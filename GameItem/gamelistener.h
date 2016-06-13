#ifndef GAMELISTENER_H
#define GAMELISTENER_H

#include<Box2D/Box2D.h>
#include"GameItem/gameitem.h"
class GameListener: public b2ContactListener
{
public:
    GameListener();
    ~GameListener();
    void PostSolve(b2Contact *contact, const b2ContactImpulse *impulse);
};

#endif // GAMELISTENER_H
