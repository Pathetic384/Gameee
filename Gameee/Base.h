#pragma once

#include "Func.h"

class Base 
{
public:
	Base();
	~Base();
	virtual bool LoadImg(std::string path, SDL_Renderer* screen);
	void Render(SDL_Renderer* des, const SDL_Rect* clip = NULL);

	void Free();
	void SetRect(const double& x, const double& y) { rect_.x = x, rect_.y = y; };
	SDL_Rect GetRect() const { return rect_; }
	SDL_Texture* GetObject() { return p_object_; }

	bool CheckRect(const int& x, const int& y, const SDL_Rect& rect);

protected:
	SDL_Texture* p_object_;
	SDL_Rect rect_;
};