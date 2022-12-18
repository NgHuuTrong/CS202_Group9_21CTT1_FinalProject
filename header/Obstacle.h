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
public:
    Obstacle(int inLane, Ob_type type);
    ~Obstacle();

    Ob_type type;
};
