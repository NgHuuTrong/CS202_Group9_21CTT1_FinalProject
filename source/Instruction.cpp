#include "../header/Instruction.h"
#include "../header/raygui.h"
Instruction::Instruction()
{
	mode = 0;
	instructionBackground1 = LoadTexture("data/Instruction1.png");
	instructionBackground2 = LoadTexture("data/Instruction2.png");
	backButton = false;
	//GuiLoadIcons("data/arrow.rgi", true);
}

Instruction::~Instruction() {
	UnloadTexture(instructionBackground1);
	UnloadTexture(instructionBackground2);

}
Screen Instruction::update() {
	if (backButton) {
		backButton = false;
		return HOME;
	}
	return INSTRUCTION;
}
void Instruction::draw() {
	if (mode == 0) {
		DrawTextureRec(instructionBackground1, { 0,0,1280,720 }, { 0,0 }, WHITE);
		Vector2 hihi = GetMousePosition();
		int xPos = 1150;
		int yPos = 275;
		if (hihi.x >= 1175 && hihi.x <= 1250 && hihi.y <= 390 && hihi.y >= 275) {
			GuiDrawIcon(119, xPos, yPos, 8, ORANGE);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
				mode = 1;
			}
		}
		else GuiDrawIcon(119, xPos, yPos, 8, BLACK);
		if (GuiLabelButton({ 15, 15, 100, 50 }, "BACK"))
			backButton = true;
		return;
	}
	if (mode == 1){
		DrawTextureRec(instructionBackground2, { 0,0,1280,720 }, { 0,0 }, WHITE);
	}
}