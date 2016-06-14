#include "bluebird.h"

BlueBird::BlueBird(float size_ratio, QPointF pos, QPixmap bird): Bird(size_ratio,pos,bird)
{

}

BlueBird::~BlueBird()
{

}

void BlueBird::special()
{
    Bird *duplicate;
    b2Vec2 v = g_body->GetLinearVelocity();
    duplicate = new BlueBird(ratio,g_pixmap.pos()+QPointF(0,g_pixmap.pixmap().height()),g_pixmap.pixmap());
    duplicate->launch(b2Vec2(v.x,v.y-5));
    duplicate->connect(g_timer,SIGNAL(timeout()),duplicate,SLOT(checkPos()));
    duplicate->connect(g_timer,SIGNAL(timeout()),duplicate,SLOT(checkVelocity()));

    duplicate = new BlueBird(ratio,g_pixmap.pos()-QPointF(0,g_pixmap.pixmap().height()),g_pixmap.pixmap());
    duplicate->launch(b2Vec2(v.x,v.y+5));
    duplicate->connect(g_timer,SIGNAL(timeout()),duplicate,SLOT(checkPos()));
    duplicate->connect(g_timer,SIGNAL(timeout()),duplicate,SLOT(checkVelocity()));
}
