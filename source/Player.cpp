#include "../header/Player.h"

// create new player, name update when close
// Player::Player(): name(""), playtime(0), level(0) {}

// Player::Player() : GameObject(), name("No Name"), curDirection(1),
// curImage(0), isMoving(false) , time(0), score(0) {}

// // load player with name
// Player::Player(std::string name) : Player()
// {
//     this->name = name;
// }
// Player::~Player() {}
// // calculate highscore
float Player::calHighScore()
{
    float high = this->level * 1000 + (1 / this->time) * 1000;
    return high;
}
// // return if player can be in the scoreboard top 5
// bool Player::checkHighScoreBoard()
// {
//     std::ifstream fin;
//     std::string temp_name;
//     float temp_highscore;
//     fin.open("./resource/highscore/highscore.txt");
//     for (int i = 0; i < 5; i++)
//     {
//         fin >> temp_highscore;
//         fin >> temp_name;
//         std::cout << temp_highscore << " " << temp_name << std::endl;
//         this->highScoreList.push_back(std::make_pair(temp_highscore, temp_name));
//     }
//     fin.close();
//     return this->highScoreList[4].first < calHighScore();
// }
// // store highscore if able
// void Player::storeHighScore()
// {
//     float playerHigh = calHighScore();
//     if (!checkHighScoreBoard())
//         return;
//     highScoreList.push_back(std::make_pair(playerHigh, this->name));
//     std::cout << playerHigh << " " << this->name;
//     std::sort(highScoreList.begin(), highScoreList.end());
//     reverse(highScoreList.begin(), highScoreList.end());
//     highScoreList.pop_back();
//     std::ofstream fout("./resource/highscore/highscore.txt");
//     for (int i = 0; i < 5; i++)
//     {
//         fout << highScoreList[i].first << std::endl;
//         fout << highScoreList[i].second << std::endl;
//     }
//     fout.close();
// }
// /*
//     state file: {name}.txt
//     name
//     level
//     playtime
// */
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
    fout << this->time << std::endl;
    fout.close();
}

void Player::loadState()
{
    std::ifstream fin;
    fin.open("./resource/state/" + name + ".txt");
    getline(fin, this->name);
    fin >> this->level;
    fin >> this->time;
    fin.close();
}

// std::string name;
// int level;
// int curDirection;
// bool isMoving;
// double time; // in second
// int score;

// Front = 0; Back = 1; Left = 2; Right = 3;
// MoveDown => Front
// MoveUp => Back
// MoveLeft => Left
// MoveRight => Right
Player::Player(): GameObject(), name(""), level(0), curDirection(0), isMoving(false), time(0.0), score(0), curImage(0) {}

Player::Player(std::string name): Player()
{
    this->name = name;
}
Player::~Player() {}

std::vector<std::pair<int, std::string>>& Player::gethighScoreList()
{
    std::vector<std::pair<int, std::string>> highScoreList = {};

    std::ifstream fin("./resource/highscore/highscore.txt");
    std::string temp_name;
    float temp_highscore;
    for (int i = 0; i < 5; i++)
    {
        fin >> temp_highscore;
        fin >> temp_name;
        std::cout << temp_highscore << " " << temp_name << std::endl;
        highScoreList.push_back(std::make_pair(temp_highscore, temp_name));
    }
    fin.close();
    return highScoreList;
}

void Player::storeHighScore()
{
    std::vector<std::pair<int, std::string>> highScoreList = gethighScoreList();

    float playerHigh = calHighScore();
    highScoreList.push_back(std::make_pair(playerHigh, this->name));
    
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

void Player::render(std::vector<std::vector<Texture2D*>> charAnim)
{
    
    DrawTexturePro(
        *charAnim[this->curDirection][this->curImage / 4],
        {0, 0, (float)charAnim[this->curDirection][this->curImage / 4]->width,
        (float)charAnim[this->curDirection][this->curImage / 4]->height},
		{this->getScreenRec()}, {0, 0},
        0, WHITE
    );
	if (this->isMoving)
	{
		this->curImage++;
		if (this->curImage > 15)
			this->curImage = 0;
		this->isMoving = false;
	}
	else
	{
		this->curImage = 0;
	}
}

// curDirection getter, setter
void Player::setCurdirection(int x)
{
    this->curDirection = x;
}
int Player::getCurdirection()
{
    return this->curDirection;
}
// time getter, setter
void Player::setTime(double t)
{
    this->time = t;
}
double Player::getTime()
{
    return this->time;
}
void Player::timeIncrease(double t)
{
    this->time += t;
}
// name getter, setter
void Player::setName(std::string n)
{
    this->name = n;
}
std::string Player::getName()
{
    return this->name;
}

void Player::setIsMoving(bool flag)
{
    this->isMoving = flag;
}
void Player::setLevel(float lvl)
{
    this->level = lvl;
}
float Player::getLevel()
{
    return this->level;
}
