#pragma once
#include "../header/raylib.h"
#include "../header/TextureHolder.h"

class GameObject
{
private:
    int inLane;          // Index of lane that the object is in
    Rectangle screenRec; // Rectangle that represents the object on the screen
public:
    GameObject();
    GameObject(int laneIndex);
    GameObject(Rectangle rec);
    GameObject(int laneIndex, Rectangle rec);
    // // bool checkCollision(GameObject &other);
    
    void setInLane(int x);
    void setScreenRec(Rectangle other);

    int getInLane();
    Rectangle getScreenRec();

    void moveScreenRecX(float x);
    void moveScreenRecY(float y);

    virtual void renderLeft() = 0;
    virtual void renderRight() = 0;
    virtual void renderUp() = 0;
    virtual void renderDown() = 0;
    void setScreenRecX(float pos, int velo, short type);

    // int getInLane();
    // Rectangle getScreenRec();
    ~GameObject();
};
