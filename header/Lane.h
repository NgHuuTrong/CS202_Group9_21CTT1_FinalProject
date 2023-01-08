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
    PAVEMENT,               // PAVEMENT  : no obstacles
    ROAD                    // ROAD      : has obstacles
}; 

enum Light
{
    RED_LIGHT,              // RED LIGHT    :   Stop
    YELLOW_LIGHT,           // YELLOW LIGHT :   Slow
    GREEN_LIGHT             // GREEN LIGHT  :   Ordinary
};

class Lane
{
private:
    Texture2D *txt;             // Texture2D of objects

    int level;

    int _numsOfObstacles;       // range = [1; 4] (random)

    bool _istraffic;            // 0 = no traffic, 1 = traffic

    float _laneVelocity;        // range = [1; 20] base on level

    Light light;                // traffic light

    int countLight;             // red_light = 0 (2s); yellow_light = 1 (1s); green_light = 2 (7s);

    LaneType _laneType;

    Rectangle _srcRec;          // rectangle to take the image from the sprite sheet

    Vector2 _screenPos;         // rectangle to draw the image on the screen

    bool _direction;            // 0 = left->right, 1 = right->left;

    std::vector<Obstacle> _obstacles;

public:
    // Constructor
    Lane();
    Lane(int level, int laneType);

    ~Lane();                                    // Destructor

    float calVelocity();                        // Calculate velocity (speed) by level

    int getNumsOfObstacles();                   // Nums of Obstacle getter

    bool getIsTraffic();                        // isTraffic getter

    float getLaneVelocity();                    // Velocity getter

    Light getLight();                           // Traffic Light getter

    LaneType getLaneType();                     // Type of lane getter

    Rectangle getSrcRec();                      // Source's rectangle getter

    bool getDirection();                        // Direction getter
                
    std::vector<Obstacle> getObstacles();       // Obstacle getter

    void increaseCountLight();                  // Increasing count to change light

    void setScreenRecX(float pos, int i);       // Change position X of all obstacles in lane;

    // Screen's rectangle
    Vector2 getScreenPos();                     // Getter
    void setScreenPos(Vector2 pos);             // Setter

    // Drawing methods
    void render();                              // Drawing lane (pavement or road)
    void renderObstacles(bool isWin, bool pauseState, bool isLose);      // Drawing obstacles in lane
    void renderTrafficLight(bool isWin, bool pauseState, bool isLose);   // Drawing traffic light in lane

    // Friend methods
    friend std::vector<Lane> random(int level);     // random all lane (by level)

};

long long Rand(long long l, long long h);           // random number

std::vector<Lane> random(int level);                // random all lane (by level)

void renderAllLane(bool isWin, bool pauseState, bool isLose);    // Drawing all lane (all object in lane)

extern std::vector<Lane> allLane;                   // global variable for all lane