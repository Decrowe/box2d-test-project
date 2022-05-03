#ifndef BALLFACTORY_H
#define BALLFACTORY_H

#include "box2d/b2_world.h"
#include "ball.h"

enum BallColors {
    RED = 0,
    GREEN,
    BLUE,
    YELLOW,
    PURPLE,
    BLACK,
    WHITE,
    ORANGE,
};

class BallFactory
{
private:
    float _ballRadius;
    b2World* _world;


public:
    BallFactory(b2World* world, float ballRadius);
    void AddNewBall(float xInit, float yInit, int color);
};

#endif // BALLFACTORY_H
