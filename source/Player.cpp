#include "../header/Player.h"

// create new player, name update when close
//Player::Player(): name(""), playtime(0), level(0) {}

// Front = 0; Back = 1; Left = 2; Right = 3;
// MoveDown => Front
// MoveUp => Back
// MoveLeft => Left
// MoveRight => Right
Player::Player() {
    this->name = "No Name";
    this->curDirection = 1;
    this->curImage = 0;
    this->isMoving = false;
}

// load player with name
Player::Player(std::string name): Player()
{
    this->name = name;
}
Player::~Player() {}
// calculate highscore
float Player::calHighScore()
{
    if (this->playtime == 0)
        throw std::runtime_error("playtime is zero");
    float high = this->level * 100000 + (1 / this->playtime) * 1000000;
    std::cout << "HighScore Log: " << high << std::endl;
    return high;
}
// return if player can be in the scoreboard top 5
bool Player::checkHighScoreBoard()
{
    std::ifstream fin;
    std::string temp_name;
    float temp_highscore;
    fin.open("./resource/highscore/highscore.txt");
    for (int i = 0; i < 5; i++)
    {
        fin >> temp_highscore;
        fin >> temp_name;
        std::cout << temp_highscore << " " << temp_name << std::endl;
        this->highScoreList.push_back(std::make_pair(temp_highscore, temp_name));
    }
    fin.close();
    return this->highScoreList[4].first < calHighScore();
}
// store highscore if able
void Player::storeHighScore()
{
    float playerHigh = calHighScore();
    if (!checkHighScoreBoard())
        return;
    highScoreList.push_back(std::make_pair(playerHigh, this->name));
    std::cout << playerHigh << " " << this->name;
    std::sort(highScoreList.begin(), highScoreList.end());
    reverse(highScoreList.begin(), highScoreList.end());
    highScoreList.pop_back();
    std::ofstream fout("./resource/highscore/highscore.txt");
    for (int i = 0; i < 5; i++)
    {
        fout << highScoreList[i].first << std::endl;
        fout << highScoreList[i].second << std::endl;
    }
    fout.close();
}
/*
    state file: {name}.txt
    name
    level
    playtime
*/ 
void Player::storeState()
{
    if (name == "")
    {
        std::cerr << "Invalid name" << std::endl;
        throw std::runtime_error("Invalid name");
    }
    else if (level == 0)
    {
        std::cerr << "Checkpoint not reached" << std::endl;
        throw std::runtime_error("Checkpoint not reached");
    }
    std::ofstream fout;
    fout.open("./resource/state/" + name + ".txt");
    fout << this->name << std::endl;
    fout << this->level << std::endl;
    fout << this->playtime << std::endl;
    fout.close();
}

void Player::loadState()
{
    std::ifstream fin;
    fin.open("./resource/state/" + name + ".txt");
    getline(fin, this->name);
    fin >> this->level;
    fin >> this->playtime;
    fin.close();
}
