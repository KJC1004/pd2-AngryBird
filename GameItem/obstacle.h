#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "GameItem/gameitem.h"
#define OBSTACLE_DENSITY 5.0f
#define OBSTACLE_FRICTION 0.5f
#define OBSTACLE_RESTITUTION 0.0f
class Obstacle: public GameItem
{
public:
    Obstacle(float,b2Vec2,QSizeF);
    virtual ~Obstacle();
};

#endif // OBSTACLE_H
