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
    _laneVelocity = level;  
        
    if(laneType == 0) // PAVEMENT
    {   
        _laneType = PAVEMENT;
        _srcRec = { 0, 0, 100, 100 };
        _screenRec = { 0, 0, 1000, 100 };
        _numsOfObstacles = 0;
        _typeOfObstacles = NONE;
        _istraffic = false;
    }
    else if(laneType == 1) // ROAD
    {
        _laneType = ROAD;
        _srcRec = { 0, 0, 100, 100 };
        _screenRec = { 0, 0, 1000, 100 };
        if (level >= 1 && level <= 5)
        {
            _numsOfObstacles = Rand(1, 4);
            while (_numsOfObstacles == 0)
            {
                _numsOfObstacles = Rand(1, 4);
            }
        }
        else if (level >= 6 && level <= 10)
        {
            _numsOfObstacles = Rand(2, 5);
            while (_numsOfObstacles == 0)
            {
                _numsOfObstacles = Rand(2, 5);
            }
        }
        else if (level >= 11 && level <= 15)
        {
            _numsOfObstacles = Rand(3, 5);
        }
        else if (level >= 16 && level <= 20)
        {
            _numsOfObstacles = Rand(4, 5);
        }
        else
        {
            _numsOfObstacles = 5;
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
    if (level >= 1 && level <= 5) {
        numsOfLanes = 5;
        lanes.push_back(Lane(level, 0));
        while((int)lanes.size() < numsOfLanes - 1)
        {
            for (int i = 0; i < 3; i++)
            {
                lanes.push_back(Lane(level, 1));
            }
        }
        lanes.push_back(Lane(level, 0));
    }
    else if (level >= 6 && level <= 10) {
        numsOfLanes = 10;
        lanes.push_back(Lane(level, 0));
        while ((int)lanes.size() < numsOfLanes - 1)
        {   
            int to_add = Rand(1, 4);
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
    else if (level >= 11 && level <= 15) {
        numsOfLanes = 15;
        lanes.push_back(Lane(level, 0));
        while (lanes.size() < numsOfLanes - 1)
        {
            int to_add = Rand(1, 5);
            while (to_add + lanes.size() > numsOfLanes - 1)
            {
                to_add = Rand(1, 5);
            }
            for (int i = 0; i < to_add; i++)
            {
                lanes.push_back(Lane(level, 1));
            }
            if (lanes.size() < numsOfLanes - 2)
            {
                lanes.push_back(Lane(level, 0));
            }
        }
        lanes.push_back(Lane(level, 0));
    }
    else if (level >= 16 && level <= 20) {
        numsOfLanes = 20;
        lanes.push_back(Lane(level, 0));
        while (lanes.size() < numsOfLanes - 1)
        {
            int to_add = Rand(1, 6);
            while (to_add + lanes.size() > numsOfLanes - 1)
            {
                to_add = Rand(1, 6);
            }
            for (int i = 0; i < to_add; i++)
            {
                lanes.push_back(Lane(level, 1));
            }
            if (lanes.size() < numsOfLanes - 2)
            {
                lanes.push_back(Lane(level, 0));
            }
        }
        lanes.push_back(Lane(level, 0));
    }
    for (int i = 0; i < (int)lanes.size(); ++i) {
        lanes[i]._screenRec.x = 0;
        lanes[i]._screenRec.y = i * 100;
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
    _screenRec.y, _numsOfObstacles, _istraffic, _laneVelocity, _laneType, _typeOfObstacles);
}
