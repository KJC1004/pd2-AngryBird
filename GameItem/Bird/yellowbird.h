#ifndef YELLOWBIRD_H
#define YELLOWBIRD_H

#include "GameItem/Bird/bird.h"

class YellowBird: public Bird
{
public:
    YellowBird(float,QPointF,QPixmap);
    virtual ~YellowBird();
    virtual void special();
};

#endif // YELLOWBIRD_H
