#pragma once
#include "home.h"
#include "TextureHolder.h"
#include "Player.h"

#define MAX_INPUT_CHARS 14

class Login {
private:
	Font font;
	Texture2D* loginBackground, *blurImage;
	Texture2D* playerBox1, *playerBox2;
	Texture2D* loadingMenu, * loadingBar, * loadingEle;
	Texture2D* inputButton1, *inputButton2;
	Texture2D* okButton1, * okButton2;
	Rectangle inputButtonRec;
	float posLoadingX, posLoadingY, posBarX, posBarY, posEleX[26], posEleY;
	int letterFrame;

	int curFrame;
	const int numsFrame = 25;
	const int delay = 5;
	bool loadSuccess;

	bool mouseOnText, mouseOnOK;
	bool isOk;
	bool backButton;
	std::string inputName;

	int numsState;
	std::pair<int,int> currentState;
	float posPlayerBoxX[2], posPlayerBoxY;
public:
	Login();
	~Login();
	Screen update();
	void draw();
	void drawListPlayer();
	int indexInPlayerList();
};