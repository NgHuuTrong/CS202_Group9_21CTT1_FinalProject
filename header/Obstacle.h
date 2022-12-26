#pragma once
#include "GameObject.h"
#include <string>
#include <vector>

enum Ob_type
{
    YCAR,
    PCAR,
    BUS,
    POLICE
};

class Obstacle : public GameObject
{
private:
    std::vector<Texture2D* > txt;

    Ob_type type;
    int numsFrame, curFrame;
public:
    Obstacle();
    Obstacle(int laneIndex, Ob_type type);

    Ob_type getType();
    void renderLeft(float y, float velocity);
    void renderRight(float y, float velocity);
    ~Obstacle();
};
