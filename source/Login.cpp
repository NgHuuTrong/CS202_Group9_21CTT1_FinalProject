#include "../header/Login.h"
#include "../header/raygui.h"

Login::Login() {
	loginBackground = &TextureHolder::getHolder().get(Textures::RANK_BG);
	inputButton1 = &TextureHolder::getHolder().get(Textures::INPUT_BTN_1);
	inputButton2 = &TextureHolder::getHolder().get(Textures::INPUT_BTN_2);
	okButton1 = &TextureHolder::getHolder().get(Textures::OK_BTN_1);
	okButton2 = &TextureHolder::getHolder().get(Textures::OK_BTN_2);
	inputButtonRec = { 640, 400, 329, 94 };
	font = LoadFont("data/font.ttf");
	letterFrame = 0;
	mouseOnText = false;
	mouseOnOK = false;
	backButton = false;
}

Login::~Login() {

}

Screen Login::update() {
	if (backButton) {
		backButton = false;
		return HOME;
	}
	if (CheckCollisionPointRec(GetMousePosition(), inputButtonRec)) {
		mouseOnText = true;
	}
	else mouseOnText = false;

	if (CheckCollisionPointCircle(GetMousePosition(), { 640, 617 }, 37)) {
		mouseOnOK = true;
	}
	else mouseOnOK = false;

	if (mouseOnText) {
		letterFrame++;
		SetMouseCursor(MOUSE_CURSOR_IBEAM);
		int key = GetCharPressed();

		if ((key >= 32) && (key <= 125) && inputName.length() <= MAX_INPUT_CHARS) {
			inputName.push_back(char(key));
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

	
	return LOGIN;
}

void Login::draw() {
	DrawTextureRec(*loginBackground, { 0, 0, 1280, 720 }, { 0, 0 }, WHITE);
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

	if (GuiLabelButton({ 15, 15, 100, 50 }, "BACK"))
		backButton = true;
}