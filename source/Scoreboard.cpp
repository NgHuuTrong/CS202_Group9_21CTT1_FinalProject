#include "../header/Scoreboard.h"
#include "../header/raygui.h"
Scoreboard::Scoreboard()
{
	rankBackground = LoadTexture("data/rankBackground.png");
	rankImage = LoadTexture("data/rankingImage1.png");
	backButton = false;
}
Scoreboard::~Scoreboard() {
	UnloadTexture(rankBackground);
	UnloadTexture(rankImage);
}
Screen Scoreboard::update() {
	if (backButton) {
		backButton = false;
		return HOME;
	}
	return HIGHSCORE;
}
void Scoreboard::draw() {	
	DrawTextureRec(rankBackground, { 0,0,1280,720 }, { 0,0 }, WHITE);
	float xPos = (rankBackground.width - rankImage.width) / 2.0;
	float yPos = (rankBackground.height - rankImage.height) / 2.0;
	DrawTextureV(rankImage, { xPos,yPos }, WHITE);
	if (GuiLabelButton({ 15, 15, 100, 50 }, "BACK"))
		backButton = true;
	//DrawTextureRec(rankImage, { 0,0,(float)rankImage.width, (float)rankBackground.height }, { 0,0 }, WHITE);
}