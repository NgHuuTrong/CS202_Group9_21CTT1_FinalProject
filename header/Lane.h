#pragma once
#include "raylib.h"
#include <vector>
#include <algorithm>
#include <time.h>
#include <chrono>
#include <random>
#include <assert.h>
#include <iostream>

#include "Obstacle.h"
#include "TextureHolder.h"
enum LaneType
{
    PAVEMENT,
    ROAD
}; // PAVEMENT: no obstacles, ROAD: has obstacles

enum Light
{
    RED_LIGHT,
    YELLOW_LIGHT,
    GREEN_LIGHT
};

class Lane
{
private:
    int _numsOfObstacles;     // range = [1; 5] (random)
    bool _istraffic;          // 0 = no traffic, 1 = traffic
    int _laneVelocity, level; // range = [1; 20] base on level
    Light light;
    int countLight;               // red_light = 0 (2s); yellow_light = 1 (1s); green_light = 2 (7s);
    LaneType _laneType;
    Rectangle _srcRec;  // rectangle to take the image from the sprite sheet
    Vector2 _screenPos; // rectangle to draw the image on the screen
    bool _direction;    // 0 = left->right, 1 = right->left;
    std::vector<Obstacle> _obstacles;

public:
    int getNumsOfObstacles();
    bool getIsTraffic();
    int getLaneVelocity();
    int getLevel();
    Light getLight();
    void increaseCountLight();
    LaneType getLaneType();
    Rectangle getSrcRec();
    Vector2 getScreenPos();
    void setScreenPos(Vector2 pos);
    bool getDirection();
    std::vector<Obstacle> getObstacles();
    void setScreenRecX(float pos, int i);

    Lane();
    Lane(int level, int laneType);
    ~Lane();

    void render();
    void renderObstacles();
    friend std::vector<Lane> random(int level);
};
long long Rand(long long l, long long h);

std::vector<Lane> random(int level);

void renderAllLane();

extern std::vector<Lane> allLane;