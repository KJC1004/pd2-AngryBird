#ifndef LAND_H
#define LAND_H

#include "GameItem/gameitem.h"

class Land : public GameItem
{
public:
    Land(float,bool);
    virtual ~Land();
};

#endif // LAND_H
