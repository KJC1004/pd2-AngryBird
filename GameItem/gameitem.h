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

class GameItem : public QObject
{
    Q_OBJECT
friend class GameListener;
friend class MainWindow;

public:
    GameItem(float);
    ~GameItem();
    static void initGameItem(QSizeF,QSizeF,b2World*,QGraphicsScene*,QTimer*,QTimer*,QList<GameItem*>*,int);

public slots:
    void paint();
    void checkPos();
    void checkVelocity();

protected:
    b2Body *g_body=NULL;
    QGraphicsPixmapItem g_pixmap;
    QSizeF g_size;
    bool vulnerable=false, wasted=false;
    int deathCountDown=4;
    float stamina, ratio;

    const static float maxStamina;
    static bool invulnerability;
    static int pigCount, birdCount;
    static float score;
    static b2World *g_world;
    static QGraphicsScene *g_scene;
    static QTimer *g_timer, *g_timer_check;
    static QSizeF g_worldsize, g_windowsize;
    static QList<GameItem *> *list;
};

#endif // GAMEITEM_H
