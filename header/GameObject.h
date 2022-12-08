#pragma once
#include "../header/raylib.h"

class GameObject
{
public:
    int inLane;
    // int posX;
    Rectangle screenRec;
    GameObject()
    {
        
    }
    GameObject(int inLane);
    bool checkCollision(GameObject& other);

};
