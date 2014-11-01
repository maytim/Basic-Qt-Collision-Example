#include "brick.h"

Brick::Brick(int x, int y) : GameObject("C:/Qt/Projects/BreakoutGame/bluebrick.png"){
    destroyed = false;
    getRect()->translate(x, y);
}

Brick::~Brick(){}

bool Brick::isDestroyed(){
    return destroyed;
}

void Brick::setDestroyed(bool destr){
    destroyed = destr;
}
