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
#include "Particle.h"

class Menu 
{
public:
	Menu();
	~Menu();

	int CreateMenu(SDL_Renderer* screen);

	int CreateLevels(SDL_Renderer* screen, int& score, int& score2, int& score3, int& score4);

	int CreateResult(SDL_Renderer* screen, int& score, int& high_score);

	int CreatePause(SDL_Renderer* screen);

	int CreateTutorial(SDL_Renderer* screen);

private:
	TTF_Font* font = TTF_OpenFont("vibe.ttf", 45);
	TTF_Font* font2 = TTF_OpenFont("vibe.ttf", 80);
};