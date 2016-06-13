#include "land.h"

Land::Land(float size_ratio, bool WH): GameItem(size_ratio)
{

    if(WH==true) g_pixmap.setPixmap(QPixmap(":/image/image/ground.png").scaled(g_scene->width(),g_scene->height()*ratio));
    g_size = QSizeF(g_worldsize.width(),g_worldsize.height()*ratio);

    b2BodyDef bodyDef;
    bodyDef.userData = this;
    if(WH==true) bodyDef.position.Set(g_worldsize.width()/2,g_worldsize.height()*ratio/2);
    else         bodyDef.position.Set(g_worldsize.width()*(1+ratio),g_worldsize.height()/2);
    g_body = g_world->CreateBody(&bodyDef);
    b2PolygonShape bodyBox;
    if(WH==true) bodyBox.SetAsBox(g_worldsize.width(),g_worldsize.height()*ratio/2);
    else         bodyBox.SetAsBox(g_worldsize.width()*ratio,g_worldsize.height());
    g_body->CreateFixture(&bodyBox,9.0f);

    g_scene->addItem(&g_pixmap);
    paint();
}
