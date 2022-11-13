#pragma once
#include "../header/raylib.h"
#include <vector>
#include <algorithm>
#include <time.h>
#include <chrono>
#include <random>
#include <assert.h>
#include <iostream>
// #include "../header/Obstacle.h"
enum LaneType{PAVEMENT, ROAD}; // PAVEMENT: no obstacles, ROAD: has obstacles
enum TypeOfObstacles{NONE, CAR, TRUCK};

class Lane {
private:
    int _numsOfObstacles; // range = [1; 5] (random)
    bool _istraffic; // 0 = no traffic, 1 = traffic
    TypeOfObstacles _typeOfObstacles;
    int _laneVelocity; // range = [1; 20] base on level
public:
    int level;
    LaneType _laneType;
    Rectangle _srcRec; // rectangle to take the image from the sprite sheet
    Vector2 _screenPos; // rectangle to draw the image on the screen

    Lane();
    Lane(int level, int laneType);
    ~Lane();
    void displayLane();

    friend void displayTest(std::vector<Lane> lanes);
    friend std::vector<Lane> random(int level);
};  
long long Rand(long long l, long long h);

void displayTest(std::vector<Lane> lanes);
std::vector<Lane> random(int level);


extern std::vector<Lane> allLane;