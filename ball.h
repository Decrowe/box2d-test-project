#ifndef BALL_H
#define BALL_H

#include "box2d/b2_circle_shape.h"
#include "box2d/b2_world.h"
#include "box2d/b2_types.h"
#include "box2d/box2d.h"
#include "IDisplayable.h"

class Ball
{
private:
    int _color;

    float _xInit;
    float _yInit;
    float _radius;

    float _density;
    float _friction;

    b2World* _world;
    b2BodyDef _bodyDef;
    b2Body* _body;
    b2CircleShape _shape;
    b2FixtureDef _fixtureDef;

    void DefineBody();
    void CreateBody();
    void DefineShape();
    void DefineFixture();
    void CreateFixture();

    void display();

public:
    Ball(b2World* world, float xInit, float yInit, float radius, int color, float density = 1.0f, float friction = 0.1f);

    b2Vec2 GetPos();
    int GetColor();

};

#endif // BALL_H
