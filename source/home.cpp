#include "../header/Home.h"
#include "../header/raygui.h"

Home::Home()
{
	homeBackground = LoadTexture("data/homeBackground.png");
	mode = 0;
}

Screen Home::update()
{
	
}

void Home::draw()
{
	DrawTexture(homeBackground, 0, 0, WHITE);
	if (GuiButton({ 500, 150, 280, 70 }, "PLAY GAME"))
		mode = 1;
	GuiButton({ 500, 230, 280, 70 }, "CONTINUE");
	GuiButton({ 500, 310, 280, 70 }, "HIGHSCORE");
	GuiButton({ 500, 390, 280, 70 }, "INSTRUCTION");
	GuiButton({ 500, 470, 280, 70 }, "EXIT");
}

Home::~Home()
{
	UnloadTexture(homeBackground);
}