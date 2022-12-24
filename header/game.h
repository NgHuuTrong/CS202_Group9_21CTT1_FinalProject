#pragma once
#include "home.h"
#include "Player.h"
#include "TextureHolder.h"


class Game
{
private:
	Texture2D* gameRight;																			 // Lane Textures
	Texture2D *restart_button, *pause_button, *music_button, *resume_button, *home_button, *next_button;	 // Buttons
	Texture2D *redcar_left, *redcar_right, *bluecar_left, *bluecar_right, *ambulance_left, *ambulance_right; // Obstacles Textures
	std::vector<std::vector<Texture2D*>> charAnim;
	
	bool backButton, nextButton;																			 // Buttons
	Player player;																							 // Player
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
	void drawPlayerState();
	~Game();
};