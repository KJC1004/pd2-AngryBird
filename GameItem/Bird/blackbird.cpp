#include "blackbird.h"

BlackBird::BlackBird(float size_ratio, QPointF pos, QPixmap bird): Bird(size_ratio,pos,bird)
{

}

BlackBird::~BlackBird()
{

}

void BlackBird::special()
{
    b2Body *body = g_world->GetBodyList();
    b2Vec2 dPos, birdPos=g_body->GetPosition();
    while(body!=NULL)
    {
        dPos = body->GetPosition()-birdPos;
        if(body!=g_body)
        {
            dPos *= (float)pow(dPos.Length()/700,-2);
            body->ApplyForceToCenter(dPos,true);
        }
        body = body->GetNext();
    }
    wasted = true;
}
