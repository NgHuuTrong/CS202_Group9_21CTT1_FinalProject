#pragma once
#include "home.h"
#include "TextureHolder.h"
#define MAX_INPUT_CHARS 11

class Login {
private:
	Font font;
	Texture2D* loginBackground;
	Texture2D* inputButton1, *inputButton2;
	Texture2D* okButton1, * okButton2;
	Rectangle inputButtonRec;
	int letterFrame;
	bool mouseOnText, mouseOnOK;
	bool backButton;
	std::string inputName;

public:
	Login();
	~Login();
	Screen update();
	void draw();
};