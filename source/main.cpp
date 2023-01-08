#include "../header/Program.h"

void loadAllTextures();

int main()
{
	InitWindow(1280, 720, "Game");
	SetTargetFPS(60);
	loadAllPlayer();
	loadAllTextures();
	sortListPlayer();
	/*for (int i = 0; i < listPlayer.size(); i++) {
		std::cout << listPlayer[i].getName() << std::endl
			<< listPlayer[i].getLevel() << std::endl
			<< listPlayer[i].getTime() << std::endl
			<< listPlayer[i].getScore() << std::endl;
	}*/
	/*for (int i = 0; i < 5; i++) {
		std::cout << listHighScore[i].getName() << std::endl;
		std::cout << listHighScore[i].getLevel() << std::endl;
		std::cout << listHighScore[i].getTime() << std::endl;
		std::cout << listHighScore[i].getScore() << std::endl;
	}*/
	Program program;

	while (!WindowShouldClose())
	{
		program.run();
		if (program.isExit)
			break;
	}
	sortListPlayer();
	saveAllPlayer();
	CloseWindow();
	return 0;
}

void loadAllTextures()
{
	TextureHolder::getHolder().load(Textures::PAVEMENT, "graphics/lanes/pavement.png");
	TextureHolder::getHolder().load(Textures::ROAD, "graphics/lanes/road.png");

	TextureHolder::getHolder().load(Textures::RESTART_BTN, "graphics/buttons/restartButton.png");
	TextureHolder::getHolder().load(Textures::PAUSE_BTN, "graphics/buttons/pauseButton.png");
	TextureHolder::getHolder().load(Textures::MUSIC_BTN, "graphics/buttons/musicButton.png");
	TextureHolder::getHolder().load(Textures::RESUME_BTN, "graphics/buttons/resumeButton.png");
	TextureHolder::getHolder().load(Textures::HOME_BTN, "graphics/buttons/homeButton.png");
	TextureHolder::getHolder().load(Textures::NEXT_BTN, "graphics/buttons/nextLevelButton.png");
	TextureHolder::getHolder().load(Textures::OK_BTN_1, "graphics/buttons/okButton.png");
	TextureHolder::getHolder().load(Textures::OK_BTN_2, "graphics/buttons/okButton2.png");

	TextureHolder::getHolder().load(Textures::GAMERIGHT, "graphics/background/gameMenuRight.png");
	TextureHolder::getHolder().load(Textures::BLUR_BG, "graphics/background/Blur.png");
	TextureHolder::getHolder().load(Textures::HOME_BG, "graphics/background/homeBackground.png");
	TextureHolder::getHolder().load(Textures::INS_BG_1, "graphics/background/Instruction1.png");
	TextureHolder::getHolder().load(Textures::INS_BG_2, "graphics/background/Instruction2.png");
	TextureHolder::getHolder().load(Textures::RANK_BG, "graphics/background/rankBackground.png");
	TextureHolder::getHolder().load(Textures::RANK_IMG, "graphics/background/rankingImage.png");
	TextureHolder::getHolder().load(Textures::PAUSE_MENU, "graphics/background/pauseMenu.png");
	TextureHolder::getHolder().load(Textures::VICTORY_MENU, "graphics/background/victoryMenu.png");
	TextureHolder::getHolder().load(Textures::LOSE_MENU, "graphics/background/loseMenu.png");
	TextureHolder::getHolder().load(Textures::LOGIN_BG, "graphics/background/loginBackground.png");
	TextureHolder::getHolder().load(Textures::PLAYER_BOX_1, "graphics/background/playerBox.png");
	TextureHolder::getHolder().load(Textures::PLAYER_BOX_2, "graphics/background/playerBox2.png");
	TextureHolder::getHolder().load(Textures::INPUT_BTN_1, "graphics/background/inputBox.png");
	TextureHolder::getHolder().load(Textures::INPUT_BTN_2, "graphics/background/inputBox2.png");
	TextureHolder::getHolder().load(Textures::LOAD_MENU, "graphics/background/loadingMenu.png");
	TextureHolder::getHolder().load(Textures::LOAD_BAR, "graphics/background/loadingBar.png");
	TextureHolder::getHolder().load(Textures::LOAD_ELE, "graphics/background/loadingEle.png");

	TextureHolder::getHolder().load(Textures::CHAR_FRONT_1, "graphics/characterAnimation/Front1.png");
	TextureHolder::getHolder().load(Textures::CHAR_FRONT_2, "graphics/characterAnimation/Front2.png");
	TextureHolder::getHolder().load(Textures::CHAR_FRONT_3, "graphics/characterAnimation/Front3.png");
	TextureHolder::getHolder().load(Textures::CHAR_FRONT_4, "graphics/characterAnimation/Front4.png");
	TextureHolder::getHolder().load(Textures::CHAR_BACK_1, "graphics/characterAnimation/Back1.png");
	TextureHolder::getHolder().load(Textures::CHAR_BACK_2, "graphics/characterAnimation/Back2.png");
	TextureHolder::getHolder().load(Textures::CHAR_BACK_3, "graphics/characterAnimation/Back3.png");
	TextureHolder::getHolder().load(Textures::CHAR_BACK_4, "graphics/characterAnimation/Back4.png");
	TextureHolder::getHolder().load(Textures::CHAR_LEFT_1, "graphics/characterAnimation/Left1.png");
	TextureHolder::getHolder().load(Textures::CHAR_LEFT_2, "graphics/characterAnimation/Left2.png");
	TextureHolder::getHolder().load(Textures::CHAR_LEFT_3, "graphics/characterAnimation/Left3.png");
	TextureHolder::getHolder().load(Textures::CHAR_LEFT_4, "graphics/characterAnimation/Left4.png");
	TextureHolder::getHolder().load(Textures::CHAR_RIGHT_1, "graphics/characterAnimation/Right1.png");
	TextureHolder::getHolder().load(Textures::CHAR_RIGHT_2, "graphics/characterAnimation/Right2.png");
	TextureHolder::getHolder().load(Textures::CHAR_RIGHT_3, "graphics/characterAnimation/Right3.png");
	TextureHolder::getHolder().load(Textures::CHAR_RIGHT_4, "graphics/characterAnimation/Right4.png");

	TextureHolder::getHolder().load(Textures::GREEN_LIGHT, "graphics/trafficlight/green_light.png");
	TextureHolder::getHolder().load(Textures::YELLOW_LIGHT, "graphics/trafficlight/yellow_light.png");
	TextureHolder::getHolder().load(Textures::RED_LIGHT, "graphics/trafficlight/red_light.png");

	TextureHolder::getHolder().load(Textures::YCAR_FRAME_1, "graphics/ycar/1.png");
	TextureHolder::getHolder().load(Textures::YCAR_FRAME_2, "graphics/ycar/2.png");
	TextureHolder::getHolder().load(Textures::YCAR_FRAME_3, "graphics/ycar/3.png");
	TextureHolder::getHolder().load(Textures::YCAR_FRAME_4, "graphics/ycar/4.png");
	TextureHolder::getHolder().load(Textures::YCAR_FRAME_5, "graphics/ycar/5.png");
	TextureHolder::getHolder().load(Textures::YCAR_FRAME_6, "graphics/ycar/6.png");
	TextureHolder::getHolder().load(Textures::YCAR_FRAME_7, "graphics/ycar/7.png");
	TextureHolder::getHolder().load(Textures::YCAR_FRAME_8, "graphics/ycar/8.png");
	TextureHolder::getHolder().load(Textures::YCAR_FRAME_9, "graphics/ycar/9.png");

	TextureHolder::getHolder().load(Textures::PCAR_FRAME_1, "graphics/pcar/1.png");
	TextureHolder::getHolder().load(Textures::PCAR_FRAME_2, "graphics/pcar/2.png");
	TextureHolder::getHolder().load(Textures::PCAR_FRAME_3, "graphics/pcar/3.png");
	TextureHolder::getHolder().load(Textures::PCAR_FRAME_4, "graphics/pcar/4.png");
	TextureHolder::getHolder().load(Textures::PCAR_FRAME_5, "graphics/pcar/5.png");
	TextureHolder::getHolder().load(Textures::PCAR_FRAME_6, "graphics/pcar/6.png");
	TextureHolder::getHolder().load(Textures::PCAR_FRAME_7, "graphics/pcar/7.png");
	TextureHolder::getHolder().load(Textures::PCAR_FRAME_8, "graphics/pcar/8.png");
	TextureHolder::getHolder().load(Textures::PCAR_FRAME_9, "graphics/pcar/9.png");

	TextureHolder::getHolder().load(Textures::BUS_FRAME_1, "graphics/bus/1.png");
	TextureHolder::getHolder().load(Textures::BUS_FRAME_2, "graphics/bus/2.png");
	TextureHolder::getHolder().load(Textures::BUS_FRAME_3, "graphics/bus/3.png");
	TextureHolder::getHolder().load(Textures::BUS_FRAME_4, "graphics/bus/4.png");
	TextureHolder::getHolder().load(Textures::BUS_FRAME_5, "graphics/bus/5.png");
	TextureHolder::getHolder().load(Textures::BUS_FRAME_6, "graphics/bus/6.png");
	TextureHolder::getHolder().load(Textures::BUS_FRAME_7, "graphics/bus/7.png");
	TextureHolder::getHolder().load(Textures::BUS_FRAME_8, "graphics/bus/8.png");
	TextureHolder::getHolder().load(Textures::BUS_FRAME_9, "graphics/bus/9.png");
	TextureHolder::getHolder().load(Textures::BUS_FRAME_10, "graphics/bus/10.png");
	TextureHolder::getHolder().load(Textures::BUS_FRAME_11, "graphics/bus/11.png");
	TextureHolder::getHolder().load(Textures::BUS_FRAME_12, "graphics/bus/12.png");
	TextureHolder::getHolder().load(Textures::BUS_FRAME_13, "graphics/bus/13.png");

	TextureHolder::getHolder().load(Textures::POLICE_1, "graphics/police/1.png");
	TextureHolder::getHolder().load(Textures::POLICE_2, "graphics/police/2.png");
	TextureHolder::getHolder().load(Textures::POLICE_3, "graphics/police/3.png");
	TextureHolder::getHolder().load(Textures::POLICE_4, "graphics/police/4.png");
	TextureHolder::getHolder().load(Textures::POLICE_5, "graphics/police/5.png");
	TextureHolder::getHolder().load(Textures::POLICE_6, "graphics/police/6.png");
	TextureHolder::getHolder().load(Textures::POLICE_7, "graphics/police/7.png");
	TextureHolder::getHolder().load(Textures::POLICE_8, "graphics/police/8.png");
	TextureHolder::getHolder().load(Textures::POLICE_9, "graphics/police/9.png");

	
}
