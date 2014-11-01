#include "paddle.h"

Paddle::Paddle() : GameObject("C:/Qt/Projects/BreakoutGame/mpaddle.png"){
    resetState();
}

Paddle::~Paddle(){}

void Paddle::moveLeft(int left){
    if(getRect()->left() > 0){
        getRect()->moveTo(left, getRect()->top());
    }
}

void Paddle::moveRight(int right){
    if(getRect()->right() < 300){
        getRect()->moveTo(right, getRect()->top());
    }
}

void Paddle::resetState(){
    getRect()->moveTo(200, 360);
}
