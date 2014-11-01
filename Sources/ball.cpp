#include "ball.h"

//Create the Ball object and set it to the default values using resetState()
Ball::Ball() : GameObject("C:/Qt/Projects/BreakoutGame/redball.png",3){
    resetState();
}

//Function to automatically move the Ball in its current x and y direction
void Ball::autoMove(){
    //start by moving the ball in its current x and y direction
    getRect()->translate(xdir, ydir);

    //Check if the Ball has moved to the window constraints and change the x or y direction to keep it 
    //within the window's constraints
    if(getRect()->left() == 0)
        xdir = 1;
    else if(getRect()->right() == 300)
        xdir = -1;
    else if(getRect()->top() == 0)
        ydir = 1;
}

//Reset the balls position and x and y direction to the default values
void Ball::resetState(){
    getRect()->moveTo(230,300);
    xdir = 1;
    ydir = -1;
}

//xDir setter
void Ball::setXDir(int x){
    xdir = x;
}

//yDir setter
void Ball::setYDir(int y){
    ydir = y;
}

//xDir getter
int Ball::getXDir(){
    return xdir;
}

//yDir getter
int Ball::getYDir(){
    return ydir;
}
