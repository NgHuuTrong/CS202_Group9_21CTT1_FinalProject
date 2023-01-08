#include "../header/Obstacle.h"

Obstacle::Obstacle() : GameObject() {}

Obstacle::Obstacle(int laneIndex, Ob_type type) : GameObject(laneIndex)
{
    this->type = type;
    curFrame = 0;
    switch (this->type)
    {
    case YCAR:
        numsFrame = 9;
        txt = std::vector<Texture2D *>(numsFrame);
        for (int i = 0; i < numsFrame; i++)
            txt[i] = &TextureHolder::getHolder().get((Textures::ID)(i + 37));
        break;
    case PCAR:
        numsFrame = 9;
        txt = std::vector<Texture2D *>(numsFrame);
        for (int i = 0; i < numsFrame; i++)
            txt[i] = &TextureHolder::getHolder().get((Textures::ID)(i + 59));
        break;
    case BUS:
        numsFrame = 13;
        txt = std::vector<Texture2D *>(numsFrame);
        for (int i = 0; i < numsFrame; i++)
            txt[i] = &TextureHolder::getHolder().get((Textures::ID)(i + 46));
        break;
    case POLICE:
        numsFrame = 9;
        txt = std::vector<Texture2D *>(numsFrame);
        for (int i = 0; i < numsFrame; i++)
            txt[i] = &TextureHolder::getHolder().get((Textures::ID)(i + 68));
        break;
    default:
        break;
    }
    this->screenRec.width = txt[0]->width;
    this->screenRec.height = txt[0]->height;
}

Ob_type Obstacle::getType()
{
    return this->type;
}

void Obstacle::renderLeft(float y, float velocity)
{
    int delay = (velocity >= 8) ? 2 : 10 - (int)velocity;
    if (velocity)
    {
        curFrame++;
        if (curFrame == numsFrame * delay)
            curFrame = 0;
    }
    else
        curFrame = 0;
    DrawTextureRec(
        *txt[curFrame / delay], {0, 0, (float)txt[curFrame / delay]->width, (float)txt[curFrame / delay]->height},
        {(float)this->screenRec.x, y}, WHITE);
}

void Obstacle::renderRight(float y, float velocity)
{
    int delay = (velocity >= 8) ? 2 : 10 - (int)velocity;
    if (velocity)
    {
        curFrame++;
        if (curFrame == numsFrame * delay)
            curFrame = 0;
    }
    else
        curFrame = 0;
    DrawTextureRec(
        *txt[curFrame / delay], {0, 0, (float)-txt[curFrame / delay]->width, (float)txt[curFrame / delay]->height},
        {(float)this->screenRec.x, y}, WHITE);
}

Obstacle::~Obstacle() 
{
    txt.clear();
}
