#pragma once
#include "../header/raylib.h"
#include <vector>
#include <algorithm>
#include <time.h>
#include <chrono>
#include <random>
#include <assert.h>
#include <iostream>

#include "../header/Obstacle.h"
enum LaneType
{
    PAVEMENT,
    ROAD
}; // PAVEMENT: no obstacles, ROAD: has obstacles

class Lane
{
private:
public:
    int _numsOfObstacles;     // range = [1; 5] (random)
    bool _istraffic;          // 0 = no traffic, 1 = traffic
    int _laneVelocity, level; // range = [1; 20] base on level
    LaneType _laneType;
    Rectangle _srcRec;  // rectangle to take the image from the sprite sheet
    Vector2 _screenPos; // rectangle to draw the image on the screen
    bool _direction;    // 0 = left->right, 1 = right->left;
    std::vector<Obstacle> _obstacles;

    Lane();
    Lane(int level, int laneType);
    ~Lane();
    friend std::vector<Lane> random(int level);
};
long long Rand(long long l, long long h);

std::vector<Lane> random(int level);

extern std::vector<Lane> allLane;