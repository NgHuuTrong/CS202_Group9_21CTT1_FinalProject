#pragma once
#include "home.h"
#include "Login.h"
#include "TextureHolder.h"

class Game
{
private:
	Texture2D *txt;
	Texture2D *gameRight;																				 // Lane Textures
	Texture2D *restart_button, *pause_button, *music_button, *resume_button, *home_button, *next_button; // Buttons
	std::vector<std::vector<Texture2D *>> charAnim;

	bool backButton, nextButton; // Buttons
	Player player;				 // Player
	double playTime, startTime;

	bool isWin;
	bool pauseState;
	Texture2D *blurImage;
	Texture2D *pauseMenu, *victoryMenu;

	bool CheckCollision(Player &p, Obstacle &ob);

public:
	Game();
	Screen update();
	void draw();
	void drawRightMenu();
	void drawButtons();
	void drawPauseMenu();
	void drawVictoryMenu();
	void drawPlayerState();
	~Game();
};