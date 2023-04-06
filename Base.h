#pragma once

#include "Func.h"

class Base 
{
public:
	Base();
	~Base();
	virtual bool LoadImg(std::string path, SDL_Renderer* screen);
	void Render(SDL_Renderer* des, const SDL_Rect* clip = NULL);

	void setAlpha(Uint8 alpha)
	{
		//Modulate texture alpha
		SDL_SetTextureAlphaMod(p_object_, alpha);
	}

	void Free();
	void SetRect(const int& x, const int& y) { rect_.x = x, rect_.y = y; };
	SDL_Rect GetRect() const { return rect_; }
	SDL_Texture* GetObject() { return p_object_; }

	void Move();
	void Move2();

	void Move3();
	void Move4();

	void Move5();
	void Move6();

	void Move7();
	void Move8();

	void Move9();
	void Move10();


protected:
	SDL_Texture* p_object_;
	SDL_Rect rect_;
};