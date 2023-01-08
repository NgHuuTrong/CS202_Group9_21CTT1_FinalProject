#pragma once
#include "../header/raylib.h"
#include "../header/TextureHolder.h"

class GameObject
{
protected:
    int inLane;              // Index of lane that the object is in

    Rectangle screenRec;     // Rectangle that represents the object on the screen

public:
    // Constructor
    GameObject();
    GameObject(int laneIndex);
    GameObject(Rectangle rec);
    GameObject(int laneIndex, Rectangle rec);

    GameObject& operator=(const GameObject& src);
    ~GameObject();                          // Destructor

    // In lane
    int getInLane();                        // Getter
    void setInLane(int x);                  // Setter

    // Screen Rectangle
    Rectangle getScreenRec();               // Getter
    void setScreenRec(Rectangle other);     // Setter

    // Move object
    void moveScreenRecX(float x);           // by X
    void moveScreenRecY(float y);           // by Y

    void setScreenRecX(float pos, int velo, short type);    // Move object has velocity

};
