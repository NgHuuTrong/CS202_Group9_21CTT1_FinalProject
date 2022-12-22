#define _CRT_SECURE_NO_WARNINGS
#define RAYGUI_IMPLEMENTATION
#include "../header/Program.h"
#include "../header/raygui.h"

Program::Program()
{
	// loadAllTextures();
	GuiLoadIcons("data/arrow.rgi", true);
	GuiLoadStyle("data/style.rgs");
	font = LoadFont("data/font.ttf");
	GuiSetStyle(BUTTON, BORDER_WIDTH, 6);
	GuiSetFont(font);
	screen = HOME;
}

Program::~Program()
{
	UnloadFont(font);
}

void Program::run()
{
	switch (screen)
	{
	case HOME:
		screen = home.update();
		break;
	case GAME:
		screen = game.update();
		break;
	case HIGHSCORE:
		screen = scoreboard.update();
		break;
	case INSTRUCTION:
		screen = instruction.update();
		break;
	case EXIT:
		isExit = 1;
		break;
	}
	BeginDrawing();
	ClearBackground(RAYWHITE);
	switch (screen)
	{
	case HOME:
		home.draw();
		break;
	case GAME:
		game.draw();
		break;
	case HIGHSCORE:
		scoreboard.draw();
		break;
	case INSTRUCTION:
		instruction.draw();
		break;
	}
	EndDrawing();
}

void Program::loadAllTextures() {
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
}