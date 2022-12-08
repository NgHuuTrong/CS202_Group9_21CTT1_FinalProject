#include "../header/GameObject.h"
#include "../header/raylib.h"

// check still in window

//check collision

GameObject::GameObject(int inLane)
{
	this->inLane = inLane;
}

bool GameObject::checkCollision(GameObject& other)
{
	return CheckCollisionRecs(this->screenRec, other.screenRec);
}	
