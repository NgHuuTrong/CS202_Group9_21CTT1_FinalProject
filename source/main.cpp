#include "../header/game.h"

int main()
{
	InitWindow(1280, 720, "Game");
	SetTargetFPS(60);
	Game game;
	while (!WindowShouldClose())
	{
		game.run();
	}
	CloseWindow();
	return 0;
}