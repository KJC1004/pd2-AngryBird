#-------------------------------------------------
#
# Project created by QtCreator 2016-04-20T02:17:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

TARGET = AngryThing
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    GameItem/gameitem.cpp \
    GameItem/land.cpp \
    GameItem/Bird/bird.cpp \
    GameItem/Bird/redbird.cpp \
    GameItem/Bird/bluebird.cpp \
    GameItem/Bird/yellowbird.cpp \
    GameItem/obstacle.cpp \
    GameItem/pig.cpp \
    GameItem/Bird/bigbird.cpp \
    GameItem/gamelistener.cpp

HEADERS  += mainwindow.h \
    Box2D/Collision/Shapes/b2ChainShape.h \
    Box2D/Collision/Shapes/b2CircleShape.h \
    Box2D/Collision/Shapes/b2EdgeShape.h \
    Box2D/Collision/Shapes/b2PolygonShape.h \
    Box2D/Collision/Shapes/b2Shape.h \
    Box2D/Collision/b2BroadPhase.h \
    Box2D/Collision/b2Collision.h \
    Box2D/Collision/b2Distance.h \
    Box2D/Collision/b2DynamicTree.h \
    Box2D/Collision/b2TimeOfImpact.h \
    Box2D/Common/b2BlockAllocator.h \
    Box2D/Common/b2Draw.h \
    Box2D/Common/b2GrowableStack.h \
    Box2D/Common/b2Math.h \
    Box2D/Common/b2Settings.h \
    Box2D/Common/b2StackAllocator.h \
    Box2D/Common/b2Timer.h \
    Box2D/Dynamics/Contacts/b2ChainAndCircleContact.h \
    Box2D/Dynamics/Contacts/b2ChainAndPolygonContact.h \
    Box2D/Dynamics/Contacts/b2CircleContact.h \
    Box2D/Dynamics/Contacts/b2Contact.h \
    Box2D/Dynamics/Contacts/b2ContactSolver.h \
    Box2D/Dynamics/Contacts/b2EdgeAndCircleContact.h \
    Box2D/Dynamics/Contacts/b2EdgeAndPolygonContact.h \
    Box2D/Dynamics/Contacts/b2PolygonAndCircleContact.h \
    Box2D/Dynamics/Contacts/b2PolygonContact.h \
    Box2D/Dynamics/Joints/b2DistanceJoint.h \
    Box2D/Dynamics/Joints/b2FrictionJoint.h \
    Box2D/Dynamics/Joints/b2GearJoint.h \
    Box2D/Dynamics/Joints/b2Joint.h \
    Box2D/Dynamics/Joints/b2MotorJoint.h \
    Box2D/Dynamics/Joints/b2MouseJoint.h \
    Box2D/Dynamics/Joints/b2PrismaticJoint.h \
    Box2D/Dynamics/Joints/b2PulleyJoint.h \
    Box2D/Dynamics/Joints/b2RevoluteJoint.h \
    Box2D/Dynamics/Joints/b2RopeJoint.h \
    Box2D/Dynamics/Joints/b2WeldJoint.h \
    Box2D/Dynamics/Joints/b2WheelJoint.h \
    Box2D/Dynamics/b2Body.h \
    Box2D/Dynamics/b2ContactManager.h \
    Box2D/Dynamics/b2Fixture.h \
    Box2D/Dynamics/b2Island.h \
    Box2D/Dynamics/b2TimeStep.h \
    Box2D/Dynamics/b2World.h \
    Box2D/Dynamics/b2WorldCallbacks.h \
    Box2D/Rope/b2Rope.h \
    Box2D/Box2D.h \
    GameItem/gameitem.h \
    GameItem/land.h \
    GameItem/Bird/bird.h \
    GameItem/Bird/redbird.h \
    GameItem/Bird/bluebird.h \
    GameItem/Bird/yellowbird.h \
    GameItem/Angry.h \
    GameItem/obstacle.h \
    GameItem/pig.h \
    GameItem/Bird/bigbird.h \
    GameItem/gamelistener.h

FORMS    += mainwindow.ui

LIBS += -L. -lBox2D

RESOURCES += \
    res.qrc \
