#include "../header/GameObject.h"
#include "../header/raylib.h"

GameObject::GameObject(): inLane(-1), screenRec({0, 0, 0, 0}) {}

GameObject::GameObject(int inLane)
{
	this->inLane = inLane;
}

bool GameObject::checkCollision(GameObject &other)
{
	return CheckCollisionRecs(this->screenRec, other.screenRec);
}

void GameObject::setInLane(int x)
{
	this->inLane = x;
}
void GameObject::setScreenRec(Rectangle other)
{
	this->screenRec = other;
}

void GameObject::setScreenRecX(float pos, int velo, short type)
{
	this->screenRec.x -= (type * velo);
	if (this->screenRec.x >= 960) this->screenRec.x = 0;
	if (this->screenRec.x <= -80) this->screenRec.x = 960;
}

void GameObject::moveScreenRecX(float x)
{
	this->screenRec.x += x;
}
void GameObject::moveScreenRecY(float y)
{
	this->screenRec.y += y;
}

int GameObject::getInLane()
{
	return this->inLane;
}
Rectangle GameObject::getScreenRec()
{
	return this->screenRec;
}
