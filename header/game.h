#pragma once
#include "home.h"
#include "Player.h"

class Game
{
private:
	Texture2D pavement, road;																		   // Lane Textures
	Texture2D restart_button, pause_button, music_button;											   // Buttons
	Texture2D redcar_left, redcar_right, bluecar_left, bluecar_right, ambulance_left, ambulance_right; // Obstacles Textures
	bool backButton, nextButton;																	   // Buttons
	Player player;																					   // Player
	Texture2D charAnim[4][4];																		   // Player Animation Textures
	int velo = 2;																					   // Velocity
public:
	Game();
	Screen update();
	void draw();
	void drawPlayerState();
	~Game();
};