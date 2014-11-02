/*
    The GameObject class is used to store the QImage and QRect data that represents the object within the game.
    All other objects within the game will build functionality off this framework.
*/
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QImage>
#include <QRect>
#include <QString>

//Constants used throughout the application
namespace CONSTANTS{
    const QString BALL_IMAGE = "C:/Qt/Projects/BreakoutGame/redball.png";
    const QString BRICK_IMAGE = "C:/Qt/Projects/BreakoutGame/bluebrick.png";
    const QString PADDLE_IMAGE = "C:/Qt/Projects/BreakoutGame/mpaddle.png";

    const int SCREEN_WIDTH = 300;
    const int SCREEN_HEIGHT = 400;

    const int DEFAULT_BALL_X = 230;
    const int DEFAULT_BALL_Y = 300;
    const int DEFAULT_PADDLE_X = 200;
    const int DEFAULT_PADDLE_Y = 360;


    const int BRICK_WIDTH_INTERVAL = 36;
    const int BRICK_HEIGHT_INTERVAL = 18;
    const int BRICK_ROWS = 5;
    const int BRICK_COLS = 6;
    const int BRICK_MARGIN = (SCREEN_WIDTH-(BRICK_COLS*BRICK_WIDTH_INTERVAL))/2;
}

class GameObject
{
public:
    //Constructors and Destructors
    GameObject();
    GameObject(QString, int=1);
    virtual ~GameObject();

    //rect and image get functions
    QRect* getRect();
    QImage* getImage();
private:
    QImage* image;
    QRect* rect;
};

#endif // GAMEOBJECT_H
