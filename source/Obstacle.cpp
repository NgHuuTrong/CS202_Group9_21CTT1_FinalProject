#include "../header/Obstacle.h"

Obstacle::Obstacle(): GameObject() {}

Obstacle::Obstacle(int inLane, Ob_type type): GameObject(inLane)
{
    this->type = type;
}

Ob_type Obstacle::getType()
{
    return this->type;
}

Obstacle::~Obstacle() {}
