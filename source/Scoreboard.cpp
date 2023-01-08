#include "../header/Scoreboard.h"
#include "../header/raygui.h"
Scoreboard::Scoreboard()
{
	rankBackground = &TextureHolder::getHolder().get(Textures::RANK_BG);
	rankImage = &TextureHolder::getHolder().get(Textures::RANK_IMG);
	rankImageX = (rankBackground->width - rankImage->width) / 2.0;
	rankImageY = (rankBackground->height - rankImage->height) / 2.0;
	nameX = rankImageX + 60;
	levelX = rankImageX + 275;
	timeX = rankImageX + 485;
	scoreX = rankImageX + 700;
	for (int i = 0; i < 5; i++) {
		posY[i] = rankImageY + 150 + 80 * (i + 1);
	}
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
	DrawTextureV(*rankImage, {rankImageX, rankImageY}, WHITE);
	for (int i = 0; i < 5; i++) {
		DrawText(listPlayer[i].getName().c_str(), nameX, posY[i], 30, DARKGRAY);
		DrawText(TextFormat("%i", listPlayer[i].getBestLevel()), levelX, posY[i], 30, DARKGRAY);
		DrawText(TextFormat("%.2lf", listPlayer[i].getBestTime()), timeX, posY[i], 30, DARKGRAY);
		DrawText(TextFormat("%i", listPlayer[i].getBestScore()), scoreX, posY[i], 30, DARKGRAY);
	}
	if (GuiLabelButton({15, 15, 100, 50}, "BACK"))
		backButton = true;
}


