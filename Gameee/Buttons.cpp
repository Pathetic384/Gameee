#include "Buttons.h"
#include <iostream>

Button::Button()
{
    width_frame_ = 0;
    height_frame_ = 0;
    status_ = -1;

}


void Button::set_button_clips(int x)
{
	for (int i = 0; i < BUTTON_SPRITE_TOTAL; ++i)
	{
		frame_clip_[i].x = 0;
		frame_clip_[i].y = i * x;
		frame_clip_[i].w = x;
		frame_clip_[i].h = x;
	}
	BUTTON_WIDTH = x;
	BUTTON_HEIGHT = x;

}

bool Button::LoadImg(std::string path, SDL_Renderer* screen)
{
    bool ret = Base::LoadImg(path, screen);

    if (ret == true)
    {
        width_frame_ = rect_.w;
        height_frame_ = rect_.h/4;
    }
    return ret;
}

void Button::handleEvent(SDL_Event e, int& t)
{
	if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP)
	{
		int x, y;
		SDL_GetMouseState(&x, &y);

		bool inside = true;

		if (x < rect_.x)
		{
			inside = false;
		}
		else if (x > rect_.x + BUTTON_WIDTH)
		{
			inside = false;
		}
		else if (y < rect_.y)
		{
			inside = false;
		}
		else if (y > rect_.y + BUTTON_HEIGHT)
		{
			inside = false;
		}
		if (!inside)
		{
			mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
		}
		else
		{
			switch (e.type)
			{
			case SDL_MOUSEMOTION:
				mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER_MOTION;
				t = 2;
				break;

			case SDL_MOUSEBUTTONDOWN:
			{
				if (e.button.button == SDL_BUTTON_LEFT)
				{
					mCurrentSprite = BUTTON_SPRITE_MOUSE_DOWN;
					break;
				}
			}
			case SDL_MOUSEBUTTONUP:
				if (e.button.button == SDL_BUTTON_LEFT)
				{
					mCurrentSprite = BUTTON_SPRITE_MOUSE_UP;
					t = 1;
					break;
				}
			}
		}
	}
}

void Button::Show(SDL_Renderer* des)
{
	SDL_Rect* currentClip = &frame_clip_[mCurrentSprite];
	SDL_Rect renderQuad = { rect_.x, rect_.y, width_frame_, height_frame_ };

	SDL_RenderCopy(des, p_object_, currentClip, &renderQuad);

}

void Button::Free()
{
	p_object_ = NULL;
}
