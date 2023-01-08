#pragma once
#include "../header/home.h"
#include "../header/Player.h"

class Scoreboard
{
	// Texture2D
	Texture2D *rankBackground;
	Texture2D *rankImage;

	bool backButton;

	// position of rankImage
	float rankImageX, rankImageY;

	// position of State
	float nameX, levelX, timeX, scoreX;   

	float posY[5];

public:
	Scoreboard();		// Constructor

	~Scoreboard();		// Destructor

	// Main methods
	Screen update();	// Process events
	void draw();		// Drawing menu
};

