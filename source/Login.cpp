#include "../header/Login.h"
#include "../header/raygui.h"

Login::Login() {
	//std::cout << GetScreenWidth() << std::endl;
	loginBackground = &TextureHolder::getHolder().get(Textures::LOGIN_BG);
	blurImage = &TextureHolder::getHolder().get(Textures::BLUR_BG);
	playerBox1 = &TextureHolder::getHolder().get(Textures::PLAYER_BOX_1);
	playerBox2 = &TextureHolder::getHolder().get(Textures::PLAYER_BOX_2);
	inputButton1 = &TextureHolder::getHolder().get(Textures::INPUT_BTN_1);
	inputButton2 = &TextureHolder::getHolder().get(Textures::INPUT_BTN_2);
	okButton1 = &TextureHolder::getHolder().get(Textures::OK_BTN_1);
	okButton2 = &TextureHolder::getHolder().get(Textures::OK_BTN_2);
	loadingMenu = &TextureHolder::getHolder().get(Textures::LOAD_MENU);
	loadingBar = &TextureHolder::getHolder().get(Textures::LOAD_BAR);
	loadingEle = &TextureHolder::getHolder().get(Textures::LOAD_ELE);
	posLoadingX = GetScreenWidth() / 2 - loadingMenu->width / 2;
	posLoadingY = GetScreenHeight() / 2 - loadingMenu->height / 2;
	posBarX = GetScreenWidth() / 2 - loadingBar->width / 2;
	posBarY = GetScreenHeight() / 2 - loadingBar->height / 2;
	posEleX[0] = posBarX + 5;
	for (int i = 1; i < 26; i++) {
		posEleX[i] = posEleX[i - 1] + loadingEle->width + 5;
	}
	posEleY = posBarY + loadingBar->height / 2 - loadingEle->height / 2;
	inputButtonRec = { 640, 400, 329, 94 };
	font = LoadFont("data/font.ttf");
	curFrame = 0;
	letterFrame = 0;
	loadSuccess = false;
	mouseOnText = false;
	mouseOnOK = false;
	isOk = false;
	backButton = false;
	inputName = "";
	if (listPlayer.size() % 2 == 0) numsState = listPlayer.size() / 2;
	else numsState = listPlayer.size() / 2 + 1;
	currentState = { 0,0 };
}

Login::~Login() {
	UnloadFont(font);
}

Screen Login::update() {
	if (backButton) {
		curFrame = 0;
		letterFrame = 0;
		loadSuccess = false;
		isOk = false;
		backButton = false;
		inputName = "";
		currentState.first = 0;
		return HOME;
	}
	if (CheckCollisionPointRec(GetMousePosition(), inputButtonRec)) {
		mouseOnText = true;
	}
	else mouseOnText = false;

	if (CheckCollisionPointCircle(GetMousePosition(), { 640, 617 }, 37) && isOk == false) {
		mouseOnOK = true;
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			isOk = true;

			int temp = indexInPlayerList();
			if (temp != -1) {
				curPlayer = listPlayer[temp];
			}
			else {
				curPlayer = Player(inputName);
			}
		}
	}
	else mouseOnOK = false;

	if (mouseOnText) {
		letterFrame++;
		SetMouseCursor(MOUSE_CURSOR_IBEAM);
		int key = GetCharPressed();

		if ((key >= 32) && (key <= 125) && inputName.length() <= MAX_INPUT_CHARS) {
			inputName.push_back(char(key));
			/*if (MeasureText(inputName.c_str(), 40) >= inputButtonRec.width) {
				inputName.pop_back();
			}*/
		}
		key = GetCharPressed();

		if (IsKeyPressed(KEY_BACKSPACE)) {
			if (!inputName.empty()) inputName.pop_back();
		}
	}
	else {
		SetMouseCursor(MOUSE_CURSOR_DEFAULT);
		letterFrame = 0;
	}

	if (isOk) {
		if (!loadSuccess) {
			curFrame++;
			if (curFrame == numsFrame * delay) {
				loadSuccess = true;
			}
		}
		else {
			if (IsKeyPressed(KEY_ENTER)) {
				curFrame = 0;
				letterFrame = 0;
				loadSuccess = false;
				isOk = false;
				backButton = false;
				inputName = "";
				currentState.first = 0;
				return GAME;
			}
		}
	}

	return LOGIN;
}

