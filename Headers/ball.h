#ifndef BALL_H
#define BALL_H

#include "gameobject.h"

class Ball : public GameObject{
public:
    Ball();
    ~Ball();
    void resetState();

    void moveBottom(int);
    void moveTop(int);
    void moveLeft(int);
    void moveRight(int);
    void autoMove();

    void setXDir(int);
    void setYDir(int);
    int getXDir();
    int getYDir();
private:
    int angle;
    int speed;
    int xdir;
    int ydir;
    bool stuck;
};

#endif // BALL_H
