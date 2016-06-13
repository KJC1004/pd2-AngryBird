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
    b2Body *bodyA = contact->GetFixtureA()->GetBody();
    b2Body *bodyB = contact->GetFixtureB()->GetBody();
    GameItem *gameitemA = (GameItem*)bodyA->GetUserData();
    GameItem *gameitemB = (GameItem*)bodyB->GetUserData();
    if(!gameitemA->vulnerable && !gameitemB->vulnerable) return;
    float damage=0;

    for(int i=0; i<impulse->count; i++)
        damage += impulse->normalImpulses[i];

    if(damage>GameItem::maxStamina*0.1)
    {
        if(gameitemA->vulnerable)
        {
            GameItem::score+=damage/10;
            gameitemA->stamina-=damage;
            if(gameitemA->stamina<=0)
                gameitemA->connect(gameitemA->g_timer,SIGNAL(timeout()),gameitemA,SLOT(die()));
            gameitemA->g_pixmap.setOpacity(gameitemA->stamina/GameItem::maxStamina*0.7+0.3);
        }
        if(gameitemB->vulnerable)
        {
            GameItem::score+=damage/10;
            gameitemB->stamina-=damage;
            if(gameitemB->stamina<=0)
                gameitemB->connect(gameitemB->g_timer,SIGNAL(timeout()),gameitemB,SLOT(die()));
            gameitemB->g_pixmap.setOpacity(gameitemB->stamina/GameItem::maxStamina*0.7+0.3);
        }
    }
}
