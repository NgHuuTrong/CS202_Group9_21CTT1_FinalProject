#pragma once
#include <iostream>
#include <string.h>
#include <string>
#include <iomanip>
#include "raylib.h"
#include "screen.h"
#include "Lane.h"
#include "TextureHolder.h"

class Home
{
private:
	Texture2D *homeBackground; // Texture2D for background

	short mode;				   // 0: home, 1: instruction, 2: highscore

public:
	Home();					// Constructor

	~Home();				// Destructor

	// Main methods
	Screen update();		// Process events
	void draw();			// Drawing menu
};