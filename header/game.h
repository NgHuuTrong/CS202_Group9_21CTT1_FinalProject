#pragma once
#include "Home.h"

class Game
{
private:
	Texture2D pavement, road;
	bool backButton;
public:
	Game();
	Screen update();
	void draw();
	~Game();
};