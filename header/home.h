#pragma once
#include <iostream>
#include <raylib.h>
#include "raygui.h"

class Home
{
private:
	Texture2D homeBackground;
public:
	Home();
	void update();
	void draw();
	~Home();
};