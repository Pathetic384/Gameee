#pragma once
#include "Base.h"

class Effects : public Base
{
public:
	//Initializes internal variables
	Effects();

	void set_clips();

	bool LoadImg(std::string path, SDL_Renderer* screen);

	void Show(SDL_Renderer* des);

	void SetFrame(int x)
	{
		frame_ = x;
	}

	void Set(int x, int y)
	{
		rect_.x = x;
		rect_.y = y;
	};

	void set_clips2();

private:
	SDL_Rect frame_clip_[55];

	SDL_Rect frame_clip_2[8];

	int width_frame_;
	int height_frame_;

	int sprite;

	int frame_;

};