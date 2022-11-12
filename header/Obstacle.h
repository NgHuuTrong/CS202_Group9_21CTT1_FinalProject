#pragma once
#include "GameObject.h"
#include <string>

enum Ob_type { Vehicle, Animal };

class Obstacle: public GameObject
{
public:
    Ob_type type;
    float velocity;
    Obstacle(Rectangle srcRec, Rectangle screenRec, float velocity, Ob_type type);
    ~Obstacle();
};
