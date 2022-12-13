#pragma once
#include "Game.h"
#include "Scoreboard.h"
#include "Instruction.h"

class Program
{
private:
	Font font;
	Home home;
	Screen screen;
	Game game;
	Scoreboard scoreboard;
	Instruction instruction;
public:
	Program();
	~Program();
	void run();
};