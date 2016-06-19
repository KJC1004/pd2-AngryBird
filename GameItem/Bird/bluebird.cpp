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
    float angle=atan2f(v.y,v.x), spin=PI/18, dist=g_pixmap.pixmap().height();
    duplicate = new BlueBird(ratio,g_pixmap.pos()+QPointF(dist*cosf(angle+PI/2),dist*-sinf(angle+PI/2)),g_pixmap.pixmap());
    duplicate->launch(b2Vec2(v.x*cosf(spin)+v.y*-sinf(spin),v.x*+sinf(spin)+v.y*cosf(spin)));
    list->push_back(duplicate);

    duplicate = new BlueBird(ratio,g_pixmap.pos()+QPointF(dist*cosf(angle-PI/2),dist*-sinf(angle-PI/2)),g_pixmap.pixmap());
    duplicate->launch(b2Vec2(v.x*cosf(-spin)+v.y*-sinf(-spin),v.x*sinf(-spin)+v.y*cosf(-spin)));
    list->push_back(duplicate);


}
