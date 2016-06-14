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
    if(gameEnded || birdie==NULL) return false;
    if(event->type()==QEvent::MouseButtonPress)
    {
        if(birdie->launched)
        {
                birdie->special();
                birdie=NULL;
        }
        else
        {
            drag = true;
            start = QCursor::pos();
            dx=0;
            dy=0;
        }
    }
    if(drag && nextRound<0 && event->type()==QEvent::MouseMove)
    {
        dx = QCursor::pos().x()-start.x();
        dy = QCursor::pos().y()-start.y();
        dl = pow(pow(dx,2)+pow(dy,2),0.5);
        dl = (dl==0? 1: dl);
        dx = dx*(dl>V_MAX? V_MAX: dl)/dl;
        dy = dy*(dl>V_MAX? V_MAX: dl)/dl;
        birdie->setBirdPos(origin,dx,dy);
    }
    if(drag && nextRound<0 && event->type()==QEvent::MouseButtonRelease)
    {
        drag = false;
        nextRound=4;
        birdie->launch(b2Vec2((float)-dx*0.25,(float)dy*0.25));
        disconnect(timer_check,SIGNAL(timeout()),this,SLOT(checkStatus()));
        connect(timer_check,SIGNAL(timeout()),this,SLOT(checkStable()));
        ui->label_Remain->setText("x "+QString::number(--GameItem::birdCount));
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
    nextRound = -1;

    world = new b2World(b2Vec2(0.0f, -20.0f));
    world->SetContactListener(new GameListener());
    scene = new QGraphicsScene(0,0,width(),height());
    scene->setBackgroundBrush(QImage(":/image/image/background.jpg").scaled(width(),height()));
    ui->graphicsView->setScene(scene);

    birds = {1,2,3,4};
    GameItem::initGameItem(QSizeF(WORLD_W,WORLD_H),size(),world,scene,timer,timer_check,birds.size());
    origin = QPointF(width()*0.15, height()*0.6);

    QGraphicsPixmapItem *catapult = new QGraphicsPixmapItem();
    catapult->setPixmap(QPixmap(":/image/image/catapult.png").scaled(height()/7,height()/2.5));
    catapult->setPos(origin.x()-catapult->pixmap().width()/2,origin.y()-50);
    scene->addItem(catapult);

    itemList.push_back(new Land(0,b2Vec2(WORLD_W*0.5,0),QSizeF(WORLD_W,WORLD_H*0.2),true));
    itemList.push_back(new Land(0,b2Vec2(WORLD_W*1.1,WORLD_H*0.5),QSizeF(WORLD_W*0.2,WORLD_H),false));
    itemList.push_back(new Pig(0.2,b2Vec2(WORLD_W*0.7,WORLD_H*0.2)));
    itemList.push_back(new Obstacle(0.05,b2Vec2(WORLD_W*0.55,WORLD_H*0.2),QSizeF(1,5)));
    itemList.push_back(new Obstacle(0.05,b2Vec2(WORLD_W*0.85,WORLD_H*0.2),QSizeF(1,5)));
    itemList.push_back(new Obstacle(0.05,b2Vec2(WORLD_W*0.7,WORLD_H*0.4),QSizeF(12,1)));
    itemList.push_back(new Pig(0.15,b2Vec2(WORLD_W*0.7,WORLD_H*0.5)));
    itemList.push_back(new Obstacle(0.05,b2Vec2(WORLD_W*0.6,WORLD_H*0.55),QSizeF(1,4)));
    itemList.push_back(new Obstacle(0.05,b2Vec2(WORLD_W*0.8,WORLD_H*0.55),QSizeF(1,4)));
    itemList.push_back(new Obstacle(0.05,b2Vec2(WORLD_W*0.7,WORLD_H*0.65),QSizeF(8,1)));
    itemList.push_back(new Pig(0.1,b2Vec2(WORLD_W*0.7,WORLD_H*0.7)));

    order();

    connect(timer,SIGNAL(timeout()),this,SLOT(nextFrame()));
    connect(timer_check,SIGNAL(timeout()),this,SLOT(checkStatus()));

    ui->label_Remain->setText("x "+QString::number(GameItem::birdCount));
    ui->label_Result->setText("");
    ui->label_Score->setText("");
}

void MainWindow::order()
{
    drag=false;
    checkStatus();
    if(gameEnded || nextRound>0 || birds.size()==0) return;
    switch(birds[0])
    {
        case 1: birdie = new RedBird(0.1,origin,QPixmap(":/image/image/red.png"));      break;
        case 2: birdie = new YellowBird(0.1,origin,QPixmap(":/image/image/yellow.png"));break;
        case 3: birdie = new BlueBird(0.07,origin,QPixmap(":/image/image/blue.png"));   break;
        case 4: birdie = new BigBird(0.15,origin,QPixmap(":/image/image/big.png"));     break;
        default: birdie = NULL; break;
    }
    birds.removeFirst();
    itemList.push_back(birdie);
}

void MainWindow::nextFrame()
{
    world->Step(1.0/FPS,6,2);
    scene->update();
    ui->label_Score->setText("SCORE  :  "+QString::number((int)GameItem::score));
}

void MainWindow::checkStable()
{
    b2Body *bodyList = world->GetBodyList();
    while(bodyList!=NULL)
    {
        if(bodyList->GetLinearVelocity().Length()>1)        {
            nextRound=4;
            return;
        }
        bodyList = bodyList->GetNext();
    }
    if(--nextRound<0)
    {
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
        ui->label_Result->setText("LOSE");
    }
    if(GameItem::pigCount==0)
    {
        gameEnded=true;
        ui->label_Result->setText("WIN");
        GameItem::score+=10000*GameItem::birdCount;
        disconnect(timer_check,SIGNAL(timeout()),this,SLOT(checkStatus()));
    }
}

void MainWindow::on_powerButton_clicked()
{
    close();
}

void MainWindow::on_playButton_pressed()
{
    gameEnded=true;
    delete timer;
    delete timer_check;
    delete world;
    delete scene;
    //itemList.clear();
    //memory leak, not fixed
    initGame();
}


