#include "Effects.h"

Effects::Effects()
{
	width_frame_ = 0;
	height_frame_ = 0;
	frame_ = 0;
	sprite = -1;
	framerun = false;
}

void Effects::set_clips()
{
	for (int i = 0; i < 19; ++i)
	{
		frame_clip_[i].x = i * 96;
		frame_clip_[i].y = 0 * 96;
		frame_clip_[i].w = 96;
		frame_clip_[i].h = 96;
	}
	
}

bool Effects::LoadImg(std::string path, SDL_Renderer* screen)
{
	bool ret = Base::LoadImg(path, screen);

	if (ret == true)
	{
		width_frame_ = rect_.w / 19;
		height_frame_ = rect_.h;
	}
	return ret;
}


void Effects::Show(SDL_Renderer* des)
{
	if (framerun == true) frame_++;
	if (frame_ >= 19)
	{
		frame_ = 0;
		framerun = false;
	}
	SDL_Rect* currentClip = &frame_clip_[frame_];
	SDL_Rect renderQuad = { rect_.x, rect_.y, width_frame_, height_frame_ };
	if (currentClip != NULL)
	{
		renderQuad.w = currentClip->w;
		renderQuad.h = currentClip->h;
	}

	SDL_RenderCopy(des, p_object_, currentClip, &renderQuad);
}