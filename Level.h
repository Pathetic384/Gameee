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

class Level 
{
public:
	Level();
	~Level();

	int CreateLevel(SDL_Renderer* screen, int& score);

private:

};