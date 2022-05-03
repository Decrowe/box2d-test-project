#include <QCoreApplication>
#include <iostream>
#include "Includes.h"


using namespace std;

int main(int argc, char *argv[])
{
    b2Vec2 gravity(0.0f, -10.0f);
    b2World world(gravity);

    QCoreApplication a(argc, argv);

    float timeStep = 1.0f / 60.0f;
    int32 velocityIterations = 6;
    int32 positionIterations = 2;

    BallFactory ballFactory = BallFactory(&world, 1.0f);
    ballFactory.AddNewBall(0.0f,4.0f,BallColors::RED);

    b2Body* balls = world.GetBodyList();


    //Obstacles like Walls etc are generated here
    ObstacleFactory obstacleFactory = ObstacleFactory(&world);
    obstacleFactory.AddObstacle(0.0f, -10.0f, 50.0f, 10.0f);


    for (int32 i = 0; i < 60; ++i)
    {
        world.Step(timeStep, velocityIterations, positionIterations);

        b2Vec2 ballPos = balls[0].GetPosition();
        printf("Ball: %4.2f %4.2f \n", ballPos.x, ballPos.y);
    }

    return a.exec();
}
