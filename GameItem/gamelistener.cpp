#include "gamelistener.h"

GameListener::GameListener()
{

}

GameListener::~GameListener()
{

}

void GameListener::PostSolve(b2Contact *contact, const b2ContactImpulse *impulse)
{
    if(GameItem::invulnerability) return;
    GameItem *gameitemA = (GameItem*)contact->GetFixtureA()->GetBody()->GetUserData();
    GameItem *gameitemB = (GameItem*)contact->GetFixtureB()->GetBody()->GetUserData();
    if(!gameitemA->vulnerable && !gameitemB->vulnerable) return;

    float damage=0;
    for(int i=0; i<impulse->count; i++)
        if(damage<impulse->normalImpulses[i])
            damage = impulse->normalImpulses[i];

    if(damage>GameItem::maxStamina*0.08)
    {
        if(gameitemA->vulnerable)
        {
            GameItem::score+=damage/20;
            gameitemA->stamina-=damage;
            if(gameitemA->stamina<=0)
                gameitemA->wasted=true;
            gameitemA->g_pixmap.setOpacity(gameitemA->stamina/GameItem::maxStamina*0.7+0.3);
        }
        if(gameitemB->vulnerable)
        {
            GameItem::score+=damage/20;
            gameitemB->stamina-=damage;
            if(gameitemB->stamina<=0)
                gameitemB->wasted=true;
            gameitemB->g_pixmap.setOpacity(gameitemB->stamina/GameItem::maxStamina*0.7+0.3);
        }
    }
}
