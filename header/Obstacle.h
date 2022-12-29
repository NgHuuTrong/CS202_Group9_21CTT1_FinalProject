#pragma once
#include "GameObject.h"
#include <string>
#include <vector>

enum Ob_type
{
    YCAR,    // Yellow Car
    PCAR,    // Purple Car
    BUS,     // Bus
    POLICE   // Police Car
};

class Obstacle : public GameObject
{
private:
    std::vector<Texture2D *> txt;  // Vector of Texture2D (frames) 

    Ob_type type;                  // Store type

    int numsFrame, curFrame;       // Store frames to draw

public:
    //Constructor
    Obstacle();
    Obstacle(int laneIndex, Ob_type type);

    ~Obstacle();                               // Destructor

    Ob_type getType();                         // Type getter

    // Drawing obstacle
    void renderLeft(float y, float velocity);  // Left  ->  right
    void renderRight(float y, float velocity); // Right ->  left
};
