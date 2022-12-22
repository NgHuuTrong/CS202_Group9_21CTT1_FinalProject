#pragma once
#include "../header/home.h"

class Scoreboard
{
	Texture2D* rankBackground;
	Texture2D* rankImage;
	bool backButton;

public:
	Scoreboard();
	Screen update();
	void draw();
	~Scoreboard();
};