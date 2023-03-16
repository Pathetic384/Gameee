#pragma once
#include "Base.h"

const int BUTTON_WIDTH = 300;
const int BUTTON_HEIGHT = 200;
const int TOTAL_BUTTONS = 4;

enum LButtonSprite
{
	BUTTON_SPRITE_MOUSE_OUT = 0,
	BUTTON_SPRITE_MOUSE_OVER_MOTION = 1,
	BUTTON_SPRITE_MOUSE_DOWN = 2,
	BUTTON_SPRITE_MOUSE_UP = 3,
	BUTTON_SPRITE_TOTAL = 4
};

class LButton : public Base
{
public:
	//Initializes internal variables
	LButton();

	void set_clips();

	bool LoadImg(std::string path, SDL_Renderer* screen);

	void handleEvent(SDL_Event* e, int& t);

	void Show(SDL_Renderer* des);

	void Set(int x, int y)
	{
		rect_.x = x;
		rect_.y = y;
	};

private:
	SDL_Rect frame_clip_[4];
	
	int width_frame_;
	int height_frame_;

	int status_;

	//Currently used global sprite
	LButtonSprite mCurrentSprite;
};