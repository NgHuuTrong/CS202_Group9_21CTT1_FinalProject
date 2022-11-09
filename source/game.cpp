#define _CRT_SECURE_NO_WARNINGS
#define RAYGUI_IMPLEMENTATION
#include "../header/game.h"


Game::Game()
{
	GuiLoadStyle("data/style.rgs");
	font = LoadFont("data/font.ttf");
	GuiSetStyle(BUTTON, BORDER_WIDTH, 5);
	GuiSetFont(font);
}

Game::~Game()
{
	UnloadFont(font);
}

void Game::run()
{
	BeginDrawing();
	ClearBackground(RAYWHITE);
	home.draw();
	EndDrawing();
}