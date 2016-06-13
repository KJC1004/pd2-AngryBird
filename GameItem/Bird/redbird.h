#ifndef REDBIRD_H
#define REDBIRD_H

#include "GameItem/Bird/bird.h"

class RedBird: public Bird
{
public:
    RedBird(float,QPointF,QPixmap);
    virtual ~RedBird();
    virtual void special();
};

#endif // REDBIRD_H
