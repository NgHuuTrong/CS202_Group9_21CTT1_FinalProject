#include "../header/Program.h"

int main()
{
	InitWindow(1280, 720, "Game");
	SetTargetFPS(60);
	Program program;
	while (!WindowShouldClose())
	{
		program.run();
	}
	CloseWindow();
	return 0;
}