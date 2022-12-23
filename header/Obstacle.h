#pragma once
#include "GameObject.h"
#include <string>

enum Ob_type
{
    REDCAR,
    BLUECAR,
    AMBULANCE
};

class Obstacle : public GameObject
{
private:
    Ob_type type;
public:
    Obstacle();
    Obstacle(int laneIndex, Ob_type type);

    Ob_type getType();
    void renderLeft();
    void renderRight();
    ~Obstacle();
};
