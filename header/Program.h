#pragma once
#include "Game.h"
class Program
{
private:
	Font font;
	Home home;
	Screen screen;
	Game game;
public:
	Program();
	~Program();
	void run();
};