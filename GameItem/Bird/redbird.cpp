#include "redbird.h"

RedBird::RedBird(float size_ratio, QPointF pos, QPixmap bird): Bird(size_ratio,pos,bird)
{

}

RedBird::~RedBird()
{

}

void RedBird::special()
{
    used=true;
}
