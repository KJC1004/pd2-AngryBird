#include "yellowbird.h"

YellowBird::YellowBird(float size_ratio, QPointF pos, QPixmap bird): Bird(size_ratio,pos,bird)
{

}

YellowBird::~YellowBird()
{

}

void YellowBird::special()
{
    b2Vec2 v = g_body->GetLinearVelocity();
    v *= 500/pow(pow(v.x,2)+pow(v.y,2),0.5);
    g_body->SetLinearVelocity(v);
}