void Login::drawListPlayer() {
	if (listPlayer.size() % 2 == 1 && currentState.first == numsState - 1) {
		currentState.second = 1;
	}
	else currentState.second = 2;

	if (currentState.second == 1) {
		posPlayerBoxX[0] = GetScreenWidth() / 2 - playerBox1->width / 2;
		posPlayerBoxY = 100;
		if (CheckCollisionPointRec(GetMousePosition(), { posPlayerBoxX[0], 100, (float)playerBox1->width, (float)playerBox1->height})) {
			DrawTexture(*playerBox2, posPlayerBoxX[0], posPlayerBoxY, WHITE);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
				isOk = true;
				curPlayer = listPlayer[2 * currentState.first];
			//	std::cout << curPlayer.getName() << std::endl;
			}
		}
		else {
			DrawTexture(*playerBox1, posPlayerBoxX[0], posPlayerBoxY, WHITE);
		}
		std::string temp1 = "Username: " + listPlayer[2 * currentState.first].getName();
		DrawText(temp1.c_str(), GetScreenWidth() / 2 - MeasureText(temp1.c_str(), 40) / 2, 130, 40, DARKGRAY);
		std::string temp2 = "Level: " + std::to_string(listPlayer[2 * currentState.first].getLevel());
		DrawText(temp2.c_str(), GetScreenWidth() / 2 - MeasureText(temp1.c_str(), 40) / 2, 250, 40, DARKGRAY);

	}
	else if (currentState.second == 2) {
		posPlayerBoxX[0] = 100;
		posPlayerBoxX[1] = 680;
		posPlayerBoxY = 100;
		if (CheckCollisionPointRec(GetMousePosition(), {100, 100, (float)playerBox1->width, (float)playerBox1->height})) {
			DrawTexture(*playerBox2, posPlayerBoxX[0], posPlayerBoxY, WHITE);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
				isOk = true;
				curPlayer = listPlayer[2 * currentState.first];
			}
		}
		else {
			DrawTexture(*playerBox1, posPlayerBoxX[0], posPlayerBoxY, WHITE);
		}
		if (CheckCollisionPointRec(GetMousePosition(), { 680, 100, (float)playerBox1->width, (float)playerBox1->height })) {
			DrawTexture(*playerBox2, posPlayerBoxX[1], posPlayerBoxY, WHITE);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
				isOk = true;
				curPlayer = listPlayer[2 * currentState.first + 1];
			}
		}
		else {
			DrawTexture(*playerBox1, posPlayerBoxX[1], posPlayerBoxY, WHITE);
		}

		std::string temp1 = "Username: " + listPlayer[2 * currentState.first].getName();
		std::string temp2 = "Username: " + listPlayer[2 * currentState.first + 1].getName();
		float posX[2] = { posPlayerBoxX[0] + (playerBox1->width - MeasureText(temp1.c_str(), 40)) / 2,
						  posPlayerBoxX[1] + (playerBox1->width - MeasureText(temp2.c_str(), 40)) / 2 };
		DrawText(temp1.c_str(), posX[0], 130, 40, DARKGRAY);
		DrawText(temp2.c_str(), posX[1], 130, 40, DARKGRAY);

		std::string temp3 = "Level: " + std::to_string(listPlayer[2 * currentState.first].getLevel());
		std::string temp4 = "Level: " + std::to_string(listPlayer[2 * currentState.first + 1].getLevel());
		DrawText(temp3.c_str(), posX[0], 250, 40, DARKGRAY);
		DrawText(temp4.c_str(), posX[1], 250, 40, DARKGRAY);
		

	}

	if (CheckCollisionPointTriangle(GetMousePosition(), { 15,220 }, { 80, 260 }, { 80, 180 })) {
		DrawTriangle({ 15,220 }, { 80, 260 }, { 80, 180 }, RED);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			if (currentState.first == 0) currentState.first = numsState - 1;
			else currentState.first--;
		}
	}
	else {
		DrawTriangle({ 15,220 }, { 80, 260 }, { 80, 180 }, BLACK);
	}

	if (CheckCollisionPointTriangle(GetMousePosition(), { 1200,180 }, { 1200, 260 }, { 1265, 220 })) {
		DrawTriangle({ 1200,180 }, { 1200, 260 }, { 1265, 220 }, RED);
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			if (currentState.first == numsState - 1) currentState.first = 0;
			else currentState.first++;
		}
	}
	else {
		DrawTriangle({ 1200,180 }, { 1200, 260 }, { 1265, 220 }, BLACK);
	}
}

