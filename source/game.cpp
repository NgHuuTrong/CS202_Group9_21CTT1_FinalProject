#include "../header/Game.h"
#include "../header/raygui.h"

Game::Game()
{
	charAnim = std::vector<std::vector<Texture2D*>>(4, std::vector<Texture2D*>(4));
	for (int i = 0; i < 4; i++)
	{
		charAnim[0][i] = &TextureHolder::getHolder().get((Textures::ID)(i + 22));
		charAnim[1][i] = &TextureHolder::getHolder().get((Textures::ID)(i + 26));
		charAnim[2][i] = &TextureHolder::getHolder().get((Textures::ID)(i + 30));
		charAnim[3][i] = &TextureHolder::getHolder().get((Textures::ID)(i + 34));
	}
	player = Player("Test Name");
	gameRight = &TextureHolder::getHolder().get(Textures::GAMERIGHT);
	pavement = &TextureHolder::getHolder().get(Textures::PAVEMENT);
	road = &TextureHolder::getHolder().get(Textures::ROAD);
	redcar_left = &TextureHolder::getHolder().get(Textures::REDCAR_LEFT);
	redcar_right = &TextureHolder::getHolder().get(Textures::REDCAR_RIGHT);
	bluecar_left = &TextureHolder::getHolder().get(Textures::BLUECAR_LEFT);
	bluecar_right = &TextureHolder::getHolder().get(Textures::BLUECAR_RIGHT);
	ambulance_left = &TextureHolder::getHolder().get(Textures::AMBULANCE_LEFT);
	ambulance_right = &TextureHolder::getHolder().get(Textures::AMBULANCE_RIGHT);
	restart_button = &TextureHolder::getHolder().get(Textures::RESTART_BTN);
	pause_button = &TextureHolder::getHolder().get(Textures::PAUSE_BTN);
	music_button = &TextureHolder::getHolder().get(Textures::MUSIC_BTN);
	resume_button = &TextureHolder::getHolder().get(Textures::RESUME_BTN);
	home_button = &TextureHolder::getHolder().get(Textures::HOME_BTN);
	next_button = &TextureHolder::getHolder().get(Textures::NEXT_BTN);
	blurImage = &TextureHolder::getHolder().get(Textures::BLUR_BG);
	pauseMenu = &TextureHolder::getHolder().get(Textures::PAUSE_MENU);
	victoryMenu = &TextureHolder::getHolder().get(Textures::VICTORY_MENU);
	red_light = &TextureHolder::getHolder().get(Textures::RED_LIGHT);
	green_light = &TextureHolder::getHolder().get(Textures::GREEN_LIGHT);
	yellow_light = &TextureHolder::getHolder().get(Textures::YELLOW_LIGHT);
	backButton = nextButton = false;
	startTime = 0;
	pauseState = false;
	isWin = false;
}

Game::~Game()
{
	
}

Screen Game::update()
{
	if (isWin || pauseState)
	{
		startTime = 0;
		player.timeIncrease(playTime);
		playTime = 0;
		return GAME;
	}
	if (!allLane.size())
	{
		allLane = random(1);
		player.setScreenRec({ 426, 0, 44, 59 });
		player.setTime(0);
		player.setCurdirection(0);
	}
	if (startTime == 0)
	{
		startTime = GetTime();
	}
	playTime = GetTime() - startTime;
	for (int i = 0; i < (int)allLane.size(); i++)
	{
		for (int j = 0; j < (int)allLane[i].getObstacles().size(); ++j)
		{
			if (this->CheckCollision(player, allLane[i].getObstacles()[j]))
			{
				startTime = 0;
				allLane.clear();
				return HOME;
			}
		}
	}
	if (player.getScreenRec().y > allLane[allLane.size() - 1].getScreenPos().y)
	{
		isWin = true;
	}
	if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))
	{
		player.setCurdirection(0);
		player.setIsMoving(true);
		if (player.getScreenRec().y + 65 < 720)
			player.moveScreenRecY(5);
	}
	else if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))
	{
		player.setCurdirection(1);
		player.setIsMoving(true);
		if (player.getScreenRec().y - 5 > 0)
			player.moveScreenRecY(-5);
	}
	else if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
	{
		player.setCurdirection(2);
		player.setIsMoving(true);
		if (player.getScreenRec().x - 5 > 0)
			player.moveScreenRecX(-5);
	}
	else if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
	{
		player.setCurdirection(3);
		player.setIsMoving(true);
		if (player.getScreenRec().x + 44 < 960)
			player.moveScreenRecX(5);
	}
	if (GetMouseWheelMove() == -1 && allLane[allLane.size() - 1].getScreenPos().y > 720 - pavement->height)
	{
		for (int i = 0; i < (int)allLane.size(); i++)
		{
			allLane[i].setScreenPos({0, -45});
		}
		player.moveScreenRecY(-45);
	}
	if (GetMouseWheelMove() == 1 && allLane[0].getScreenPos().y < 0)
	{
		for (int i = 0; i < (int)allLane.size(); i++)
		{
			allLane[i].setScreenPos({0, 45});
		}
		player.moveScreenRecY(45);
	}
	

	if (backButton)
	{
		startTime = 0;
		player.timeIncrease(playTime);
		backButton = false;
		return HOME;
	}
	if (nextButton)
	{
		player.setCurdirection(0);
		player.setScreenRec({426, 0, 44, 59});
		startTime = 0;
		player.timeIncrease(playTime);
		nextButton = false;
		int level = allLane[0].getLevel() + 1;
		allLane.clear();
		allLane = random(level);
	}
	return GAME;
}

