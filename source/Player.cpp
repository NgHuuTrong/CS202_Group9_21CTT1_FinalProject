#include "../header/Player.h"
#include "../header/Lane.h"

Player::Player() : GameObject(), name(""), level(1), curDirection(0), isMoving(false), time(0.0), preTime(0.0), score(0), curImage(0), posInList(0), bestScore(0), bestLevel(1), bestTime(0) {}

Player::Player(std::string name) : Player()
{
    this->name = name;
    this->screenRec = { 426, 0, 44, 59 };
}

Player& Player::operator=(const Player& src) {
    if (this == &src) return *this;
    GameObject::operator=(src);
    this->name = src.name;
    this->level = src.level;
    this->curDirection = src.curDirection;
    this->isMoving = src.isMoving;
    this->time = src.time;
    this->preTime = src.preTime;
    this->score = src.score;
    this->curImage = src.curImage;
    this->posInList = src.posInList;
    this->bestLevel = src.bestLevel;
    this->bestScore = src.bestScore;
    this->bestTime = src.bestTime;
    return *this;
}

// calculate highscore
int Player::calScore()
{
    int high = int((float)(1 + 1 / (this->time - this->preTime)) * (1000 + this->level * 100));
    return high;
}

void Player::addScore(int x)
{
    this->score += x;
}

int Player::getScore()
{
    return score;
}

void Player::setScore(int x)
{
    this->score = x;
}
 /*
     state file: {name}.txt
     name
     level
     playtime
 */
void Player::storeState()
{
    std::string statepath = "./resource/login/state/" + name + ".txt";
    std::ofstream fout(statepath);
    fout << this->name << std::endl;
    fout << this->level << std::endl;
    fout << this->preTime << std::endl;
    fout << this->score << std::endl;
    fout.close();

    std::string highscorepath = "./resource/highscore/" + name + ".txt";
    fout.open(highscorepath);
    fout << this->bestLevel << std::endl;
    fout << this->bestTime << std::endl;
    fout << this->bestScore << std::endl;
    fout.close();
}

void Player::loadState()
{
    std::string statepath = "./resource/login/state/" + name + ".txt";
    std::cerr << "./resource/login/state/" << name << ".txt" << std::endl;
    if (!FileExists(statepath.c_str()))
        throw std::runtime_error("Invalid file state of player: " + name);
    std::ifstream fin(statepath);
    getline(fin, this->name);
    fin >> this->level;
    fin >> this->time;
    this->preTime = this->time;
    fin >> this->score;
    fin.close();
    
    std::string highscorepath = "./resource/highscore/" + name + ".txt";
    fin.open(highscorepath);
    fin >> this->bestLevel;
    fin >> this->bestTime;
    fin >> this->bestScore;
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

Player::~Player() 
{
}

//void saveFileHighScore(std::vector<std::pair<int, std::string>> listHighScore)
//{
//    std::string filepath = "./resource/highscore/highscore.txt";
//    std::ofstream fout(filepath);
//    for (int i = 0; i < listHighScore.size(); i++)
//    {
//        fout << listHighScore[i].first << std::endl;
//        fout << listHighScore[i].second << std::endl;
//    }
//    fout.close();
//}

//std::vector<std::pair<int, std::string>> Player::getHighScoreList()
//{
//    return listHighScore;
//}
//
//void Player::updateListHighScore()
//{
//    listHighScore.push_back(std::make_pair(this->score, this->name));
//
//    std::sort(listHighScore.begin(), listHighScore.end());
//    reverse(listHighScore.begin(), listHighScore.end());
//    listHighScore.pop_back();
//}

void Player::render(std::vector<std::vector<Texture2D *>> charAnim)
{
    DrawTexturePro(
        *charAnim[this->curDirection][this->curImage / 4],
        {0, 0, (float)charAnim[this->curDirection][this->curImage / 4]->width,
         (float)charAnim[this->curDirection][this->curImage / 4]->height},
        {this->getScreenRec()}, {0, 0},
        0, WHITE);
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

void Player::setPreTime(double t)
{
    this->preTime = t;
}

double Player::getPreTime()
{
    return preTime;
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

int Player::getLevel()
{
    return this->level;
}

void Player::setPosInList(int t) {
    this->posInList = t;
}

int Player::getPosInList() {
    return this->posInList;
}

void Player::setBestTime(double t) {
    this->bestTime = t;
}

double Player::getBestTime() {
    return this->bestTime;
}

void Player::setBestScore(int t) {
    this->bestScore = t;
}

int Player::getBestScore() {
    return this->bestScore;
}

void Player::setBestLevel(int t) {
    this->bestLevel = t;
}

void Player::updateBestScore() {
    if (this->score > this->bestScore) {
        this->bestScore = this->score;
        this->bestTime = this->time;
        this->bestLevel = this->level + 1;
    }
}

int Player::getBestLevel() {
    return this->bestLevel;
}

void Player::eventKeyboard()
{
    {
        if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))
        {
            this->curDirection = 0;
            this->isMoving = true;
            this->screenRec.y += 5;
            if (allLane[allLane.size() - 1].getScreenPos().y > 630)
            {

                if (this->screenRec.y >= 270)
                {
                    for (int i = 0; i < (int)allLane.size(); i++)
                        allLane[i].setScreenPos({0, -5});
                    this->screenRec.y = 270;
                }
            }
        }
        else if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))
        {
            this->curDirection = 1;
            this->isMoving = true;
            this->screenRec.y -= 5;
            if (allLane[0].getScreenPos().y < 0)
            {
                for (int i = 0; i < (int)allLane.size(); i++)
                    allLane[i].setScreenPos({0, 5});
                if (this->screenRec.y <= 270)
                    this->screenRec.y = 270;
                
            }
            if (this->screenRec.y <= 0)
                this->screenRec.y = 0;
        }
        else if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
        {
            this->curDirection = 2;
            this->isMoving = true;
            if (this->screenRec.x - 5 > 0)
                this->moveScreenRecX(-5);
        }
        else if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
        {
            this->curDirection = 3;
            this->isMoving = true;
            if (this->screenRec.x + 44 < 960)
                this->moveScreenRecX(5);
        }
    }
}

void loadAllPlayer() {
    std::string filepath = "./resource/login/player.txt";
    if (!FileExists(filepath.c_str()))
        throw std::runtime_error("Invalid file player.txt");
    std::ifstream finPlayer(filepath);
    std::string temp;
    while (!finPlayer.eof()) {
        getline(finPlayer, temp);
        if (temp == "") break;
        Player t(temp);
        t.loadState();
        listPlayer.push_back(t);
    }
    finPlayer.close();
}

void saveAllPlayer()
{
    std::string allPlayerPath = "./resource/login/player.txt";
    std::ofstream foutPlayers(allPlayerPath);
    for (int i = 0; i < (int)listPlayer.size(); i++)
    {
        foutPlayers << listPlayer[i].getName() << std::endl;
        listPlayer[i].storeState();
    }
    foutPlayers.close();
}

void sortListPlayer() {
    for (int i = 0; i < listPlayer.size(); i++) {
        for (int j = i + 1; j < listPlayer.size(); j++) {
            if (listPlayer[i].getBestScore() < listPlayer[j].getBestScore()) {
                Player temp = listPlayer[i];
                listPlayer[i] = listPlayer[j];
                listPlayer[j] = temp;
            }
        }
    }
    for (int i = 0; i < listPlayer.size(); i++) {
        if (curPlayer.getName() == listPlayer[i].getName()) {
            curPlayer.setPosInList(i);
            break;
        }
    }
}

std::vector<Player> listPlayer;
Player curPlayer("");
