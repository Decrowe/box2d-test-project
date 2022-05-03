#include "obstaclefactory.h"

//PUBLIC
ObstacleFactory::ObstacleFactory(b2World* world)
{
    this->_world = world;
}

void ObstacleFactory::AddObstacle(float xInit, float yInit, float width, float height){
    b2BodyDef bodyDef = GetBodyDef(xInit, yInit);
    b2Body* body = GetBody(bodyDef);
    b2PolygonShape shape = GetShape(width, height);
    b2FixtureDef fixtureDef = GetFixtureDef(&shape);

    body->CreateFixture(&fixtureDef);
}

//PRIVATE
b2BodyDef ObstacleFactory::GetBodyDef(float xInit, float yInit){
    b2BodyDef bodyDef;
    bodyDef.type = b2_staticBody;
    bodyDef.position.Set(xInit,yInit);
    return bodyDef;
}
b2Body* ObstacleFactory::GetBody(b2BodyDef bodyDef){
    b2Body* body = this->_world->CreateBody(&bodyDef);
    return body;
}
b2PolygonShape ObstacleFactory::GetShape(float width, float height){
    b2PolygonShape shape;
    shape.SetAsBox(width, height);
    return shape;
}
b2FixtureDef ObstacleFactory::GetFixtureDef(b2PolygonShape* shape){
    b2FixtureDef fixtureDef;
    fixtureDef.shape = shape;
    fixtureDef.density = this->_density;
    fixtureDef.friction = this->_friction;
    return fixtureDef;
}
