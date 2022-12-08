#include "../header/Lane.h"
using namespace std;

Lane::Lane()
{
    
}

Lane::~Lane()
{
    
}

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
typedef long long LL;
long long Rand(long long l, long long h) {
    assert(l <= h);
    // return abs(l + rd() * 1LL * rd() % (h - l + 1));
    return (rd() % (h - l + 1)) + l;
}



Lane::Lane(int level, int laneType)
{
    _laneVelocity = level * 2;  
    this->level = level;
    if(laneType == 0) // PAVEMENT
    {   
        _laneType = PAVEMENT;
        _srcRec = { 0, 0, 960, 90 };
        _screenPos = { 0, 0 };
        _numsOfObstacles = 0;
        _istraffic = false;
    }
    else if(laneType == 1) // ROAD
    {
        _laneType = ROAD;
        _srcRec = { 0, 0, 960, 90 };
        _screenPos = { 0, 0 };
        if (level >= 1 && level <= 3)
        {
            _numsOfObstacles = Rand(1, 4);
        }
        else if (level <= 5)
        {
            _numsOfObstacles = Rand(2, 4);
        }
        else if (level <= 15)
        {
            _numsOfObstacles = Rand(3, 4);
        }
        else if (level <= 25)
        {
            _numsOfObstacles = Rand(4, 5);
        }
        else 
        {
            _numsOfObstacles = Rand(4, 7);
        }
        _istraffic = Rand(0, 1);
        _direction = Rand(0, 1);
    }
}

std::vector<Lane> random(int level)
{
    //assert(level > 0 && level <= 20);
    int numsOfLanes;
    vector<Lane> lanes;
    if (level >= 1 && level <= 3) {
        numsOfLanes = 8;
        lanes.push_back(Lane(level, 0));
        for (int i = 1; i < numsOfLanes - 1; i++)
        {
            if (i != 2 && i != 5) lanes.push_back(Lane(level, 1));
            else lanes.push_back(Lane(level, 0));
        }
        lanes.push_back(Lane(level, 0));
    }
    else {
        numsOfLanes = level + 6;
        lanes.push_back(Lane(level, 0));
        while ((int)lanes.size() < numsOfLanes - 1)
        {   
            int to_add;
            if (level <= 8) to_add = Rand(1, 4);
            else if (level <= 14) to_add = Rand(2, 4);
            else if (level <= 20) to_add = Rand(2, 5);
            else to_add = Rand(2, 6);
            while (to_add + (int)lanes.size() > numsOfLanes - 1)
            {
                to_add = Rand(1, 4);
            }
            for (int i = 0; i < to_add; i++)
            {
                lanes.push_back(Lane(level, 1));
            }
            if ((int)lanes.size() < numsOfLanes - 2)
            {
                lanes.push_back(Lane(level, 0));
            }
        }
        lanes.push_back(Lane(level, 0));
    }
    for (int i = 0; i < (int)lanes.size(); ++i) {
        lanes[i]._screenPos.x = 0;
        lanes[i]._screenPos.y = i * lanes[i]._srcRec.height;
        if (lanes[i]._laneType == PAVEMENT) continue;
        for (int j = 0; j < (int)lanes[i]._numsOfObstacles; j++)
        {
            int ChooseObsType = Rand(1, 3);
            if (ChooseObsType == 1)
                lanes[i]._obstacles.push_back(Obstacle(i, REDCAR));
            if (ChooseObsType == 2)
                lanes[i]._obstacles.push_back(Obstacle(i, BLUECAR));
            if (ChooseObsType == 3)
                lanes[i]._obstacles.push_back(Obstacle(i, AMBULANCE));
        }
        for (int j = 0; j < (int)lanes[i]._numsOfObstacles; j++)
        {
            int tmp = Rand(0, 23);
            bool check = true, flag = false;
            while (check)
            {
                flag = false;
                for (int k = 0; k < j; k++)
                {
                    if (abs(tmp * 40 - lanes[i]._obstacles[k].screenRec.x) < 80 || abs(tmp * 40 - lanes[i]._obstacles[k].screenRec.x) >= 920)
                    {
                        std::cerr << abs(tmp * 40 - lanes[i]._obstacles[k].screenRec.x) << std::endl;
                        tmp = Rand(0, 23);
                        flag = true;
                        break;
                    }
                }
                if (!flag) check = false;
            }
            lanes[i]._obstacles[j].screenRec.x = tmp * 40;
        }
    }
    std::cerr << "finish random" << std::endl;
    return lanes;
}

std::vector<Lane> allLane;