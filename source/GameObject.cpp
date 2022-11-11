#include "GameObject.h"

// check still in window
bool GameObject::inWindow()
{
    // check right border is out of screen to the left, check left border is out of screen to the right
    return this->screenRec.x + this->screenRec.width < 0 || this->screenRec.x > 1000;
}

//check collision
bool GameObject::collision(const GameObject& other)
{
    return CheckCollisionRecs(this->screenRec, other.screenRec);
}
