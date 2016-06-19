#ifndef PIG_H
#define PIG_H

#include "GameItem/gameitem.h"
#define PIG_DENSITY 8.0f
#define PIG_FRICTION 0.5f
#define PIG_RESTITUTION 0.0f
class Pig: public GameItem
{
public:
    Pig(float,b2Vec2);
    virtual ~Pig();

private:
    float prize=5000.0;
};

#endif // PIG_H
