#include "ball.h"

Ball::Ball(b2World* world, float xInit, float yInit, float radius, int color, float density, float friction)
{
    this->_world = world;
    this->_xInit = xInit;
    this->_yInit = yInit;
    this->_radius = radius;
    this->_color = color;
    this->_density = density;
    this->_friction = friction;

    DefineBody();
    CreateBody();
    DefineShape();
    DefineFixture();
    CreateFixture();
}

//PRIVATE
void Ball::DefineBody(){
    _bodyDef.type = b2_dynamicBody;
    _bodyDef.position.Set(_xInit,_yInit);
}

void Ball::CreateBody(){
    //_body = (b2Body*) malloc(sizeof(b2Body));
    //if(_body == NULL) exit(1);
    _body = _world->CreateBody(&_bodyDef);
}
void Ball::DefineShape(){
    _shape.m_radius = this->_radius;
}
void Ball::DefineFixture(){
    _fixtureDef.shape = &_shape;
    _fixtureDef.density = 1.0f;
    _fixtureDef.friction = 0.1f;
}
void Ball::CreateFixture(){
    _body->CreateFixture(&_fixtureDef);
}

void Ball::display(){

}

//PUBLIC

b2Vec2 Ball::GetPos(){
    return _body->GetPosition();
}

int Ball::GetColor(){
    return _color;
}
