#include "../header/Program.h"

void loadAllTextures();

int main()
{
	InitWindow(1280, 720, "Game");
	SetTargetFPS(60);
	
	loadAllTextures();
	Program program; 

	while (!WindowShouldClose())
	{
		program.run();
		if (program.isExit) break;
	}
	CloseWindow();
	return 0;
}

void loadAllTextures() {
	TextureHolder::getHolder().load(Textures::GAMERIGHT, "data/gameMenuRight.png");
	TextureHolder::getHolder().load(Textures::PAVEMENT, "data/pavement.png");
	TextureHolder::getHolder().load(Textures::ROAD, "data/road.png");
	TextureHolder::getHolder().load(Textures::REDCAR_LEFT, "data/redcar_left.png");
	TextureHolder::getHolder().load(Textures::REDCAR_RIGHT, "data/redcar_right.png");
	TextureHolder::getHolder().load(Textures::BLUECAR_LEFT, "data/bluecar_left.png");
	TextureHolder::getHolder().load(Textures::BLUECAR_RIGHT, "data/bluecar_right.png");
	TextureHolder::getHolder().load(Textures::AMBULANCE_LEFT, "data/ambulance_left.png");
	TextureHolder::getHolder().load(Textures::AMBULANCE_RIGHT, "data/ambulance_right.png");
	TextureHolder::getHolder().load(Textures::RESTART_BTN, "data/restartButton.png");
	TextureHolder::getHolder().load(Textures::PAUSE_BTN, "data/pauseButton.png");
	TextureHolder::getHolder().load(Textures::MUSIC_BTN, "data/musicButton.png");
	TextureHolder::getHolder().load(Textures::RESUME_BTN, "data/resumeButton.png");
	TextureHolder::getHolder().load(Textures::HOME_BTN, "data/homeButton.png");
	TextureHolder::getHolder().load(Textures::NEXT_BTN, "data/nextLevelButton.png");
	TextureHolder::getHolder().load(Textures::BLUR_BG, "data/Blur.png");
	TextureHolder::getHolder().load(Textures::HOME_BG, "data/homeBackground.png");
	TextureHolder::getHolder().load(Textures::INS_BG_1, "data/Instruction1.png");
	TextureHolder::getHolder().load(Textures::INS_BG_2, "data/Instruction2.png");
	TextureHolder::getHolder().load(Textures::RANK_BG, "data/rankBackground.png");
	TextureHolder::getHolder().load(Textures::RANK_IMG, "data/rankingImage1.png");
	TextureHolder::getHolder().load(Textures::PAUSE_MENU, "data/pauseMenu.png");
	TextureHolder::getHolder().load(Textures::VICTORY_MENU, "data/victoryMenu.png");
	TextureHolder::getHolder().load(Textures::CHAR_FRONT_1, "data/characterAnimation/Front1.png");
	TextureHolder::getHolder().load(Textures::CHAR_FRONT_2, "data/characterAnimation/Front2.png");
	TextureHolder::getHolder().load(Textures::CHAR_FRONT_3, "data/characterAnimation/Front3.png");
	TextureHolder::getHolder().load(Textures::CHAR_FRONT_4, "data/characterAnimation/Front4.png");
	TextureHolder::getHolder().load(Textures::CHAR_BACK_1, "data/characterAnimation/Back1.png");
	TextureHolder::getHolder().load(Textures::CHAR_BACK_2, "data/characterAnimation/Back2.png");
	TextureHolder::getHolder().load(Textures::CHAR_BACK_3, "data/characterAnimation/Back3.png");
	TextureHolder::getHolder().load(Textures::CHAR_BACK_4, "data/characterAnimation/Back4.png");
	TextureHolder::getHolder().load(Textures::CHAR_LEFT_1, "data/characterAnimation/Left1.png");
	TextureHolder::getHolder().load(Textures::CHAR_LEFT_2, "data/characterAnimation/Left2.png");
	TextureHolder::getHolder().load(Textures::CHAR_LEFT_3, "data/characterAnimation/Left3.png");
	TextureHolder::getHolder().load(Textures::CHAR_LEFT_4, "data/characterAnimation/Left4.png");
	TextureHolder::getHolder().load(Textures::CHAR_RIGHT_1, "data/characterAnimation/Right1.png");
	TextureHolder::getHolder().load(Textures::CHAR_RIGHT_2, "data/characterAnimation/Right2.png");
	TextureHolder::getHolder().load(Textures::CHAR_RIGHT_3, "data/characterAnimation/Right3.png");
	TextureHolder::getHolder().load(Textures::CHAR_RIGHT_4, "data/characterAnimation/Right4.png");
}