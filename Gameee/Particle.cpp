#include "Particle.h"

Particle::Particle(SDL_Renderer*screen)
{
	mPosX = 0;
	mPosY = 0;
	mTexture = NULL;
	mFrame = 0;
	gRedTexture.LoadImg("38_particle_engines/red.bmp", screen);
	gBlueTexture.LoadImg("38_particle_engines/blue.bmp", screen);
	gGreenTexture.LoadImg("38_particle_engines/greeen.bmp", screen);
	gRedTexture.setAlpha(192);
	gGreenTexture.setAlpha(192);
	gBlueTexture.setAlpha(192);
}

Particle::~Particle()
{
	
}

void Particle::SetPat(int x, int y)
{
	//Set offsets
	mPosX = x - 5 + (rand() % 25);
	mPosY = y - 5 + (rand() % 25);

	//Initialize animation
	mFrame = rand() % 5;

	//Set type
	switch (rand() % 3)
	{
	case 0: mTexture = &gRedTexture; break;
	case 1: mTexture = &gGreenTexture; break;
	case 2: mTexture = &gBlueTexture; break;
	}
}

void Particle::Show(SDL_Renderer* screen)
{
	//Show image
	mTexture->SetRect(mPosX, mPosY);
	mTexture->Render(screen);

	//Animate
	mFrame++;
}

bool Particle::isDead()
{
	return mFrame > 20;
}

bool Particle::LoadMedia(SDL_Renderer* screen)
{
	bool ret;
	ret = gRedTexture.LoadImg("38_particle_engines/red.bmp",screen); 
	ret = gBlueTexture.LoadImg("38_particle_engines/blue.bmp",screen);
	ret = gGreenTexture.LoadImg("38_particle_engines/greeen.bmp",screen);
	gRedTexture.setAlpha(192);
	gGreenTexture.setAlpha(192);
	gBlueTexture.setAlpha(192);
	return ret;
}