#ifndef OBSTACLEFACTORY_H
#define OBSTACLEFACTORY_H

#include "box2d/box2d.h"
#include "box2d/b2_world.h"
#include "box2d/b2_types.h"
#include "box2d/b2_polygon_shape.h"

class ObstacleFactory
{
private:
    float _density = 1.0f;
    float _friction = 0.1f;

    b2World* _world;

    b2BodyDef GetBodyDef(float xInit, float yInit);
    b2Body* GetBody(b2BodyDef bodyDef);
    b2PolygonShape GetShape(float width, float height);
    b2FixtureDef GetFixtureDef(b2PolygonShape* shape);



public:
    ObstacleFactory(b2World* world);
    void AddObstacle(float xInit, float yInit, float width, float height);
};

#endif // OBSTACLEFACTORY_H
