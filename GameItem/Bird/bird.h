#ifndef BIRD_H
#define BIRD_H

#include "GameItem/gameitem.h"
#define BIRD_DENSITY 5.0f
#define BIRD_FRICTION 0.3f
#define BIRD_RESTITUTION 0.3f
class Bird : public GameItem
{
public:
    Bird(float,QPointF,QPixmap);
    virtual ~Bird();
    void setBirdPos(QPointF,int,int);
    void launch(b2Vec2);
    virtual void special()=0;
    bool launched=false;
};

#endif // BIRD_H
