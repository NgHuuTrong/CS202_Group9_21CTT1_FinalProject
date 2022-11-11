#include "Obstacle.h"

Obstacle::Obstacle(Rectangle srcRec, Rectangle screenRec, float velocity, Ob_type type)
{
    this->srcRec = srcRec;
    this->screenRec = screenRec;
    this->velocity = velocity;
    this->type = type;
    
}

Obstacle::~Obstacle()
{
}
