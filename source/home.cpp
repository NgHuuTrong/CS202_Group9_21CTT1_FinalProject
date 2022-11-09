#include "../header/home.h"

Home::Home()
{
	homeBackground = LoadTexture("data/homeBackground.png");
}


void Home::draw()
{
	DrawTextureEx(homeBackground, { 0, 0 }, 0, 2.0 / 3, WHITE);
	GuiButton({ 300, 200, 270, 60 }, "PLAY GAME");
}

Home::~Home()
{
	UnloadTexture(homeBackground);
}