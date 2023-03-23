#include "Effects.h"

Effects::Effects()
{
	width_frame_ = 0;
	height_frame_ = 0;
	frame_ = -1;
	sprite = -1;

}

void Effects::set_clips2()
{
	for (int i = 0; i < 8; ++i)
	{
		frame_clip_2[i].x = i * width_frame_;
		frame_clip_2[i].y = 0;
		frame_clip_2[i].w = width_frame_;
		frame_clip_2[i].h = height_frame_;
	}
}

void Effects::set_clips()
{
	for (int i = 0; i < 55; ++i)
	{
		frame_clip_[i].x = i * 64;
		frame_clip_[i].y = 0 * 64;
		frame_clip_[i].w = 64;
		frame_clip_[i].h = 64;
	}
	
}

bool Effects::LoadImg(std::string path, SDL_Renderer* screen)
{
	bool ret = Base::LoadImg(path, screen);

	if (ret == true)
	{
		width_frame_ = rect_.w / 8;
		height_frame_ = rect_.h;
	}
	return ret;
}


void Effects::Show(SDL_Renderer* des)
{
	frame_++;
	if (frame_ >= 55)
	{
		frame_ = 0;
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