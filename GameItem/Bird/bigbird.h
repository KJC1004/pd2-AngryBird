#ifndef BIGBIRD_H
#define BIGBIRD_H
#include <QObject>
#include "GameItem/Bird/bird.h"
class BigBird: public Bird
{    
public:
    BigBird(float,QPointF,QPixmap);
    virtual void special();
};

#endif // BIGBIRD_H
