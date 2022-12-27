#pragma once
#include "Game.h"
#include "Login.h"
#include "Scoreboard.h"
#include "Instruction.h"
#include "TextureHolder.h"

class Program
{
private:
	Font font;
	Home home;
	Screen screen;
	Game game;
	Login login;
	Scoreboard scoreboard;
	Instruction instruction;

public:
	int isExit = 0;
	Program();
	~Program();
	void run();
};