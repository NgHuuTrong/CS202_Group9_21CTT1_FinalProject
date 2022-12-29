#pragma once
#include "home.h"
#include "Login.h"
#include "TextureHolder.h"

class Game
{
private:
	// Texture2D in Game menu
	Texture2D *txt;
	Texture2D *gameRight, *blurImage;																	 // Lane Textures
	Texture2D *restart_button, *pause_button, *music_button, *resume_button, *home_button, *next_button; // Buttons
	Texture2D* pauseMenu, * victoryMenu;
	std::vector<std::vector<Texture2D *>> charAnim;

	bool backButton, nextButton; // Buttons

	double playTime, startTime;  // Time when playing game

	// Checked variable
	bool isWin;					 // Check Win
	bool pauseState;			 // Check Pause
public:
	Game();					// Constructor

	~Game();				// Destructor
	
	// Main methods of Game menu
	Screen update();		// Process events
	void draw();		    // Drawing menu

	// Drawing methods in Game menu
	void drawRightMenu();	// Drawing detail menu
	void drawButtons();		// Drawing buttons
	void drawPauseMenu();	// Drawing paused state
	void drawVictoryMenu(); // Drawing passed menu
	void drawPlayerState(); // Drawing current detail of player

	// Win, Lose methods
	bool checkLose();	    // Lose
	bool checkWin();	    // Win
};

bool CheckCollision(Player& p, Obstacle& ob); // Checking collision between an obstacle and player
