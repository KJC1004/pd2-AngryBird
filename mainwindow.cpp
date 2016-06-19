#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qApp->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showEvent(QShowEvent *)
{
    initGame();
}

bool MainWindow::eventFilter(QObject *, QEvent *event)
{
    QMouseEvent* mouseEvent = (QMouseEvent*)event;
    if(gameEnded || birdie==NULL || GameItem::invulnerability || QRectF(0,0,150,300).contains(mouseEvent->pos())) return false;
    if(!drag && event->type()==QEvent::MouseButtonPress)
    {
        if(birdie->launched)
        {
                birdie->special();
                birdie=NULL;
        }
        else if(dragBox.contains(mouseEvent->pos()) && nextRound<0)
        {
            drag = true;            
            start = mouseEvent->pos();
            dx=0;//
            dy=0;
        }
        return true;
    }
    if(!drag || birdie->launched ||nextRound>=0) return false;
    if(event->type()==QEvent::MouseMove)
    {
        dx = mouseEvent->pos().x()-start.x();
        dy = mouseEvent->pos().y()-start.y();
        dl = pow(pow(dx,2)+pow(dy,2),0.5);
        dl = (dl<1? 1: dl);
        dx = dx*(dl>V_MAX? V_MAX: dl)/dl;
        dy = dy*(dl>V_MAX? V_MAX: dl)/dl;
        birdie->setBirdPos(origin,dx,dy);
        return true;
    }
    if(event->type()==QEvent::MouseButtonRelease)
    {
        drag = false;
        nextRound=4;
        birdie->launch(b2Vec2((float)-dx*0.4,(float)dy*0.4));
        disconnect(timer_check,SIGNAL(timeout()),this,SLOT(checkStatus()));
        connect(timer_check,SIGNAL(timeout()),this,SLOT(checkStable()));
        ui->label_Remain->setText("x "+QString::number(--GameItem::birdCount));
        return true;
    }    
    return false;
}



void MainWindow::closeEvent(QCloseEvent *)
{
    emit quitGame();
}

void MainWindow::initGame()
{
    timer = new QTimer();
    timer->start(1000/FPS);
    timer_check = new QTimer();
    timer_check->start(500);

    drag = false;
    gameEnded = false;
    nextRound = 1;

    world = new b2World(b2Vec2(0.0f, -WORLD_H/2));
    world->SetContactListener(new GameListener());
    scene = new QGraphicsScene(0,0,width(),height());
    scene->setBackgroundBrush(QImage(":/image/image/background.jpg").scaled(width(),height()));
    ui->graphicsView->setScene(scene);

    birds={0,1,2,3,4};
    GameItem::initGameItem(QSizeF(WORLD_W,WORLD_H),size(),world,scene,timer,timer_check,&itemList,birds.size());
    origin = QPointF(width()*0.1, height()*0.75);

    QGraphicsPixmapItem *catapult = new QGraphicsPixmapItem();
    catapult->setPixmap(QPixmap(":/image/image/catapult.png").scaled(height()*0.1,height()*0.2));
    catapult->setPos(origin.x()-catapult->pixmap().width()/2,origin.y()-25);
    scene->addItem(catapult);

    itemList.push_back(new Land(b2Vec2(WORLD_W*0.5,WORLD_H*0.05),QSizeF(WORLD_W,WORLD_H*0.1),true));
    itemList.push_back(new Land(b2Vec2(WORLD_W*1.05,WORLD_H*0.5),QSizeF(WORLD_W*0.1,WORLD_H),false));

    for(float i=0.5; i<=0.91; i+=0.1)
    {
        for(float j=0.2; j<=0.81; j+=0.15)
        {
            itemList.push_back(new Pig(0.07,b2Vec2(WORLD_W*i,WORLD_H*j)));
            itemList.push_back(new Obstacle(b2Vec2(WORLD_W*i,WORLD_H*(j+0.07)),QSizeF(17, 2)));
            itemList.push_back(new Obstacle(b2Vec2(WORLD_W*(i-0.04),WORLD_H*j),QSizeF(2.5,11)));
            itemList.push_back(new Obstacle(b2Vec2(WORLD_W*(i+0.04),WORLD_H*j),QSizeF(2.5,11)));
        }
    }

    connect(timer,SIGNAL(timeout()),this,SLOT(nextFrame()));
    connect(timer,SIGNAL(timeout()),this,SLOT(clearWasted()));
    connect(timer_check,SIGNAL(timeout()),this,SLOT(checkStable()));

    ui->label_Remain->setText("x "+QString::number(GameItem::birdCount));
    ui->label_Result->clear();
}

void MainWindow::endGame()
{
    gameEnded=true;
    delete timer;
    delete timer_check;
    for(int i=0; i<itemList.size(); ++i)
        delete itemList[i];
    itemList.clear();
    birds.clear();
    delete world;
    delete scene;
}

void MainWindow::order()
{
    drag=false;
    checkStatus();
    if(gameEnded || nextRound>0 || birds.size()==0) return;
    switch(birds[0])
    {
        case 0: birdie = new RedBird(0.07,origin,QPixmap(":/image/image/red.png"));      break;
        case 1: birdie = new YellowBird(0.07,origin,QPixmap(":/image/image/yellow.png"));break;
        case 2: birdie = new BlueBird(0.05,origin,QPixmap(":/image/image/blue.png"));   break;
        case 3: birdie = new BigBird(0.1,origin,QPixmap(":/image/image/big.png"));     break;
        case 4: birdie = new BlackBird(0.07,origin,QPixmap(":image/image/black.png")); break;
        default: birdie = NULL; break;
    }
    birds.removeFirst();
    itemList.push_back(birdie);
    QPointF temp = QPointF(birdie->g_pixmap.pixmap().width()/2,birdie->g_pixmap.pixmap().height()/2);
    dragBox = QRectF(origin-temp,origin+temp);
}

void MainWindow::nextFrame()
{
    world->Step(1.0/FPS,6,2);
    scene->update();
    ui->label_Score->setText("SCORE  :  "+QString::number((int)GameItem::score));
}

void MainWindow::clearWasted()
{
    for(int i=0; i<itemList.size(); ++i)
    {
        if(itemList[i]->wasted)
        {
            delete itemList[i];
            itemList.erase(itemList.begin()+i);
            --i;
        }
    }
}

void MainWindow::checkStable()
{
    b2Body *bodyList = world->GetBodyList();
    while(bodyList!=NULL)
    {
        if(bodyList->GetLinearVelocity().Length()>1)
        {
            nextRound=4;
            return;
        }
        bodyList = bodyList->GetNext();
    }
    if(--nextRound<0)
    {
        GameItem::invulnerability=false;
        disconnect(timer_check,SIGNAL(timeout()),this,SLOT(checkStable()));
        connect(timer_check,SIGNAL(timeout()),this,SLOT(checkStatus()));
        order();
    }
}

void MainWindow::checkStatus()
{
    if(GameItem::birdCount==0)
    {
        gameEnded=true;
        ui->label_Result->setText("FAIL");
    }
    if(GameItem::pigCount==0)
    {
        gameEnded=true;
        ui->label_Result->setText("PASS");
        GameItem::score+=10000*GameItem::birdCount;
        disconnect(timer_check,SIGNAL(timeout()),this,SLOT(checkStatus()));
    }
}

void MainWindow::on_replayButton_clicked()
{
    endGame();
    initGame();
}

void MainWindow::on_exitButtom_clicked()
{
    endGame();
    close();
}
