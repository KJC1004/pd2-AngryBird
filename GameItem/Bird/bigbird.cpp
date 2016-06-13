#include "bigbird.h"

BigBird::BigBird(float size_ratio, QPointF pos, QPixmap bird): Bird(size_ratio,pos,bird)
{

}

void BigBird::special()
{
    used=true;
    b2Fixture *fixture = g_body->GetFixtureList();    
    fixture->SetFriction(1);
    fixture->SetDensity(fixture->GetDensity()*1000);
    fixture->SetRestitution(0);
    g_body->ApplyLinearImpulse(b2Vec2(0,-100*g_body->GetMass()),g_body->GetPosition(),true);
    g_body->SetGravityScale(10);
}
