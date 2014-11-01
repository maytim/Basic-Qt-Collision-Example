#ifndef PADDLE_H
#define PADDLE_H

#include "gameobject.h"

class Paddle : public GameObject{
public:
    Paddle();
    ~Paddle();

    void resetState();
    void moveLeft(int);
    void moveRight(int);
};

#endif // PADDLE_H
