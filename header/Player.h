#include "GameObject.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

class Player: public GameObject
{
private:
    std::vector<std::pair<float, std::string>> highScoreList;
    void loadState();
public:
    // playtime in sec
    int playtime;
    std::string name;
    int level;

    Player();
    Player(std::string name);
    ~Player();
    
    bool checkHighScoreBoard();
    void storeHighScore();
    float calHighScore();

    void storeState();
};
