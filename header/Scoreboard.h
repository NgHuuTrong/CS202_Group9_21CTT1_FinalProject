#pragma once
#include "../header/home.h"

class Scoreboard
{
	// Texture2D
	Texture2D *rankBackground;
	Texture2D *rankImage;

	bool backButton;

public:
	Scoreboard();		// Constructor

	~Scoreboard();		// Destructor

	// Main methods
	Screen update();	// Process events
	void draw();		// Drawing menu
};