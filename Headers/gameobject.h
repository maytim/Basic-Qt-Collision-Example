/*
    The GameObject class is used to store the QImage and QRect data that represents the object within the game.
    All other objects within the game will build functionality off this framework.
*/
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QImage>
#include <QRect>

class GameObject
{
public:
    //Constructors and Destructors
    GameObject();
    GameObject(QString, int=1);
    virtual ~GameObject();

    //rect and image get and set functions
    QRect* getRect();
    virtual void setRect(QRect);
    QImage* getImage();
private:
    QImage* image;
    QRect* rect;
};

#endif // GAMEOBJECT_H
