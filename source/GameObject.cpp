#include "../header/GameObject.h"
#include "../header/raylib.h"

GameObject::GameObject()
{
}

GameObject::GameObject(int inLane)
{
	this->inLane = inLane;
}

bool GameObject::checkCollision(GameObject &other)
{
	return CheckCollisionRecs(this->screenRec, other.screenRec);
}
