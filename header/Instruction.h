#pragma once
#include "../header/home.h"

class Instruction {
private:
	int mode;
	int color;
	Texture2D instructionBackground;
	bool backButton;
public:
	Instruction();
	Screen update();
	void draw();
	~Instruction();
};