#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QList>
#include <QTimer>
#include <QMouseEvent>
#include <Box2D/Box2D.h>
#include "GameItem/Angry.h"

#define WORLD_W 64
#define WORLD_H 36
#define FPS 60.0f
#define V_MAX 200

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
friend class GameListener;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showEvent(QShowEvent *);
    bool eventFilter(QObject *,QEvent *event);
    void closeEvent(QCloseEvent *);
    void initGame();
    void order();

signals:
    void quitGame();

private slots:
    void nextFrame();
    void checkStable();
    void on_powerButton_clicked();
    void on_playButton_pressed();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QList<GameItem *> itemList;
    QList<int> birds;
    QTimer *timer;
    QPoint start;
    QPointF origin;
    int dx, dy, dl, nextRound=-1;
    bool drag=false, gameEnded=false;
    b2World *world;
    Bird *birdie;
};

#endif // MAINWINDOW_H
