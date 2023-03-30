#pragma once
#include "Base.h"

class Res : public Base
{
public:
	//Initializes internal variables
	Res();

	void set_clips();

	bool LoadImg(std::string path, SDL_Renderer* screen);

	void Show(SDL_Renderer* des);

	void Reset()
	{
		frame_ = 0;
		framerun = true;
	}

	void Set(int x, int y)
	{
		rect_.x = x;
		rect_.y = y;
	};



private:
	SDL_Rect frame_clip_[38];

	int width_frame_;
	int height_frame_;

	int sprite;

	int frame_;

	bool framerun;
}; 