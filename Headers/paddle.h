/*
    The Paddle class is another GameObject in the game. This is the object that the player will control to deflect the 
    Ball object. It has the ability to move left or right based on player input.
*/
#ifndef PADDLE_H
#define PADDLE_H

#include "gameobject.h"

class Paddle : public GameObject{
public:
    //Constructor
    Paddle();
    
    //Reset to defaults
    void resetState();
    
    //Functions to update the position of the Paddle
    void moveLeft(int);
    void moveRight(int);
};

#endif // PADDLE_H
