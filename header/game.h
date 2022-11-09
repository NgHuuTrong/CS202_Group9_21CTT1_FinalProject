#pragma once
#include "home.h"

class Game
{
private:
	Font font;
	Home home;
public:
	Game();
	~Game();
	void run();
};