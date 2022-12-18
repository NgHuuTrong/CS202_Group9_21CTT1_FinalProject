#pragma once
#include <iostream>
#include <string.h>
#include <string>
#include "raylib.h"
#include "screen.h"
#include "Lane.h"

class Home
{
private:
	Texture2D homeBackground; // Texture for background
	short mode; // 0: home, 1: instruction, 2: highscore
public:
	Home();
	Screen update();
	void draw();
	~Home();
};