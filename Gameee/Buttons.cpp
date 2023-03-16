#include "Buttons.h"
#include <iostream>

LButton::LButton()
{
    width_frame_ = 0;
    height_frame_ = 0;
    status_ = -1;

}

void LButton::set_clips()
{
	for (int i = 0; i < BUTTON_SPRITE_TOTAL; ++i)
	{
		frame_clip_[i].x = 0;
		frame_clip_[i].y = i * 200;
		frame_clip_[i].w = BUTTON_WIDTH;
		frame_clip_[i].h = BUTTON_HEIGHT;
	}
}

bool LButton::LoadImg(std::string path, SDL_Renderer* screen)
{
    bool ret = Base::LoadImg(path, screen);

    if (ret == true)
    {
        width_frame_ = rect_.w;
        height_frame_ = rect_.h/4;
    }
    return ret;
}

void LButton::handleEvent(SDL_Event* e, int& t)
{
	//If mouse event happened
	if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP)
	{
		//Get mouse position
		int x, y;
		SDL_GetMouseState(&x, &y);

		//Check if mouse is in button
		bool inside = true;

		//Mouse is left of the button
		if (x < rect_.x)
		{
			inside = false;
		}
		//Mouse is right of the button
		else if (x > rect_.x + BUTTON_WIDTH)
		{
			inside = false;
		}
		//Mouse above the button
		else if (y < rect_.y)
		{
			inside = false;
		}
		//Mouse below the button
		else if (y > rect_.y + BUTTON_HEIGHT)
		{
			inside = false;
		}

		//Mouse is outside button
		if (!inside)
		{
			mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
		}
		//Mouse is inside button
		else
		{
			//Set mouse over sprite
			switch (e->type)
			{
			case SDL_MOUSEMOTION:
				mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
				break;

			case SDL_MOUSEBUTTONDOWN:
				mCurrentSprite = BUTTON_SPRITE_MOUSE_DOWN;
				break;

			case SDL_MOUSEBUTTONUP:
				mCurrentSprite = BUTTON_SPRITE_MOUSE_UP;
				t = 1;
				break;
			}
		}
	}
}

void LButton::Show(SDL_Renderer* des)
{
	SDL_Rect* currentClip = &frame_clip_[mCurrentSprite];
	SDL_Rect renderQuad = { rect_.x, rect_.y, width_frame_, height_frame_ };

	SDL_RenderCopy(des, p_object_, currentClip, &renderQuad);

}