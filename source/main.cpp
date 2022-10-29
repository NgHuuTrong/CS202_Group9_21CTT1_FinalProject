#include <iostream>
#include <raylib.h>


int main()
{
	InitWindow(800, 600, "Game");
	SetTargetFPS(60);
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawText("Game Bang Qua Duong", 350, 250, 30, BLACK);
		EndDrawing();
	}
	CloseWindow();
	return 0;
}