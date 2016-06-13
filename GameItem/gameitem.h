#ifndef GAMEITEM_H
#define GAMEITEM_H

#include <Box2D/Box2D.h>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>
#include <QPainter>
#include <QTransform>
#include <QtMath>
#include "GameItem/gamelistener.h"
#include <iostream>

class GameItem : public QObject
{
    Q_OBJECT
friend class GameListener;
friend class MainWindow;

public:
    GameItem(float);
    ~GameItem();
    static void initGameItem(QSizeF,QSizeF,b2World *,QGraphicsScene *,QTimer *,int);

signals:
    void dead();

public slots:
    void paint();
    void die();
    void checkPos();
    void checkVelocity();
    // TODO virtual void collide();

protected:
    b2Body *g_body;
    QGraphicsPixmapItem g_pixmap;
    QSizeF g_size;
    bool vulnerable=false;
    int death=120;
    float stamina, ratio;

    const static float maxStamina;
    static bool invulnerability;
    static int pigCount, birdCount;
    static float score;
    static b2World *g_world;
    static QGraphicsScene *g_scene;
    static QTimer *g_timer;
    static QSizeF g_worldsize, g_windowsize;
};

#endif // GAMEITEM_H
