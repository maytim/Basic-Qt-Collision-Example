#include "paddle.h"

//Create the Paddle and reset its position
Paddle::Paddle() : GameObject("C:/Qt/Projects/BreakoutGame/mpaddle.png"){
    resetState();
}

//Function to move the Paddle left
void Paddle::moveLeft(int left){
    //Prevent the Paddle from moving outside of the window
    if(getRect()->left() > 0){
        getRect()->moveTo(left, getRect()->top());
    }
}

//Function to move the Paddle right
void Paddle::moveRight(int right){
    //Prevetn the Paddle from moving outside of the window
    if(getRect()->right() < 300){
        getRect()->moveTo(right, getRect()->top());
    }
}

//Function to reset the Paddle to its default position
void Paddle::resetState(){
    getRect()->moveTo(200, 360);
}
