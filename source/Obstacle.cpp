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

void Obstacle::renderLeft()
{
    TextureHolder* tHold;
    Texture2D txt;
    switch (this->type)
    {
    case REDCAR:
        txt = tHold->get(Textures::REDCAR_LEFT);
        break;
    case BLUECAR:
        txt = tHold->get(Textures::BLUECAR_LEFT);
        break;
    case AMBULANCE:
        txt = tHold->get(Textures::AMBULANCE_LEFT);
        break;
    default:
        break;
    }
    Rectangle srcTexture = { 0, 0, (float)txt.width, float(txt.height) };
    
    Vector2 screenPos = { (float)this->getScreenRec().x, (float)this->getScreenRec().y };
    DrawTextureRec(txt, srcTexture, screenPos, WHITE);
}

void Obstacle::renderRight()
{
    TextureHolder* tHold;
    Texture2D txt;
    switch (this->type)
    {
    case REDCAR:
        txt = tHold->get(Textures::REDCAR_RIGHT);
        break;
    case BLUECAR:
        txt = tHold->get(Textures::BLUECAR_RIGHT);
        break;
    case AMBULANCE:
        txt = tHold->get(Textures::AMBULANCE_RIGHT);
        break;
    default:
        break;
    }
    Rectangle srcTexture = { 0, 0, (float)txt.width, float(txt.height) };
    Vector2 screenPos = { (float)this->getScreenRec().x, (float)this->getScreenRec().y + 15 };
    DrawTextureRec(txt, srcTexture, screenPos, WHITE);
}

void Obstacle::renderUp() {}

void Obstacle::renderDown() {}

Obstacle::~Obstacle() {}
