#include "gameitem.h"
#include <iostream>

GameItem::GameItem(float size_ratio): ratio(size_ratio)
{
    stamina = maxStamina;
}

GameItem::~GameItem()
{
    if(g_body!=NULL)
        g_world->DestroyBody(g_body);
}

b2World *GameItem::g_world = NULL;
QGraphicsScene *GameItem::g_scene = NULL;
QTimer *GameItem::g_timer = NULL;
QTimer *GameItem::g_timer_check = NULL;
QSizeF GameItem::g_windowsize = QSizeF();
QSizeF GameItem::g_worldsize = QSizeF();
QList<GameItem *> *GameItem::list = NULL;
const float GameItem::maxStamina = 1000.0;
bool GameItem::invulnerability=true;
int GameItem::pigCount = 0;
int GameItem::birdCount = 0;
float GameItem::score = 0;
void GameItem::initGameItem(QSizeF worldsize, QSizeF windowsize, b2World *world, QGraphicsScene *scene, QTimer *timer, QTimer *timer_check,QList<GameItem*> *itemList, int count)
{
    g_worldsize = worldsize;
    g_windowsize = windowsize;
    g_world = world;
    g_scene = scene;
    g_timer = timer;
    g_timer_check = timer_check;
    list = itemList;
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

void GameItem::checkPos()
{
    b2Vec2 pos = g_body->GetPosition();
    if(pos.x<0.0f || pos.x>g_worldsize.width() || pos.y<0)
        wasted=true;
}

void GameItem::checkVelocity()
{
    if(g_body->GetLinearVelocity().Length()>1)
        deathCountDown=4;
    else if(--deathCountDown<0)
        wasted=true;
}
