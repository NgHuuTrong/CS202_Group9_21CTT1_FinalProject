#include "../header/Scoreboard.h"
#include "../header/raygui.h"
Scoreboard::Scoreboard()
{
	rankBackground = &TextureHolder::getHolder().get(Textures::RANK_BG);
	rankImage = &TextureHolder::getHolder().get(Textures::RANK_IMG);
	backButton = false;
}
Scoreboard::~Scoreboard()
{
}

Screen Scoreboard::update()
{
	if (backButton)
	{
		backButton = false;
		return HOME;
	}
	return HIGHSCORE;
}
void Scoreboard::draw()
{
	DrawTextureRec(*rankBackground, {0, 0, 1280, 720}, {0, 0}, WHITE);
	float xPos = (rankBackground->width - rankImage->width) / 2.0;
	float yPos = (rankBackground->height - rankImage->height) / 2.0;
	DrawTextureV(*rankImage, {xPos, yPos}, WHITE);
	if (GuiLabelButton({15, 15, 100, 50}, "BACK"))
		backButton = true;
	// DrawTextureRec(rankImage, { 0,0,(float)rankImage.width, (float)rankBackground.height }, { 0,0 }, WHITE);
}