#include "../header/Game.h"
#include "../header/raygui.h"

Game::Game()
{
	player = Player("Test Name");
	pavement = LoadTexture("data/pavement.png");
	road = LoadTexture("data/road.png");
	dog = LoadTexture("data/character.png");
	redcar_left = LoadTexture("data/redcar_left.png");
	redcar_right = LoadTexture("data/redcar_right.png");
	bluecar_left = LoadTexture("data/bluecar_left.png");
	bluecar_right = LoadTexture("data/bluecar_right.png");
	ambulance_left = LoadTexture("data/ambulance_left.png");
	ambulance_right = LoadTexture("data/ambulance_right.png");
	backButton = nextButton = false;
}

Game::~Game()
{
	UnloadTexture(pavement);
	UnloadTexture(road);
	UnloadTexture(dog);
	UnloadTexture(redcar_left);
	UnloadTexture(bluecar_left);
	UnloadTexture(ambulance_left);
	UnloadTexture(redcar_right);
	UnloadTexture(bluecar_right);
	UnloadTexture(ambulance_right);

}

Screen Game::update()
{
	if (!allLane.size())
	{
		allLane = random(1);
		player.posX = 426;
		player.posY = 0;
		player.inLane = 0;
	}
	for (int i = 0; i < (int)allLane[player.posY]._obstacles.size(); i++)
	{
		if (player.checkCollision(allLane[player.posY]._obstacles[i], allLane[player.posY]._direction))
		{
			std::cout << "Collision" << std::endl;
		}
	}
	if (GetKeyPressed())
	{
		if (IsKeyPressed(KEY_S) || IsKeyPressed(KEY_DOWN))
		{
			if (player.posY < allLane.size() - 1) player.posY++;
			player.inLane++;
		}
		else if (IsKeyPressed(KEY_W) || IsKeyPressed(KEY_UP))
		{
			if (player.posY > 0) player.posY--;
			player.inLane--;
		}
		else if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_LEFT))
		{
			if (player.posX - 60 > 0) player.posX -= 60;
		}
		else if (IsKeyPressed(KEY_D) || IsKeyPressed(KEY_RIGHT))
		{
			if (player.posX + 60 < 960) player.posX += 60;
		}
	}
	if (GetMouseWheelMove() == -1 && allLane[allLane.size() - 1]._screenPos.y > 720 - pavement.height)
	{
		for (int i = 0; i < (int)allLane.size(); i++)
		{
			allLane[i]._screenPos.y -= 45;
		}
	}
	if (GetMouseWheelMove() == 1 && allLane[0]._screenPos.y < 0)
	{
		for (int i = 0; i < (int)allLane.size(); i++)
		{
			allLane[i]._screenPos.y += 45;
		}
	}

	if (backButton)
	{
		backButton = false;
		return HOME;
	}
	if (nextButton)
	{
		nextButton = false;
		int level = allLane[0].level + 1;
		allLane.clear();
		allLane = random(level);
	}
	return GAME;
}

void Game::draw()
{
	if (!allLane.size()) return;
	for (Lane l : allLane)
	{
		if (l._laneType == PAVEMENT)
			DrawTextureRec(pavement, l._srcRec, l._screenPos, WHITE);
		else if (l._laneType == ROAD)
			DrawTextureRec(road, l._srcRec, l._screenPos, WHITE);
		//DrawLineEx(l._screenPos, { 960, l._screenPos.y }, 2, WHITE);
	}
	DrawRectangleLinesEx({ 0, 0, 960, 720 }, 3, BLACK);
	//DrawText(TextFormat("Level: %i", redcar.width), 1000, 500, 35, BLACK);
	//DrawText(TextFormat("y: %f", allLane[0]._screenPos.y), 1000, 300, 35, BLACK);
	DrawTextureRec(dog, { 0, 0, (float)dog.width, (float)dog.height }, { (float)player.posX, allLane[player.posY]._screenPos.y + 8 }, WHITE);
	for (int i = 0; i < allLane.size(); i++)
	{
		if (!allLane[i]._direction)
		{
			for (int j = 0; j < allLane[i]._numsOfObstacles; j++)
			{
				allLane[i]._obstacles[j].posX += velo;
				if (allLane[i]._obstacles[j].posX >= 960) allLane[i]._obstacles[j].posX = -80;
				if (allLane[i]._obstacles[j].type == REDCAR)
					DrawTextureRec(redcar_left, { 0,0,(float)redcar_left.width, float(redcar_left.height) }, { (float)allLane[i]._obstacles[j].posX, allLane[allLane[i]._obstacles[j].inLane]._screenPos.y + 15 }, WHITE);
				if (allLane[i]._obstacles[j].type == BLUECAR)
					DrawTextureRec(bluecar_left, { 0,0,(float)bluecar_left.width, float(bluecar_left.height) }, { (float)allLane[i]._obstacles[j].posX, allLane[allLane[i]._obstacles[j].inLane]._screenPos.y + 15 }, WHITE);
				if (allLane[i]._obstacles[j].type == AMBULANCE)
					DrawTextureRec(ambulance_left, { 0,0,(float)ambulance_left.width, float(ambulance_left.height) }, { (float)allLane[i]._obstacles[j].posX, allLane[allLane[i]._obstacles[j].inLane]._screenPos.y + 15 }, WHITE);
			}
		}
		else
		{
			for (int j = 0; j < allLane[i]._numsOfObstacles; j++)
			{
				allLane[i]._obstacles[j].posX -= velo;
				if (allLane[i]._obstacles[j].posX <= -80) allLane[i]._obstacles[j].posX = 960;
				if (allLane[i]._obstacles[j].type == REDCAR)
					DrawTextureRec(redcar_right, { 0,0,(float)redcar_right.width, float(redcar_right.height) }, { (float)allLane[i]._obstacles[j].posX, allLane[allLane[i]._obstacles[j].inLane]._screenPos.y + 15 }, WHITE);
				if (allLane[i]._obstacles[j].type == BLUECAR)
					DrawTextureRec(bluecar_right, { 0,0,(float)bluecar_right.width, float(bluecar_right.height) }, { (float)allLane[i]._obstacles[j].posX, allLane[allLane[i]._obstacles[j].inLane]._screenPos.y + 15 }, WHITE);
				if (allLane[i]._obstacles[j].type == AMBULANCE)
					DrawTextureRec(ambulance_right, { 0,0,(float)ambulance_right.width, float(ambulance_right.height) }, { (float)allLane[i]._obstacles[j].posX, allLane[allLane[i]._obstacles[j].inLane]._screenPos.y + 15 }, WHITE);
			}
		}
	}
	DrawRectangleRec({ 961, 0, 1280 - 961, 720 }, RAYWHITE);
	if (GuiLabelButton({ 1150, 100, 100, 50 }, "NEXT"))
		nextButton = true;
	if (GuiLabelButton({ 1050, 100, 100, 50 }, "BACK"))
		backButton = true;
}