void Login::draw() {
	DrawTextureRec(*loginBackground, { 0, 0, 1280, 720 }, { 0, 0 }, WHITE);

	drawListPlayer();
	DrawTextEx(font, "Username: ", { 400, 430 }, 40, -3, DARKGRAY);

	if (!mouseOnText) {
		DrawTextureRec(*inputButton1, { 0, 0, 329, 94 }, { 640, 400 }, WHITE);
	}
	else DrawTextureRec(*inputButton2, { 0, 0, 329, 94 }, { 640, 400 }, WHITE);

	DrawText(inputName.c_str(), inputButtonRec.x + 10, inputButtonRec.y + 27, 40, RED);

	if (mouseOnText) {
		if (inputName.size() <= MAX_INPUT_CHARS) {
			if ((letterFrame / 20) % 5 == 0) {
				DrawText("_", inputButtonRec.x + 14 + MeasureText(inputName.c_str(), 40), inputButtonRec.y + 31, 40, MAROON);
			}
		}
	}

	if (mouseOnOK) {
		DrawTexture(*okButton2, 640 - 38, 580, WHITE);
	}
	else DrawTexture(*okButton1, 640 - 38, 580, WHITE);

	if (GuiLabelButton({ 15, 15, 100, 50 }, "BACK") && isOk == false)
		backButton = true;


	if (isOk) {
		DrawTexture(*blurImage, 0, 0, CLITERAL(Color){ 255, 255, 255, 240 });
		DrawTexture(*loadingMenu, posLoadingX, posLoadingY, WHITE);
		DrawText(curPlayer.getName().c_str(), GetScreenWidth() / 2 - MeasureText(curPlayer.getName().c_str(), 40) / 2,
			250, 40, DARKGRAY);
		DrawTexture(*loadingBar, posBarX, posBarY, WHITE);
		if (!loadSuccess) {
			std::string temp = "Loading";
			std::cout << curFrame << std::endl;
			for (int i = 0; i < curFrame / delay; i++) {
				DrawTexture(*loadingEle, posEleX[i], posEleY, WHITE);
			}
			for (int j = 0; j <= (curFrame / delay) % 3; j++) {
				temp += '.';
			}
			DrawText(temp.c_str(), GetScreenWidth() / 2 - 60,
				480, 40, DARKGRAY);
		}
		else {
			for (int i = 0; i < 26; i++) {
				DrawTexture(*loadingEle, posEleX[i], posEleY, WHITE);
			}
			std::string temp = "Press Enter to PlayGame";
			DrawText(temp.c_str(), GetScreenWidth() / 2 - MeasureText(temp.c_str(), 40) / 2,
				480, 40, DARKGRAY);
		}
	}
}

int Login::indexInPlayerList() {
	for (int i = 0; i < listPlayer.size(); i++) {
		if (inputName == listPlayer[i].getName()) {
			return i;
		}
	}
	return -1;
}