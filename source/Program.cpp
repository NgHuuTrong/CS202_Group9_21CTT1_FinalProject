#define _CRT_SECURE_NO_WARNINGS
#define RAYGUI_IMPLEMENTATION
#include "../header/Program.h"
#include "../header/raygui.h"


Program::Program()
{
	GuiLoadStyle("data/style.rgs");
	font = LoadFont("data/font.ttf");
	GuiSetStyle(BUTTON, BORDER_WIDTH, 6);
	GuiSetFont(font);
	screen = HOME;
}

Program::~Program()
{
	UnloadFont(font);
}

void Program::run()
{
	switch (screen)
	{
	case HOME:
		screen = home.update();
		break;
	case GAME:
		screen = game.update();
		break;
	}
	BeginDrawing();
	ClearBackground(RAYWHITE);
	switch (screen)
	{
	case HOME:
		home.draw();
		break;
	case GAME:
		game.draw();
		break;
	}
	EndDrawing();
}