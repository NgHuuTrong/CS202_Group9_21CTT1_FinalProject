#include "../header/Game.h"
#include "../header/raygui.h"


Game::Game()
{
	pavement = LoadTexture("data/pavement.png");
	road = LoadTexture("data/road.png");
	backButton = nextButton = false;
}

Game::~Game()
{
	UnloadTexture(pavement);
	UnloadTexture(road);
}

Screen Game::update()
{
	if (GetMouseWheelMove() == -1 && allLane[allLane.size() - 1]._screenPos.y > 720 - pavement.height)
	{
		for (int i = 0; i < allLane.size(); i++)
		{
			allLane[i]._screenPos.y -= 45;
		}
	}
	if (GetMouseWheelMove() == 1 && allLane[0]._screenPos.y < 0)
	{
		for (int i = 0; i < allLane.size(); i++)
		{
			allLane[i]._screenPos.y += 45;
		}
	}
	if (backButton)
	{
		backButton = false;
		return HOME;
	}
	else if (nextButton)
	{
		nextButton = false;
		int level = allLane[0].level + 1;
		allLane.clear();
		allLane = random(level);
		return GAME;
	}
	else return GAME;
}

void Game::draw()
{
	for (Lane l : allLane)
	{
		if (l._laneType == PAVEMENT)
			DrawTextureRec(pavement, l._srcRec, l._screenPos, WHITE);
		else if (l._laneType == ROAD)
			DrawTextureRec(road, l._srcRec, l._screenPos, WHITE);
		DrawLineEx(l._screenPos, { 960, l._screenPos.y }, 2, WHITE);
	}
	DrawRectangleLinesEx({ 0, 0, 960, 720 }, 3, BLACK);
	DrawText(TextFormat("Level: %i", allLane[0].level), 1000, 500, 35, BLACK);
	//DrawText(TextFormat("y: %f", allLane[0]._screenPos.y), 1000, 300, 35, BLACK);
	if (GuiLabelButton({ 1150, 100, 100, 50 }, "NEXT"))
		nextButton = true;
	if (GuiLabelButton({ 1050, 100, 100, 50 }, "BACK"))
		backButton = true;
}

