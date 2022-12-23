#pragma once
#include "home.h"
#include "Player.h"
#include "TextureHolder.h"

class Game
{
private:
	Texture2D* gameRight;
	Texture2D *pavement, *road;																				 // Lane Textures
	Texture2D *restart_button, *pause_button, *music_button, *resume_button, *home_button, *next_button;	 // Buttons
	Texture2D *redcar_left, *redcar_right, *bluecar_left, *bluecar_right, *ambulance_left, *ambulance_right; // Obstacles Textures
	bool backButton, nextButton;																			 // Buttons
	Player player;																							 // Player
	std::vector<std::vector<Texture2D*>> charAnim;																				 // Player Animation Textures
	int velo = 2;																							 // Velocity
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