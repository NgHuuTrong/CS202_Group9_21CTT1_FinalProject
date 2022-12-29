#include "../header/Home.h"
#include "../header/raygui.h"
#include "../header/Player.h"

Home::Home()
{
	homeBackground = &TextureHolder::getHolder().get(Textures::HOME_BG);
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
	DrawTexture(*homeBackground, 0, 0, WHITE);
	float posX = 150;
	if (allLane.size())
		if (GuiButton({510, posX, 280, 65}, "CONTINUE"))
			mode = 2;
	if (GuiButton({510, posX + 75, 280, 65}, "PLAY GAME"))
		mode = 1;
	if (GuiButton({ 510, posX + 300, 280, 65 }, "LOG OUT"))
	{
		mode = 3;
		for (int i = 0; i < listPlayer.size(); i++)
		{
			if (listPlayer[i].getName() == curPlayer.getName())
			{
				listPlayer[i] = curPlayer;
				break;
			}
		}
	}
	if (GuiButton({510, posX + 225 , 280, 65}, "HIGHSCORE"))
		mode = 4;
	if (GuiButton({ 510, posX + 150, 280, 65 }, "INSTRUCTION"))
		mode = 5;
	if (GuiButton({510, posX + 375, 280, 65}, "EXIT")) 
		mode = 6;
}

Home::~Home()
{
}