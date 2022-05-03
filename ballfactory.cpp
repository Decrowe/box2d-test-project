#include "ballfactory.h"


BallFactory::BallFactory(b2World* world, float ballRadius)
{
    this->_world = world;
    this->_ballRadius = ballRadius;
}

void BallFactory::AddNewBall(float xInit, float yInit, int color){
    Ball* tmpBall = new Ball(_world, xInit, yInit, _ballRadius, color);
    delete(tmpBall);
}
