#pragma once
#include "home.h"
#include "TextureHolder.h"
#include "Player.h"

#define MAX_INPUT_CHARS 14

class Login {
private:
	Font font;			// New Font

	// Texture2D
	Texture2D* loginBackground, *blurImage;
	Texture2D* playerBox1, *playerBox2;
	Texture2D* loadingMenu, * loadingBar, * loadingEle;
	Texture2D* inputButton1, *inputButton2;
	Texture2D* okButton1, * okButton2;

	// Position
	Rectangle inputButtonRec;
	float posLoadingX, posLoadingY, posBarX, posBarY, posEleX[26], posEleY;
	float posPlayerBoxX[2], posPlayerBoxY;

	// Attributes for frames
	int letterFrame;
	int curFrame;
	const int numsFrame = 25;
	const int delay = 5;

	// Check variable
	bool loadSuccess;
	bool mouseOnText, mouseOnOK;
	bool isOk;
	bool backButton;
	std::string inputName;

	// Store state
	int numsState;
	std::pair<int,int> currentState;

public:
	Login();					// Constructor

	~Login();					// Destructor

	// Main methods
	Screen update();			// Process events
	void draw();				// Drawing menu

	void drawListPlayer();		// Drawing list of saved player

	int indexInPlayerList();

};