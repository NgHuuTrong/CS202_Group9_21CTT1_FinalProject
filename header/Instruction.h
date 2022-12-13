#pragma once
#include "../header/home.h"

class Instruction {
private:
	int mode;
	int color;
	Texture2D instructionBackground1;
	Texture2D instructionBackground2;
	bool backButton;
public:
	Instruction();
	Screen update();
	void draw();
	~Instruction();
};