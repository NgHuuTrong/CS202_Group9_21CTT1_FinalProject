#pragma once
#include "GameObject.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <exception>

class Player : public GameObject
{
private:
    std::vector<std::pair<float, std::string>> highScoreList;
    void loadState();

public:
    int playtime; // playtime in sec
    std::string name;
    int level;
    int curDirection;
    int curImage;
    bool isMoving;
    double time; // in second
    int score;
    // Vector2 playerPos = {426, 0};
    // int posY;

    Player();
    Player(std::string name);
    ~Player();

    bool checkHighScoreBoard();
    void storeHighScore();
    float calHighScore();

    void storeState();
};
