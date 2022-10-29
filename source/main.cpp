#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <raylib.h>
#define RAYGUI_IMPLEMENTATION
#include "../header/raygui.h"

int main()
{
	InitWindow(1000, 600, "Game");
	SetTargetFPS(60);
	GuiSetStyle(DEFAULT, TEXT_SIZE, 25);
	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(RAYWHITE);
		if (GuiButton({ 100,100,100,60 }, "Button"))
		{
			DrawText("Test Button", 350, 150, 30, RED);
		}
		DrawText("Game Bang Qua Duong", 350, 250, 30, BLACK);
		EndDrawing();
	}
	CloseWindow();
	return 0;
}