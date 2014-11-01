#ifndef BRICK_H
#define BRICK_H

#include "gameobject.h"

class Brick : public GameObject{
public:
    Brick(int, int);
    ~Brick();

    void resetState();
    bool isDestroyed();
    void setDestroyed(bool);
private:
    int position;
    bool destroyed;
};

#endif // BRICK_H
