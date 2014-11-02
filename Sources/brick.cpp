#include "brick.h"

//The Brick constructor accepts x and y coordinates to position the Brick
Brick::Brick(int x, int y) : GameObject(CONSTANTS::BRICK_IMAGE){
    destroyed = false;
    //After creating the Brick move it to its correct position
    getRect()->translate(x, y);
}

//Function to check if the Brick has been destroyed
bool Brick::isDestroyed(){
    return destroyed;
}

//Function to change the Bricks status as being destroyed or not
void Brick::setDestroyed(bool destr){
    destroyed = destr;
}
