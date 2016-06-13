#include "gameitem.h"
#include <iostream>

GameItem::GameItem(float size_ratio): ratio(size_ratio)
{
    stamina = maxStamina;
}

GameItem::~GameItem()
{
    g_world->DestroyBody(g_body);
}

b2World *GameItem::g_world = NULL;
QGraphicsScene *GameItem::g_scene = NULL;
QTimer *GameItem::g_timer = NULL;
QSizeF GameItem::g_windowsize = QSizeF();
QSizeF GameItem::g_worldsize = QSizeF();
const float GameItem::maxStamina = 5000.0;
bool GameItem::invulnerability=true;
int GameItem::pigCount = 0;
int GameItem::birdCount = 0;
float GameItem::score = 0;
void GameItem::initGameItem(QSizeF worldsize, QSizeF windowsize, b2World *world, QGraphicsScene *scene, QTimer *timer, int count)
{
    g_worldsize = worldsize;
    g_windowsize = windowsize;
    g_world = world;
    g_scene = scene;
    g_timer = timer;
    pigCount=0;
    birdCount=count;
    score=0;
    invulnerability=true;
}

void GameItem::paint()
{
    b2Vec2 pos = g_body->GetPosition();
    QPointF mappedPoint;
    mappedPoint.setX(((pos.x-g_size.width()/2)*g_windowsize.width())/g_worldsize.width());
    mappedPoint.setY((1.0f -(pos.y+g_size.height()/2)/g_worldsize.height())*g_windowsize.height());
    g_pixmap.setPos(mappedPoint);
    g_pixmap.resetTransform();
    g_pixmap.setRotation(-(g_body->GetAngle()*180/3.14159));
}

void GameItem::die()
{
    emit dead();
    delete this;
}

void GameItem::checkPos()
{
    b2Vec2 pos = g_body->GetPosition();
    if(pos.x<0.0f || pos.x>g_worldsize.width() || pos.y<0)
        die();
}

void GameItem::checkVelocity()
{
    if(g_body->GetLinearVelocity().Length()<1.5)
    {
        if(--death<0) die();
    }
    else
        death = 120;
}
