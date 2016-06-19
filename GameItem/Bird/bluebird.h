#ifndef BLUEBIRD_H
#define BLUEBIRD_H

#include "GameItem/Bird/bird.h"
#define PI 3.14159f
class BlueBird: public Bird
{
public:
    BlueBird(float,QPointF,QPixmap);
    virtual ~BlueBird();
    virtual void special();
};

#endif // BLUEBIRD_H
