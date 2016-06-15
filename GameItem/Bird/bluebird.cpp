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
    list->push_back(duplicate);
    duplicate = new BlueBird(ratio,g_pixmap.pos()-QPointF(0,g_pixmap.pixmap().height()),g_pixmap.pixmap());
    duplicate->launch(b2Vec2(v.x,v.y+5));
    list->push_back(duplicate);
}
