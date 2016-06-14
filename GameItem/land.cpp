#include "land.h"

Land::Land(float size_ratio, b2Vec2 pos, QSizeF size, bool ground): GameItem(size_ratio)
{
    g_size = size;
    if(ground)
        g_pixmap.setPixmap(QPixmap(":/image/image/ground.png").scaled(g_scene->width(),g_scene->height()*g_size.height()/g_worldsize.height()));

    b2BodyDef bodyDef;
    b2PolygonShape bodyBox;
    bodyDef.userData = this;
    bodyDef.position.Set(pos.x,pos.y);
    bodyBox.SetAsBox(g_size.width()/2,g_size.height()/2);

    g_body = g_world->CreateBody(&bodyDef);
    g_body->CreateFixture(&bodyBox,9.0f);
    paint();
    g_scene->addItem(&g_pixmap);
}

Land::~Land()
{

}
