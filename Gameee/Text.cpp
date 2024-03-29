#include "Text.h"

Text::Text()
{
    text_color_.r = 255;
    text_color_.g = 255;
    text_color_.b = 255;
}


Text::~Text()
{
}


bool Text::loadFromRenderedText(TTF_Font* gFont, SDL_Renderer* screen)
{
    SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, str_val_.c_str(), text_color_);
    if (textSurface != NULL)
    {
        texture_ = SDL_CreateTextureFromSurface(screen, textSurface);
        if (texture_ != NULL)
        {
            width_ = textSurface->w;
            height_ = textSurface->h;
        }
        SDL_FreeSurface(textSurface);
    }

    return texture_ != NULL;
}

void Text::Free()
{
    if (texture_ != NULL)
    {
        SDL_DestroyTexture(texture_);
        texture_ = NULL;
    }
}


void Text::setColor(int type)
{
    if (type == RED_TEXT)
    {
        SDL_Color color = { 255, 0, 0 };
        text_color_ = color;
    }
    else if (type == WHITE_TEXT)
    {
        SDL_Color color = { 255, 255, 255 };
        text_color_ = color;
    }
    else
    {
        SDL_Color color = { 0, 0, 0 };
        text_color_ = color;
    }
}
void Text::RenderText(SDL_Renderer* screen, int x, int y, SDL_Rect* clip )
{
    SDL_Rect renderQuad = { x, y, width_, height_ };

    if (clip != NULL)
    {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }

    SDL_RenderCopy(screen, texture_, clip, &renderQuad);
}