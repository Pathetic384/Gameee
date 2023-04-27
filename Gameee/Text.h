#pragma once
#include "Base.h"

class Text : public Base
{
public:
    Text();
    ~Text();

    enum TextColor
    {
        RED_TEXT = 0,
        WHITE_TEXT = 1,
        BLACK_TEXT = 2,
    };


    bool loadFromRenderedText(TTF_Font* gFont, SDL_Renderer* screen);
    void Free();
    void setColor(int type);

    void RenderText(SDL_Renderer* screen, int x, int y, SDL_Rect* clip = NULL);

    void SetText(const std::string& text) { str_val_ = text; }

private:
    std::string str_val_;
    SDL_Color text_color_;
    SDL_Texture* texture_;
    int width_;
    int height_;

};