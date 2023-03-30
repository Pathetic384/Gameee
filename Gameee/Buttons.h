#pragma once
#include "Base.h"

enum ButtonSprite
{
	BUTTON_SPRITE_MOUSE_OUT = 0,
	BUTTON_SPRITE_MOUSE_OVER_MOTION = 1,
	BUTTON_SPRITE_MOUSE_DOWN = 2,
	BUTTON_SPRITE_MOUSE_UP = 3,
	BUTTON_SPRITE_TOTAL = 4
};

class Button : public Base
{
public:
	//Initializes internal variables
	Button();

	void set_button_clips(int x);

	bool LoadImg(std::string path, SDL_Renderer* screen);

	void handleEvent(SDL_Event e, int& t);

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
	ButtonSprite mCurrentSprite;

	int BUTTON_WIDTH;
	int BUTTON_HEIGHT;
};