void Game::draw()
{
	if (!allLane.size())
		return;
	for (Lane l : allLane)
	{
		if (l.getLaneType() == PAVEMENT)
			DrawTextureRec(*pavement, l.getSrcRec(), l.getScreenPos(), WHITE);
		else if (l.getLaneType() == ROAD)
			DrawTextureRec(*road, l.getSrcRec(), l.getScreenPos(), WHITE);
		if (l.getIsTraffic())
		{
			if (l.getLight() == RED_LIGHT)
			{
				DrawTexture(*red_light, 930, l.getScreenPos().y, WHITE);
			}
			else if (l.getLight() == GREEN_LIGHT)
			{
				DrawTexture(*green_light, 930, l.getScreenPos().y, WHITE);
			}
			else if (l.getLight() == YELLOW_LIGHT)
			{
				DrawTexture(*yellow_light, 930, l.getScreenPos().y, WHITE);
			}
		}
	}
	renderAllLane();
	DrawRectangleLinesEx({ 0, 0, 960, 720 }, 3, BLACK);
	drawPlayerState();
	DrawRectangleRec({ 961, 0, 1280 - 961, 720 }, RAYWHITE);

	//DrawRectangleRec({ 961, 0, 1280 - 961, 720 }, RAYWHITE);
	DrawTexture(*gameRight, 961, 0, RAYWHITE);
	DrawText("123", 1160, 147, 32, DARKGRAY);
	DrawText("234", 1160, 228, 32, DARKGRAY);
	player.setTime(playTime + player.getTime());
	DrawText(TextFormat("%.0f", player.calHighScore()), 1160, 316, 32, DARKGRAY);
	DrawText(TextFormat("%.2f", player.getTime()), 1160, 395, 32, DARKGRAY);
	Vector2 getMouse = GetMousePosition();
	int restartX = 1000, restartY = 600, pauseX = 1100, pauseY = 600, musicX = 1200, musicY = 600;
	if (getMouse.x >= restartX && getMouse.x <= restartX + restart_button->width && getMouse.y >= restartY && getMouse.y <= restartY + restart_button->height)
	{
		DrawTexture(*restart_button, restartX, restartY, RED);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
		}
	}
	else
	{
		DrawTexture(*restart_button, restartX, restartY, RAYWHITE);
	}

	if (getMouse.x >= pauseX && getMouse.x <= pauseX + pause_button->width && getMouse.y >= pauseY && getMouse.y <= pauseY + pause_button->height)
	{
		DrawTexture(*pause_button, pauseX, pauseY, RED);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			pauseState = true;
		}
	}
	else
	{
		DrawTexture(*pause_button, pauseX, pauseY, RAYWHITE);
	}

	if (getMouse.x >= musicX && getMouse.x <= musicX + music_button->width && getMouse.y >= musicY && getMouse.y <= musicY + music_button->height)
	{
		DrawTexture(*music_button, musicX, musicY, RED);
	}
	else
		DrawTexture(*music_button, musicX, musicY, RAYWHITE);


	//DrawRectangleRec({ 961, 0, 1280 - 961, 720 }, RAYWHITE);
	//DrawText(TextFormat("Time: %.2f", playTime + player.getTime()), 1030, 500, 35, BLACK);
	if (GuiLabelButton({ 1150, 100, 100, 50 }, "NEXT"))
		nextButton = true;
	if (GuiLabelButton({ 1050, 100, 100, 50 }, "BACK"))
		backButton = true;

	if (pauseState == true) {
		float pauseMenuX = 640 - pauseMenu->width / 2;
		float pauseMenuY = 360 - pauseMenu->height / 2;
		DrawTexture(*blurImage, 0, 0, CLITERAL(Color){ 255, 255, 255, 200 });
		DrawTexture(*pauseMenu, pauseMenuX, pauseMenuY, RAYWHITE);
		float resumeButtonX = pauseMenuX + pauseMenu->width / 4 - resume_button->width / 2;
		float resumeButtonY = pauseMenuY + 170;
		float homeButtonX = pauseMenuX + 3 * pauseMenu->width / 4 - home_button->width / 2;
		float homeButtonY = pauseMenuY + 170;
		Vector2 mousePos = GetMousePosition();
		if (mousePos.x >= resumeButtonX && mousePos.x <= resumeButtonX + resume_button->width && mousePos.y >= resumeButtonY && mousePos.y <= resumeButtonY + resume_button->height) {
			DrawTexture(*resume_button, resumeButtonX, resumeButtonY, RED);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
				pauseState = false;
			}
		}
		else DrawTexture(*resume_button, resumeButtonX, resumeButtonY, RAYWHITE);

		if (mousePos.x >= homeButtonX && mousePos.x <= homeButtonX + home_button->width && mousePos.y >= homeButtonY && mousePos.y <= homeButtonY + home_button->height) {
			DrawTexture(*home_button, homeButtonX, homeButtonY, RED);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
				pauseState = false;
				backButton = true;
			}
		}
		else DrawTexture(*home_button, homeButtonX, homeButtonY, RAYWHITE);
	}
	if (isWin == true) {
		float victoryMenuX = 640 - victoryMenu->width / 2;
		float victoryMenuY = 360 - victoryMenu->height / 2;
		DrawTexture(*blurImage, 0, 0, CLITERAL(Color){ 255, 255, 255, 200 });
		DrawTexture(*victoryMenu, victoryMenuX, victoryMenuY, RAYWHITE);
		float nextButtonX = victoryMenuX + victoryMenu->width / 4 - next_button->width / 2;
		float nextButtonY = victoryMenuY + 150;
		float homeButtonX = victoryMenuX + 3 * victoryMenu->width / 4 - home_button->width / 2;
		float homeButtonY = victoryMenuY + 150;
		Vector2 mousePos = GetMousePosition();
		if (mousePos.x >= nextButtonX && mousePos.x <= nextButtonX + next_button->width && mousePos.y >= nextButtonY && mousePos.y <= nextButtonY + next_button->height) {
			DrawTexture(*next_button, nextButtonX, nextButtonY, RED);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
				player.setScreenRec({ 426, 0, 44, 59 });
				isWin = false;
				nextButton = true;
				pauseState = false;
			}
		}
		else DrawTexture(*next_button, nextButtonX, nextButtonY, RAYWHITE);

		if (mousePos.x >= homeButtonX && mousePos.x <= homeButtonX + home_button->width && mousePos.y >= homeButtonY && mousePos.y <= homeButtonY + home_button->height) {
			DrawTexture(*home_button, homeButtonX, homeButtonY, RED);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
				isWin = false;
				pauseState = false;
				backButton = true;
			}
		}
		else DrawTexture(*home_button, homeButtonX, homeButtonY, RAYWHITE);

		DrawText("Current Score: ", victoryMenuX + 50, victoryMenuY + 330, 55, DARKGRAY);
		DrawText("2000", victoryMenuX + 600, victoryMenuY + 333, 55, ORANGE);	
	}
}

void Game::drawPlayerState()
{
	player.render(charAnim);
}

bool Game::CheckCollision(Player& p, Obstacle  &ob)
{
	Rectangle temp1 = ob.getScreenRec();
	Rectangle temp2 = player.getScreenRec();
	temp1.y = allLane[ob.getInLane()].getScreenPos().y + 15;
	temp2.y += temp2.height * 4 / 5;
	temp2.height /= 5;
	switch (ob.getType())
	{
		case REDCAR:
			temp1.width = (float)redcar_left->width;
			temp1.height = (float)(redcar_left->height);
			break;
		case BLUECAR:
			temp1.width = (float)bluecar_left->width;
			temp1.height = (float)bluecar_left->height;
			break;
		case AMBULANCE:
			temp1.width = (float)ambulance_left->width;
			temp1.height = (float)ambulance_right->height;
			break;
		default:
			break;
	}
	temp1.y += temp1.height * 0.5;
	temp1.height /= 2;
	if (CheckCollisionRecs(temp2, temp1))
	{
		return true;
	}
	return false;
}
