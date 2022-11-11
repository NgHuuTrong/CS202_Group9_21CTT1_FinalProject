#include "../header/Game.h"
#include "../header/raygui.h"


Game::Game()
{
	roadSide = LoadTexture("data/roadSide.png");
	road = LoadTexture("data/road.png");
	backButton = false;
}

Screen Game::update()
{
	
}

void Game::draw()
{
	DrawTexture(roadSide, 50, 100, WHITE);
	DrawTexture(road, 50, 300, WHITE);
	if (GuiLabelButton({ 1150, 100, 100, 50 }, "BACK"))
		backButton = true;
}

Game::~Game()
{
	UnloadTexture(roadSide);
	UnloadTexture(road);
}