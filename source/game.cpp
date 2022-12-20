#include "../header/Game.h"
#include "../header/raygui.h"

Game::Game()
{
	std::string path = "data/characterAnimation/";
	for (int i = 0; i < 4; i++)
	{
		charAnim[0][i] = LoadTexture((path + "Front" + std::to_string(i + 1) + ".png").c_str());
		charAnim[1][i] = LoadTexture((path + "Back" + std::to_string(i + 1) + ".png").c_str());
		charAnim[2][i] = LoadTexture((path + "Left" + std::to_string(i + 1) + ".png").c_str());
		charAnim[3][i] = LoadTexture((path + "Right" + std::to_string(i + 1) + ".png").c_str());
	}
	player = Player("Test Name");
	pavement = LoadTexture("data/pavement.png");
	road = LoadTexture("data/road.png");
	redcar_left = LoadTexture("data/redcar_left.png");
	redcar_right = LoadTexture("data/redcar_right.png");
	bluecar_left = LoadTexture("data/bluecar_left.png");
	bluecar_right = LoadTexture("data/bluecar_right.png");
	ambulance_left = LoadTexture("data/ambulance_left.png");
	ambulance_right = LoadTexture("data/ambulance_right.png");
	restart_button = LoadTexture("data/restartButton.png");
	pause_button = LoadTexture("data/pauseButton.png");
	music_button = LoadTexture("data/musicButton.png"); 
	resume_button = LoadTexture("data/resumeButton.png");
	home_button = LoadTexture("data/homeButton.png");
	blurImage = LoadTexture("data/Blur.png");
	pauseMenu = LoadTexture("data/pauseMenu.png");
	backButton = nextButton = false;
	startTime = 0;
	pauseState = false;
}

Game::~Game()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			UnloadTexture(charAnim[i][j]);
		}
	}
	UnloadTexture(pavement);
	UnloadTexture(road);
	UnloadTexture(redcar_left);
	UnloadTexture(bluecar_left);
	UnloadTexture(ambulance_left);
	UnloadTexture(redcar_right);
	UnloadTexture(bluecar_right);
	UnloadTexture(ambulance_right);
	UnloadTexture(restart_button);
	UnloadTexture(pause_button);
	UnloadTexture(music_button);
	UnloadTexture(resume_button);
	UnloadTexture(home_button);
	UnloadTexture(blurImage);
}

