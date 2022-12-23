#include "../header/Obstacle.h"

Obstacle::Obstacle(): GameObject() {}

Obstacle::Obstacle(int laneIndex, Ob_type type): GameObject(laneIndex)
{
    this->type = type;
}

Ob_type Obstacle::getType()
{
    return this->type;
}

void Obstacle::renderLeft(float y)
{
    Texture2D* txt;
    switch (this->type)
    {
    case REDCAR:
        txt = &TextureHolder::getHolder().get(Textures::REDCAR_LEFT);
        break;
    case BLUECAR:
        txt = &TextureHolder::getHolder().get(Textures::BLUECAR_LEFT);
        break;
    case AMBULANCE:
        txt = &TextureHolder::getHolder().get(Textures::AMBULANCE_LEFT);
        break;
    default:
        break;
    }
    DrawTextureRec(
        *txt, { 0, 0, (float)txt->width, (float)txt->height },
        { (float)this->getScreenRec().x, y }, WHITE
    );
}

void Obstacle::renderRight(float y)
{
    Texture2D* txt;
    switch (this->type)
    {
    case REDCAR:
        txt = &TextureHolder::getHolder().get(Textures::REDCAR_RIGHT);
        break;
    case BLUECAR:
        txt = &TextureHolder::getHolder().get(Textures::BLUECAR_RIGHT);
        break;
    case AMBULANCE:
        txt = &TextureHolder::getHolder().get(Textures::AMBULANCE_RIGHT);
        break;
    default:
        break;
    }
    DrawTextureRec(
        *txt, { 0, 0, (float)txt->width, (float)txt->height },
        { (float)this->getScreenRec().x, y }, WHITE
    );
}

Obstacle::~Obstacle() {}
