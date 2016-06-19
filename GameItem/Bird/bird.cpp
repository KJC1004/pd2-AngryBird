#include "bird.h"

Bird::Bird(float size_ratio, QPointF pos,QPixmap bird): GameItem(size_ratio)
{
    g_pixmap.setPixmap(bird.scaled(g_scene->height()*ratio,g_scene->height()*ratio));
    g_pixmap.setPos(pos.x()-g_pixmap.pixmap().width()/2,pos.y()-g_pixmap.pixmap().height()/2);
    g_pixmap.setTransformOriginPoint(g_pixmap.boundingRect().width()/2,g_pixmap.boundingRect().height()/2);
    g_scene->addItem(&g_pixmap);
}

Bird::~Bird()
{

}

void Bird::setBirdPos(QPointF origin, int dx, int dy)
{
    g_pixmap.setPos(origin.x()-g_pixmap.pixmap().width()/2+dx, origin.y()-g_pixmap.pixmap().height()/2+dy);
}

void Bird::launch(b2Vec2 velocity)
{
    launched = true;

    g_size = QSizeF(g_worldsize.height()*ratio,g_worldsize.height()*ratio);
    QPointF mapped;
    mapped.setX((g_pixmap.x()+g_pixmap.pixmap().width()/2)/g_windowsize.width()*g_worldsize.width());
    mapped.setY((1.0f-(g_pixmap.y()+g_pixmap.pixmap().height()/2)/g_windowsize.height())*g_worldsize.height());

    // Create Body
    b2BodyDef bodydef;
    bodydef.type = b2_dynamicBody;
    bodydef.bullet = true;
    bodydef.position.Set(mapped.x(),mapped.y());

    bodydef.userData = this;
    g_body = g_world->CreateBody(&bodydef);

    b2CircleShape bodyshape;
    bodyshape.m_radius = g_worldsize.height()*ratio/2;

    b2FixtureDef fixturedef;
    fixturedef.shape = &bodyshape;
    fixturedef.density = BIRD_DENSITY;
    fixturedef.friction = BIRD_FRICTION;
    fixturedef.restitution = BIRD_RESTITUTION;
    g_body->CreateFixture(&fixturedef);
    g_body->SetAngularDamping(1);
    g_body->SetLinearVelocity(velocity);

    connect(g_timer, SIGNAL(timeout()), this,SLOT(paint()));
    connect(g_timer_check, SIGNAL(timeout()), this, SLOT(checkPos()));
    connect(g_timer_check, SIGNAL(timeout()), this, SLOT(checkVelocity()));
}