Screen Game::update()
{
	if (!allLane.size())
	{
		allLane = random(1);
		// player.screenRec = { 426, 0, 44, 59 };
		player.setScreenRec({ 426, 0, 44, 59 });
		player.time = 0;
		player.curDirection = 0;
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
				std::cerr << "Collision" << std::endl;
			}
			// Rectangle temp = allLane[i].getObstacles()[j].getScreenRec();
			// temp.y = allLane[allLane[i].getObstacles()[j].getInLane()].getScreenPos().y + 15;
			// switch (allLane[i].getObstacles()[j].getType())
			// {
			// case REDCAR:
			// 	temp.width = (float)redcar_left.width;
			// 	temp.height = (float)(redcar_left.height);
			// 	break;
			// case BLUECAR:
			// 	temp.width = (float)bluecar_left.width;
			// 	temp.height = (float)bluecar_left.height;
			// 	break;
			// case AMBULANCE:
			// 	temp.width = (float)ambulance_left.width;
			// 	temp.height = (float)ambulance_right.height;
			// 	break;
			// default:
			// 	break;
			// }
			// if (CheckCollisionRecs(this->player.getScreenRec(), temp))
			// {
			// 	std::cout << "Collision" << std::endl;
			// 	break;
			// }
		}
	}
	if (IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN))
	{

		player.curDirection = 0;
		player.isMoving = true;
		if (player.getScreenRec().y + 65 < 720)
			player.moveScreenRecY(5);
			// player.screenRec.y += 5;
			// player.setScreenRec({ player.getScreenRec().x, player.getScreenRec().y + 5, player.getScreenRec().width, player.getScreenRec().height });
	}
	else if (IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))
	{

		player.curDirection = 1;
		player.isMoving = true;
		if (player.getScreenRec().y - 5 > 0)
			player.moveScreenRecY(-5);
			// player.screenRec.y -= 5;
			// player.setScreenRec({ player.getScreenRec().x, player.getScreenRec().y - 5, player.getScreenRec().width, player.getScreenRec().height });
	}
	else if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))
	{

		player.curDirection = 2;
		player.isMoving = true;
		if (player.getScreenRec().x - 5 > 0)
			player.moveScreenRecX(-5);
			// player.screenRec.x -= 5;
			// player.setScreenRec({ player.getScreenRec().x - 5, player.getScreenRec().y, player.getScreenRec().width, player.getScreenRec().height });
	}
	else if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
	{
		player.curDirection = 3;
		player.isMoving = true;
		if (player.getScreenRec().x + 44 < 960)
			player.moveScreenRecX(5);
			// player.screenRec.x += 5;
			// player.setScreenRec({ player.getScreenRec().x + 5, player.getScreenRec().y, player.getScreenRec().width, player.getScreenRec().height });
	}
	if (GetMouseWheelMove() == -1 && allLane[allLane.size() - 1].getScreenPos().y > 720 - pavement.height)
	{
		for (int i = 0; i < (int)allLane.size(); i++)
		{
			allLane[i].setScreenPos({0, -45});
		}
		player.moveScreenRecY(-45);
		// player.screenRec.y -= 45;
		// player.setScreenRec({ player.getScreenRec().x, player.getScreenRec().y - 45, player.getScreenRec().width, player.getScreenRec().height });
	}
	if (GetMouseWheelMove() == 1 && allLane[0].getScreenPos().y < 0)
	{
		for (int i = 0; i < (int)allLane.size(); i++)
		{
			allLane[i].setScreenPos({0, 45});
		}
		player.moveScreenRecX(45);
		// player.screenRec.y += 45;
		// player.setScreenRec({ player.getScreenRec().x, player.getScreenRec().y + 45, player.getScreenRec().width, player.getScreenRec().height });
	}
	

	if (backButton)
	{
		startTime = 0;
		player.time += playTime;
		backButton = false;
		return HOME;
	}
	if (nextButton)
	{
		player.curDirection = 0;
		// player.screenRec = {426, 0, 44, 59};
		player.setScreenRec({426, 0, 44, 59});
		startTime = 0;
		player.time += playTime;
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
			DrawTextureRec(pavement, l.getSrcRec(), l.getScreenPos(), WHITE);
		else if (l.getLaneType() == ROAD)
			DrawTextureRec(road, l.getSrcRec(), l.getScreenPos(), WHITE);
	}
	DrawRectangleLinesEx({ 0, 0, 960, 720 }, 3, BLACK);
	//DrawText(TextFormat("y: %f", allLane[0].getScreenPos().y), 1000, 300, 35, BLACK);
	drawPlayerState();
	for (int i = 0; i < allLane.size(); i++)
	{
		if (!allLane[i].getDirection())
		{
			for (int j = 0; j < allLane[i].getNumsOfObstacles(); j++)
			{
				// allLane[i].getObstacles()[j].moveScreenRecX(2);
				// allLane[i].getObstacles()[j].screenRec.x += velo;
				//allLane[i].getObstacles()[j].setScreenRec({ allLane[i].getObstacles()[j].getScreenRec().x + velo, allLane[i].getObstacles()[j].getScreenRec().y, allLane[i].getObstacles()[j].getScreenRec().width, allLane[i].getObstacles()[j].getScreenRec().height });
				allLane[i].setScreenRecX(allLane[i].getObstacles()[j].getScreenRec().x, j);
				
				if (allLane[i].getObstacles()[j].getType() == REDCAR)
					DrawTextureRec(redcar_left, { 0, 0, (float)redcar_left.width, float(redcar_left.height) }, { (float)allLane[i].getObstacles()[j].getScreenRec().x, allLane[allLane[i].getObstacles()[j].getInLane()].getScreenPos().y + 15 }, WHITE);
				if (allLane[i].getObstacles()[j].getType() == BLUECAR)
					DrawTextureRec(bluecar_left, { 0, 0, (float)bluecar_left.width, float(bluecar_left.height) }, { (float)allLane[i].getObstacles()[j].getScreenRec().x, allLane[allLane[i].getObstacles()[j].getInLane()].getScreenPos().y + 15 }, WHITE);
				if (allLane[i].getObstacles()[j].getType() == AMBULANCE)
					DrawTextureRec(ambulance_left, { 0, 0, (float)ambulance_left.width, float(ambulance_left.height) }, { (float)allLane[i].getObstacles()[j].getScreenRec().x, allLane[allLane[i].getObstacles()[j].getInLane()].getScreenPos().y + 15 }, WHITE);
			}
		}
		else
		{
			for (int j = 0; j < allLane[i].getNumsOfObstacles(); j++)
			{
				// allLane[i].getObstacles()[j].moveScreenRecX(-2);
				// allLane[i].getObstacles()[j].getScreenRec().x -= velo;
				// allLane[i].getObstacles()[j].setScreenRec({ allLane[i].getObstacles()[j].getScreenRec().x - velo, allLane[i].getObstacles()[j].getScreenRec().y, allLane[i].getObstacles()[j].getScreenRec().width, allLane[i].getObstacles()[j].getScreenRec().height });
				allLane[i].setScreenRecX(allLane[i].getObstacles()[j].getScreenRec().x, j);
				if (allLane[i].getObstacles()[j].getType() == REDCAR)
					DrawTextureRec(redcar_right, { 0, 0, (float)redcar_right.width, float(redcar_right.height) }, { (float)allLane[i].getObstacles()[j].getScreenRec().x, allLane[allLane[i].getObstacles()[j].getInLane()].getScreenPos().y + 15 }, WHITE);
				if (allLane[i].getObstacles()[j].getType() == BLUECAR)
					DrawTextureRec(bluecar_right, { 0, 0, (float)bluecar_right.width, float(bluecar_right.height) }, { (float)allLane[i].getObstacles()[j].getScreenRec().x, allLane[allLane[i].getObstacles()[j].getInLane()].getScreenPos().y + 15 }, WHITE);
				if (allLane[i].getObstacles()[j].getType() == AMBULANCE)
					DrawTextureRec(ambulance_right, { 0, 0, (float)ambulance_right.width, float(ambulance_right.height) }, { (float)allLane[i].getObstacles()[j].getScreenRec().x, allLane[allLane[i].getObstacles()[j].getInLane()].getScreenPos().y + 15 }, WHITE);
			}
		}
	}
	DrawRectangleRec({ 961, 0, 1280 - 961, 720 }, RAYWHITE);

	Vector2 getMouse = GetMousePosition();
	int restartX = 1000, restartY = 600, pauseX = 1100, pauseY = 600, musicX = 1200, musicY = 600;
	if (getMouse.x >= restartX && getMouse.x <= restartX + restart_button.width && getMouse.y >= restartY && getMouse.y <= restartY + restart_button.height)
	{
		DrawTexture(restart_button, restartX, restartY, RED);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
		}
	}
	else
	{
		DrawTexture(restart_button, restartX, restartY, RAYWHITE);
	}

	if (getMouse.x >= pauseX && getMouse.x <= pauseX + pause_button.width && getMouse.y >= pauseY && getMouse.y <= pauseY + pause_button.height)
	{
		DrawTexture(pause_button, pauseX, pauseY, RED);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			pauseState = true;
		}
	}
	else
	{
		DrawTexture(pause_button, pauseX, pauseY, RAYWHITE);
	}

	if (getMouse.x >= musicX && getMouse.x <= musicX + music_button.width && getMouse.y >= musicY && getMouse.y <= musicY + music_button.height)
	{
		DrawTexture(music_button, musicX, musicY, RED);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
		}
	}
	else
		DrawTexture(music_button, musicX, musicY, RAYWHITE);


	//DrawRectangleRec({ 961, 0, 1280 - 961, 720 }, RAYWHITE);
	DrawText(TextFormat("Time: %lf", playTime + player.time), 1000, 500, 35, BLACK);
	if (GuiLabelButton({ 1150, 100, 100, 50 }, "NEXT"))
		nextButton = true;
	if (GuiLabelButton({ 1050, 100, 100, 50 }, "BACK"))
		backButton = true;

	if (pauseState == true) {
		float pauseMenuX = 640 - pauseMenu.width / 2;
		float pauseMenuY = 360 - pauseMenu.height / 2;
		DrawTexture(blurImage, 0, 0, CLITERAL(Color){ 255, 255, 255, 200 });
		DrawTexture(pauseMenu, pauseMenuX, pauseMenuY, RAYWHITE);
		float resumeButtonX = pauseMenuX + pauseMenu.width / 4 - resume_button.width / 2;
		float resumeButtonY = pauseMenuY + 170;
		float homeButtonX = pauseMenuX + 3 * pauseMenu.width / 4 - home_button.width / 2;
		float homeButtonY = pauseMenuY + 170;
		Vector2 mousePos = GetMousePosition();
		if (mousePos.x >= resumeButtonX && mousePos.x <= resumeButtonX + resume_button.width && mousePos.y >= resumeButtonY && mousePos.y <= resumeButtonY + resume_button.height) {
			DrawTexture(resume_button, resumeButtonX, resumeButtonY, RED);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
				pauseState = false;
			}
		}
		else DrawTexture(resume_button, resumeButtonX, resumeButtonY, RAYWHITE);

		if (mousePos.x >= homeButtonX && mousePos.x <= homeButtonX + home_button.width && mousePos.y >= homeButtonY && mousePos.y <= homeButtonY + home_button.height) {
			DrawTexture(home_button, homeButtonX, homeButtonY, RED);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
				pauseState = false;
				backButton = true;
			}
		}
		else DrawTexture(home_button, homeButtonX, homeButtonY, RAYWHITE);
	}
}

void Game::drawPlayerState()
{
	DrawTexturePro(charAnim[player.curDirection][player.curImage / 4],
				   {0, 0, (float)charAnim[player.curDirection][player.curImage / 4].width, (float)charAnim[player.curDirection][player.curImage / 4].height},
				   {player.getScreenRec()}, {0, 0}, 0, WHITE);
	if (player.isMoving)
	{
		player.curImage++;
		if (player.curImage > 15)
			player.curImage = 0;
		player.isMoving = false;
	}
	else
	{
		player.curImage = 0;
	}
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
			temp1.width = (float)redcar_left.width;
			temp1.height = (float)(redcar_left.height);
			break;
		case BLUECAR:
			temp1.width = (float)bluecar_left.width;
			temp1.height = (float)bluecar_left.height;
			break;
		case AMBULANCE:
			temp1.width = (float)ambulance_left.width;
			temp1.height = (float)ambulance_right.height;
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
