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
        _typeOfObstacles = NONE;
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
            while (_numsOfObstacles == 0)
            {
                _numsOfObstacles = Rand(1, 4);
            }
        }
        else if (level <= 6)
        {
            _numsOfObstacles = Rand(2, 5);
            while (_numsOfObstacles == 0)
            {
                _numsOfObstacles = Rand(2, 5);
            }
        }
        else if (level <= 9)
        {
            _numsOfObstacles = Rand(3, 5);
        }
        else if (level <= 12)
        {
            _numsOfObstacles = Rand(4, 5);
        }
        else if (level <= 15)
        {
            _numsOfObstacles = Rand(4, 6);
        }
        else if (level <= 18)
        {
            _numsOfObstacles = Rand(5, 7);
        }
        else
        {
            _numsOfObstacles = Rand(7, 8);
        }
        _istraffic = Rand(0, 1);
        int ChooseObsType = Rand(1, 2);
        if(ChooseObsType == 1)
        {
            _typeOfObstacles = CAR;
        }
        else if(ChooseObsType == 2)
        {
            _typeOfObstacles = TRUCK;
        }
    }
}

std::vector<Lane> random(int level)
{
    assert(level > 0 && level <= 20);
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
            int to_add = Rand(1, 4);
            while (to_add + (int)lanes.size() > numsOfLanes - 1 || to_add == 0)
            {
                if (level <= 8) to_add = Rand(1, 4);
                else if (level <= 14) to_add = Rand(2, 4);
                else if (level <= 20) to_add = Rand(2, 5);
                else to_add = Rand(2, 6);
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
    }
    return lanes;
}

void displayTest(vector<Lane> lanes)
{
    for (int i = 0; i < (int)lanes.size(); ++i) {
        lanes[i].displayLane();
    }
}

void Lane::displayLane() {
    printf("[Y: %f,\n NumsOfObs: %i,\n Is traffic: %i,\n Lane Velocity: %i,\n Lane Type: %i,\n ObsType: %i]\n",
    _screenPos.y, _numsOfObstacles, _istraffic, _laneVelocity, _laneType, _typeOfObstacles);
}

std::vector<Lane> allLane;