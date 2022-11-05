#pragma once
#include "../header/raylib.h"
#include <vector>
#include <algorithm>
#include <time.h>
#include <chrono>
#include <random>
#include <assert.h>
// #include "Obstacles.h"

class Lane {
private:
    Rectangle _srcRec; // rectangle to take the image from the sprite sheet
    Rectangle _screenRec; // rectangle to draw the image on the screen
    int _numsOfObstacles; // range = [1; 5] (random)
    bool _istraffic; // 0 = no traffic, 1 = traffic
    enum _laneType{PAVEMENT, ROAD}; // PAVEMENT: no obstacles, ROAD: has obstacles
    enum _typeOfObstacles{CAR, TRUCK}; 
    int _laneVelocity; // range = [1; 20] base on level
public:
    Lane();
    Lane(int level, int laneType);
    ~Lane();
    std::vector<Lane> random(int level);    
};  