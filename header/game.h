#pragma once
#include "Home.h"

class Game
{
private:
	Texture2D pavement, road; // Images of lane
	bool backButton, nextButton;
public:
	Game();
	Screen update();
	void draw();
	~Game();
};