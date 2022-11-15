#include "../header/Obstacle.h"

Obstacle::Obstacle(int inLane, Ob_type type) : GameObject(inLane)
{
    this->type = type;
}

Obstacle::~Obstacle()
{
}
