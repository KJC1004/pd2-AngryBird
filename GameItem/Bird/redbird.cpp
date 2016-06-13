#include "redbird.h"

RedBird::RedBird(float size_ratio, QPointF pos, QPixmap bird): Bird(size_ratio,pos,bird)
{

}

void RedBird::special()
{
    used=true;
}
