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
		if (program.isExit)
			break;
	}
	CloseWindow();
	return 0;
}

void loadAllTextures()
{
	TextureHolder::getHolder().load(Textures::GAMERIGHT, "data/gameMenuRight.png");
	TextureHolder::getHolder().load(Textures::PAVEMENT, "data/pavement.png");
	TextureHolder::getHolder().load(Textures::ROAD, "data/road.png");
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
	TextureHolder::getHolder().load(Textures::GREEN_LIGHT, "data/green_light.png");
	TextureHolder::getHolder().load(Textures::YELLOW_LIGHT, "data/yellow_light.png");
	TextureHolder::getHolder().load(Textures::RED_LIGHT, "data/red_light.png");
	TextureHolder::getHolder().load(Textures::YCAR_FRAME_1, "data/ycar/1.png");
	TextureHolder::getHolder().load(Textures::YCAR_FRAME_2, "data/ycar/2.png");
	TextureHolder::getHolder().load(Textures::YCAR_FRAME_3, "data/ycar/3.png");
	TextureHolder::getHolder().load(Textures::YCAR_FRAME_4, "data/ycar/4.png");
	TextureHolder::getHolder().load(Textures::YCAR_FRAME_5, "data/ycar/5.png");
	TextureHolder::getHolder().load(Textures::YCAR_FRAME_6, "data/ycar/6.png");
	TextureHolder::getHolder().load(Textures::YCAR_FRAME_7, "data/ycar/7.png");
	TextureHolder::getHolder().load(Textures::YCAR_FRAME_8, "data/ycar/8.png");
	TextureHolder::getHolder().load(Textures::YCAR_FRAME_9, "data/ycar/9.png");
	TextureHolder::getHolder().load(Textures::PCAR_FRAME_1, "data/pcar/1.png");
	TextureHolder::getHolder().load(Textures::PCAR_FRAME_2, "data/pcar/2.png");
	TextureHolder::getHolder().load(Textures::PCAR_FRAME_3, "data/pcar/3.png");
	TextureHolder::getHolder().load(Textures::PCAR_FRAME_4, "data/pcar/4.png");
	TextureHolder::getHolder().load(Textures::PCAR_FRAME_5, "data/pcar/5.png");
	TextureHolder::getHolder().load(Textures::PCAR_FRAME_6, "data/pcar/6.png");
	TextureHolder::getHolder().load(Textures::PCAR_FRAME_7, "data/pcar/7.png");
	TextureHolder::getHolder().load(Textures::PCAR_FRAME_8, "data/pcar/8.png");
	TextureHolder::getHolder().load(Textures::PCAR_FRAME_9, "data/pcar/9.png");
	TextureHolder::getHolder().load(Textures::BUS_FRAME_1, "data/bus/1.png");
	TextureHolder::getHolder().load(Textures::BUS_FRAME_2, "data/bus/2.png");
	TextureHolder::getHolder().load(Textures::BUS_FRAME_3, "data/bus/3.png");
	TextureHolder::getHolder().load(Textures::BUS_FRAME_4, "data/bus/4.png");
	TextureHolder::getHolder().load(Textures::BUS_FRAME_5, "data/bus/5.png");
	TextureHolder::getHolder().load(Textures::BUS_FRAME_6, "data/bus/6.png");
	TextureHolder::getHolder().load(Textures::BUS_FRAME_7, "data/bus/7.png");
	TextureHolder::getHolder().load(Textures::BUS_FRAME_8, "data/bus/8.png");
	TextureHolder::getHolder().load(Textures::BUS_FRAME_9, "data/bus/9.png");
	TextureHolder::getHolder().load(Textures::BUS_FRAME_10, "data/bus/10.png");
	TextureHolder::getHolder().load(Textures::BUS_FRAME_11, "data/bus/11.png");
	TextureHolder::getHolder().load(Textures::BUS_FRAME_12, "data/bus/12.png");
	TextureHolder::getHolder().load(Textures::BUS_FRAME_13, "data/bus/13.png");
	TextureHolder::getHolder().load(Textures::POLICE_1, "data/police/1.png");
	TextureHolder::getHolder().load(Textures::POLICE_2, "data/police/2.png");
	TextureHolder::getHolder().load(Textures::POLICE_3, "data/police/3.png");
	TextureHolder::getHolder().load(Textures::POLICE_4, "data/police/4.png");
	TextureHolder::getHolder().load(Textures::POLICE_5, "data/police/5.png");
	TextureHolder::getHolder().load(Textures::POLICE_6, "data/police/6.png");
	TextureHolder::getHolder().load(Textures::POLICE_7, "data/police/7.png");
	TextureHolder::getHolder().load(Textures::POLICE_8, "data/police/8.png");
	TextureHolder::getHolder().load(Textures::POLICE_9, "data/police/9.png");
}