#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QList>
#include <QTimer>
#include <QMouseEvent>
#include <QKeyEvent>
#include <Box2D/Box2D.h>
#include "GameItem/Angry.h"

#include <iostream>

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

signals:
    void quitGame();

private slots:
    void nextFrame();
    void order();
    void setScore();
    void initGame();
    void on_powerButton_clicked();
    void on_playButton_pressed();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    b2World *world;
    QList<GameItem *> itemList;
    QList<int> birds;
    QTimer *timer;
    QPoint start;
    QPointF origin;
    int dx, dy, dl;
    bool drag=false, gameEnded=false;
    Bird *birdie;
};

#endif // MAINWINDOW_H
