#ifndef BLUEBIRD_H
#define BLUEBIRD_H

#include "GameItem/Bird/bird.h"

class BlueBird: public Bird
{
public:
    BlueBird(float,QPointF,QPixmap);
    virtual void special();
};

#endif // BLUEBIRD_H
