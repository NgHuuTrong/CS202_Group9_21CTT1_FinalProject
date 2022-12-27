#include "../header/Instruction.h"
#include "../header/raygui.h"
Instruction::Instruction()
{
	mode = 0;
	instructionBackground1 = &TextureHolder::getHolder().get(Textures::INS_BG_1);
	instructionBackground2 = &TextureHolder::getHolder().get(Textures::INS_BG_2);
	backButton = false;
}
Instruction::~Instruction()
{
}

Screen Instruction::update()
{
	if (backButton)
	{
		backButton = false;
		return HOME;
	}
	return INSTRUCTION;
}
void Instruction::draw()
{
	if (mode == 0)
	{
		DrawTextureRec(*instructionBackground1, {0, 0, 1280, 720}, {0, 0}, WHITE);
		if (CheckCollisionPointTriangle(GetMousePosition(), {1200, 300}, {1200, 400}, {1250, 350}))
		{
			DrawTriangle({1200, 300}, {1200, 400}, {1250, 350}, RED);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				mode = 1;
			}
		}
		else
			DrawTriangle({1200, 300}, {1200, 400}, {1250, 350}, BLACK);
		if (GuiLabelButton({15, 15, 100, 50}, "BACK"))
			backButton = true;
	}
	if (mode == 1)
	{
		DrawTextureRec(*instructionBackground2, {0, 0, 1280, 720}, {0, 0}, WHITE);
		if (CheckCollisionPointTriangle(GetMousePosition(), {100, 300}, {50, 350}, {100, 400}))
		{
			DrawTriangle({100, 300}, {50, 350}, {100, 400}, RED);
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				mode = 0;
			}
		}
		else
			DrawTriangle({100, 300}, {50, 350}, {100, 400}, BLACK);
		if (GuiLabelButton({15, 15, 100, 50}, "BACK"))
			backButton = true;
	}
}