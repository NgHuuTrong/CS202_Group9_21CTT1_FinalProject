#include "../header/GameObject.h"

// check still in window

//check collision

GameObject::GameObject(int inLane)
{
	this->inLane = inLane;
}

bool GameObject::checkCollision(GameObject& other, bool direction)
{
	if (this->posX + 80 > other.posX && this->posX < other.posX + 80 && this->inLane == other.inLane) {
		return true;
	}
	return false;
}	
