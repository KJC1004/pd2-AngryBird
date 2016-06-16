#ifndef LAND_H
#define LAND_H

#include "GameItem/gameitem.h"

class Land : public GameItem
{
public:
    Land(b2Vec2,QSizeF,bool);
    virtual ~Land();
};

#endif // LAND_H
