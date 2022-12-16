#include "../header/Home.h"
#include "../header/raygui.h"

Home::Home()
{
	homeBackground = LoadTexture("data/homeBackground.png");
	mode = 0;
}

Screen Home::update()
{
	if (mode)
	{
		if (mode == 1)
		{
			allLane.clear();
		}
		else if (mode == 2)
			mode = 1;
		int tmp = mode;
		mode = 0;
		return static_cast<Screen>(tmp);
	}
	else
		return HOME;
}

void Home::draw()
{
	DrawTexture(homeBackground, 0, 0, WHITE);
	if (allLane.size())
		if (GuiButton({500, 150, 280, 70}, "CONTINUE"))
			mode = 2;
	if (GuiButton({500, 230, 280, 70}, "PLAY GAME"))
		mode = 1;
	if (GuiButton({500, 310, 280, 70}, "HIGHSCORE"))
		mode = 3;
	if (GuiButton({500, 390, 280, 70}, "INSTRUCTION"))
		mode = 4;
	GuiButton({500, 470, 280, 70}, "EXIT");
}

Home::~Home()
{
	UnloadTexture(homeBackground);
}