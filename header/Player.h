#pragma once
#include "GameObject.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

class Player : public GameObject
{
private:
    std::string name;
    int level;
    // Front = 0; Back = 1; Left = 2; Right = 3;
    // MoveDown => Front
    // MoveUp => Back
    // MoveLeft => Left
    // MoveRight => Right
    int curDirection;
    bool isMoving;
    double time, preTime; // in second
    int score;
    int curImage;

    std::vector<std::pair<int, std::string>> &gethighScoreList();

public:
    Player();
    Player(std::string name);
    ~Player();

    // Score
    float calHighScore();
    int getScore();
    void addScore(int x);
    void setScore(int x);
    void storeHighScore();

    void storeState();
    void loadState();

    // curDirection getter, setter
    void setCurdirection(int x);
    int getCurdirection();

    // time getter, setter
    void setTime(double t);
    double getTime();
    void timeIncrease(double t);

    // name getter, setter
    void setName(std::string n);
    std::string getName();

    void setLevel(float lvl);
    int getLevel();
    void setIsMoving(bool flag);

    void render(std::vector<std::vector<Texture2D *>> charAnim);

    void eventKeyboard();
};

extern std::vector<Player> listPlayer;
extern Player curPlayer;
void loadAllPlayer();