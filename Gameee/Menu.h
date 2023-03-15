#pragma once
#include "Base.h"
#include "Text.h"
#include "Buttons.h"

class Menu : public Base
{
public:
	Menu();
	~Menu();

	int CreateMenu(SDL_Renderer* screen);

	int CreateLevels(SDL_Renderer* screen);

	int CreateResult(SDL_Renderer* screen, int score);

	int CreatePause(SDL_Renderer* screen);
private:

};