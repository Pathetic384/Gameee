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
    //The final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface != NULL)
    {
        //Color key image
        //SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, COLOR_KEY_R, COLOR_KEY_G, COLOR_KEY_B));

        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface(screen, loadedSurface);
        if (newTexture != NULL)
        {
            //Get image dimensions
            rect_.w = loadedSurface->w;
            rect_.h = loadedSurface->h;
        }

        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    //Return success
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

bool Base::CheckRect(const int& x, const int& y, const SDL_Rect& rect)
{
    if (x >= rect.x && x <= rect.x + rect.w && y >= rect.y && y <= rect.y + rect.h)
    {
        return true;
    }
    return false;
}

