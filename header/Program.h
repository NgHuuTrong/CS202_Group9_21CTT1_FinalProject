#pragma once
#include "Game.h"
#include "Scoreboard.h"
class Program
{
private:
	Font font;
	Home home;
	Screen screen;
	Game game;
	Scoreboard scoreboard;
public:
	Program();
	~Program();
	void run();
};