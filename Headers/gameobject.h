#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QImage>
#include <QRect>

class GameObject
{
public:
    GameObject();
    GameObject(QString, int=1);
    virtual ~GameObject();
    QRect* getRect();
    virtual void setRect(QRect);
    QImage* getImage();
private:
    QImage* image;
    QRect* rect;
};

#endif // GAMEOBJECT_H
