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
    std::string name;       // Player's name

    int level;              // Current Level

    int curDirection;       /* Front = 0; Back = 1; Left = 2; Right = 3;
                               MoveDown => Front
                               MoveUp => Back
                               MoveLeft => Left
                               MoveRight => Right*/

    bool isMoving;          // Check move

    double time, preTime;   // In second (preTime: save time before this level

    int score;              // Current Score

    int curImage;           // Current Frame

    int posInList;          // Position in the listPlayer

    int bestScore, bestLevel; // Best Score, Best Level
    double bestTime;          // Best Time
public:
    // Constructor
    Player();
    Player(std::string name);

    Player& operator= (const Player& src);
    ~Player();                  // Destructor

    // Score method
    int calScore();             // Calculate score each level (by time)
    void addScore(int x);       // Add
    int getScore();             // Getter
    void setScore(int x);       // Setter

    // High Score
    //void updateListHighScore();                                     // Update
    //std::vector<std::pair<int, std::string>> getHighScoreList();    // Getter

    // State
    void storeState();               // Storing
    void loadState();                // Loading

    // curDirection
    void setCurdirection(int x);     // Setter
    int getCurdirection();           // Getter

    // time
    void setTime(double t);          // Setter
    double getTime();                // Getter
    void timeIncrease(double t);     // Add

    // preTime
    void setPreTime(double t);       // Setter
    double getPreTime();             // Getter

    // name
    void setName(std::string n);     // Setter
    std::string getName();           // Getter
    
    //level 
    void setLevel(float lvl);        // Setter
    int getLevel();                  // Getter

    // posInList
    void setPosInList(int t);        // Setter
    int getPosInList();              // Getter

    // bestTime
    void setBestTime(double t);      // Setter
    double getBestTime();            // Getter

    // bestScore
    void setBestScore(int t);        // Setter
    int getBestScore();              // Getter
    void updateBestScore();

    // bestLevel
    void setBestLevel(int t);        // Setter
    int getBestLevel();              // Getter

    void setIsMoving(bool flag);     // isMoving setter

    void render(std::vector<std::vector<Texture2D *>> charAnim);    // Drawing player (frames)

    void eventKeyboard();            // Process keyboard event
};

void loadAllPlayer();
void saveAllPlayer();
void sortListPlayer();

// decrease score
extern std::vector<Player> listPlayer;
extern Player curPlayer;