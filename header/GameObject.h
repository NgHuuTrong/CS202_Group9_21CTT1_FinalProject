#pragma once
#include "../header/raylib.h"

class GameObject
{
private:
    int inLane;          // Index of lane that the object is in
    Rectangle screenRec; // Rectangle that represents the object on the screen
public:
    GameObject();
    GameObject(int inLane);
    bool checkCollision(GameObject &other);
    
    void setInLane(int x);
    void setScreenRec(Rectangle other);
    void moveScreenRecX(float x);
    void moveScreenRecY(float y);

    int getInLane();
    Rectangle getScreenRec();
};
