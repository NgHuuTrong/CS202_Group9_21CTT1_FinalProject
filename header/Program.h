#pragma once
#include "Game.h"
#include "Login.h"
#include "Scoreboard.h"
#include "Instruction.h"
#include "TextureHolder.h"

class Program
{
private:
	Font font;					// Load font

	Screen screen;				// Store current screen

	Home home;					// Store home menu				

	Game game;					// Store game menu

	Login login;				// Store login menu

	Scoreboard scoreboard;		// Store ranking menu

	Instruction instruction;	// Store instruction menu

public:
	Program();					// Constructor

	~Program();					// Destructor

	int isExit = 0;				// Check if exit

	void run();					// Run

	Screen getScreen();			// Screen getter
};