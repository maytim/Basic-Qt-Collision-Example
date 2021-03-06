/*
    The Brick class builds off the GameObject framework by adding destroyed functionality.
*/
#ifndef BRICK_H
#define BRICK_H

#include "gameobject.h"

class Brick : public GameObject{
public:
    //Constructors
    Brick(int, int);
    //Reset to defaults
    void resetState();
    //A function to check if the brick is destroyed
    bool isDestroyed();
    //A function to set the destroyed bool
    void setDestroyed(bool);
private:
    bool destroyed;
};

#endif // BRICK_H
