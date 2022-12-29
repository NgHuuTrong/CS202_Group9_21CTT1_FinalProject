#pragma once
#include "../header/home.h"

class Instruction
{
private:
	// Texture2D
	Texture2D* instructionBackground1;	
	Texture2D* instructionBackground2;

	int mode;				// Page 1 or 2
	bool backButton;		// Back Button

public:
	Instruction();			// Constructor

	~Instruction();			// Destructor

	// Main methods
	Screen update();		// Process events
	void draw();			// Drawing menu
};