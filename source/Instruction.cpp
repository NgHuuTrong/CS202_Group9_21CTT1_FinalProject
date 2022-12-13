#include "../header/Instruction.h"
#include "../header/raygui.h"
Instruction::Instruction()
{
	mode = 0;
	instructionBackground = LoadTexture("data/Instruction1.png");
	backButton = false;
	//GuiLoadIcons("data/arrow.rgi", true);
}

Instruction::~Instruction() {
	UnloadTexture(instructionBackground);
}
Screen Instruction::update() {
	if (backButton) {
		backButton = false;
		return HOME;
	}
	return INSTRUCTION;
}
void Instruction::draw() {
	DrawTextureRec(instructionBackground, { 0,0,1280,720 }, { 0,0 }, WHITE);
	if (GuiLabelButton({ 15, 15, 100, 50 }, "BACK"))
		backButton = true;
}