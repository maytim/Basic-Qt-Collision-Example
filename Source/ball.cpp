#include "ball.h"

Ball::Ball() : GameObject("C:/Qt/Projects/BreakoutGame/redball.png",3){
    xdir = 1;
    ydir = -1;
    resetState();
}

Ball::~Ball(){}

void Ball::autoMove(){
    getRect()->translate(xdir, ydir);

    if(getRect()->left() == 0)
        xdir = 1;
    else if(getRect()->right() == 300)
        xdir = -1;
    else if(getRect()->top() == 0)
        ydir = 1;
}

void Ball::resetState(){
    getRect()->moveTo(230,300);
    ydir = -1;
}

void Ball::moveBottom(int bottom){
    getRect()->moveBottom(bottom);
}

void Ball::moveTop(int top){
    getRect()->moveTop(top);
}

void Ball::moveLeft(int left){
    getRect()->moveLeft(left);
}

void Ball::moveRight(int right){
    getRect()->moveRight(right);
}

void Ball::setXDir(int x){
    xdir = x;
}

void Ball::setYDir(int y){
    ydir = y;
}

int Ball::getXDir(){
    return xdir;
}

int Ball::getYDir(){
    return ydir;
}
