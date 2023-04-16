#include "Base.h"
#include <iostream>

Base::Base()
{
    p_object_ = NULL;
    rect_.x = 0;
    rect_.y = 0;
    rect_.w = 0;
    rect_.h = 0;
}
Base::~Base()
{
    Free();
}

bool Base::LoadImg(std::string path, SDL_Renderer* screen)
{
    SDL_Texture* newTexture = NULL;

    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface != NULL)
    {
        SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 255, 255, 255));
        SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 195, 195, 195));
        newTexture = SDL_CreateTextureFromSurface(screen, loadedSurface);
        if (newTexture != NULL)
        {
            rect_.w = loadedSurface->w;
            rect_.h = loadedSurface->h;
        }

        SDL_FreeSurface(loadedSurface);
    }

    p_object_ = newTexture;
    return p_object_ != NULL;
}

void Base::Free()
{

    if (p_object_ != NULL)
    {
        SDL_DestroyTexture(p_object_);
        p_object_ = NULL;
        rect_.w = 0;
        rect_.h = 0;
    }
}

void Base::Render(SDL_Renderer* des, const SDL_Rect* clip)
{
    SDL_Rect renderQuad = { rect_.x, rect_.y, rect_.w, rect_.h };
    if (clip != NULL)
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }
    SDL_RenderCopy(des, p_object_, clip, &renderQuad);
}

void Base::Move()
{
    rect_.x -= 1;
    if (rect_.x < -1200) rect_.x += 1200;
}

void Base::Move2()
{
    rect_.x -= 1;
    if (rect_.x < 0) rect_.x += 1200;
}
void Base::Move3()
{
    rect_.x -= 2;
    if (rect_.x < -1200) rect_.x += 1200;
}
void Base::Move4()
{
    rect_.x -= 2;
    if (rect_.x < 0) rect_.x += 1200;
}
void Base::Move5()
{
    rect_.x -= 3;
    if (rect_.x < -1200) rect_.x += 1200;
}
void Base::Move6()
{
    rect_.x -= 3;
    if (rect_.x < 0) rect_.x += 1200;
}
void Base::Move7()
{
    rect_.x -= 4;
    if (rect_.x < -1200) rect_.x += 1200;
}
void Base::Move8()
{
    rect_.x -= 4;
    if (rect_.x < 0) rect_.x += 1200;
}
void Base::Move9()
{
    rect_.x -= 6;
    if (rect_.x < -1200) rect_.x += 1200;
}
void Base::Move10()
{
    rect_.x -= 6;
    if (rect_.x < 0) rect_.x += 1200;
}
