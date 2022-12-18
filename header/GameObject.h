#pragma once
#include "../header/raylib.h"

class GameObject
{
public:
    int inLane;          // Index of lane that the object is in
    Rectangle screenRec; // Rectangle that represents the object on the screen
    GameObject();
    GameObject(int inLane);
    bool checkCollision(GameObject &other);
};
