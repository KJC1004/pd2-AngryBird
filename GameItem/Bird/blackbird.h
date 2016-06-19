#ifndef BLACKBIRD_H
#define BLACKBIRD_H

#include "GameItem/Bird/bird.h"
class BlackBird: public Bird
{
public:
    BlackBird(float,QPointF,QPixmap);
    virtual ~BlackBird();
    virtual void special();
};

#endif // BLACKBIRD_H
