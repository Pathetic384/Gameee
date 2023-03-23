#pragma once
#include "Base.h"


class Particle
{
public:
	//Initialize position and animation
	Particle(SDL_Renderer* screen);

	~Particle();

	//Shows the particle
	void Show(SDL_Renderer* screen);

	void SetPat(int x, int y);

	//Checks if particle is dead
	bool isDead();

	bool LoadMedia(SDL_Renderer* screen);
private:
	//Offsets
	int mPosX, mPosY;

	//Current frame of animation
	int mFrame;

	//Type of particle
	Base* mTexture;

	Base gRedTexture;
	Base gGreenTexture;
	Base gBlueTexture;
};
