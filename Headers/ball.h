/*
    This is the class for the ball object. It expands upon the GameObject framework by adding the ability to move the ball
    in four directions.
*/
#ifndef BALL_H
#define BALL_H

#include "gameobject.h"

class Ball : public GameObject{
public:
    Ball();
    
    //Reset the ball to its defaults
    void resetState();
    
    //Function that will automatically move the ball relative to the limitations of the game window
    void autoMove();

    //Set and get functions for xdir and ydir
    void setXDir(int);
    void setYDir(int);
    int getXDir();
    int getYDir();
private:
    int xdir;
    int ydir;
};

#endif // BALL_H
