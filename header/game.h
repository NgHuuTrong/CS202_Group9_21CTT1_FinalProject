#pragma once
#include "home.h"
#include "Player.h"

class Game
{
private:
	Texture2D pavement, road; // Images of lane
	Texture2D dog, redcar_left, redcar_right, bluecar_left, bluecar_right, ambulance_left, ambulance_right;
	bool backButton, nextButton;
	// Vector2 dogPos {426, 0};
	Player player;
	std::vector<std::vector<Texture2D>> charAnim;
	//std::vector<std::vector<Vector2>> carPos;
	int velo = 2;
public:
	Game();
	Screen update();
	void draw();
	~Game();
};