#pragma once
#include "Base.h"
#include "Func.h"
#include "Char.h"
#include "gamemap.h"
#include "Text.h"
#include "Timer.h"
#include <string>
#include "Menu.h"
#include "Buttons.h"

class Level2
{
public:
	Level2();
	~Level2();

	int CreateLevel(SDL_Renderer* screen, int& high_score, int sprite, int& per);

private:

};
