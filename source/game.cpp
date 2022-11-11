#include "../header/Game.h"
#include "../header/raygui.h"


Game::Game()
{
	pavement = LoadTexture("data/pavement.png");
	road = LoadTexture("data/road.png");
	backButton = false;
}

Screen Game::update()
{
	if (backButton)
	{
		backButton = false;
		return HOME;
	}
	else return GAME;
}

void Game::draw()
{
	DrawTexture(pavement, 50, 100, WHITE);
	DrawTexture(road, 50, 300, WHITE);
	if (GuiLabelButton({ 1150, 100, 100, 50 }, "BACK"))
		backButton = true;
}

Game::~Game()
{
	UnloadTexture(pavement);
	UnloadTexture(road);
}