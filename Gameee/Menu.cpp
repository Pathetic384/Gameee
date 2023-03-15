#include "Menu.h"
#include <iostream>

Menu::Menu()
{

}
Menu::~Menu()
{

}


int Menu::CreateMenu(SDL_Renderer* screen)
{
    Base menu;
    bool ret1 = menu.LoadImg("img//genmenu.png", screen);
    if (ret1 == false) std::cout << 11;

    int b1 = 0;
    LButton but;
    but.LoadImg("img//button.png", screen);
    but.set_clips();
    but.Set(450, 30);

    int b2 = 0;
    LButton but2;
    but2.LoadImg("img//button.png", screen);
    but2.set_clips();
    but2.Set(450, 330);

    bool quit = false;
    SDL_Event e;
    while (quit == false)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                return 3;
            }
            but.handleEvent(&e,b1);
            but2.handleEvent(&e,b2);
        }
        menu.Render(screen);
        but.Show(screen);
        but2.Show(screen);

        SDL_RenderPresent(screen);

        if (b1 == 1) return 2;
        if (b2 == 1) return 3;
    }
    return 3;
}

int Menu::CreateLevels(SDL_Renderer* screen)
{
    Base menu;
    bool ret1 = menu.LoadImg("img//levels.png", screen);
    if (ret1 == false) std::cout << 11;

    int b1 = 0;
    LButton but;
    but.LoadImg("img//button.png", screen);
    but.set_clips();
    but.Set(450, 30);

    int b2 = 0;
    LButton but2;
    but2.LoadImg("img//button.png", screen);
    but2.set_clips();
    but2.Set(450, 330);

    bool quit = false;
    SDL_Event e;
    while (quit == false)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                return 3;
            }
            but.handleEvent(&e, b1);
            but2.handleEvent(&e, b2);
        }
        menu.Render(screen);
        but.Show(screen);
        but2.Show(screen);

        SDL_RenderPresent(screen);

        if (b1 == 1) return 4;
        if (b2 == 1) return 1;
    }
    return 1;
}

int Menu::CreateResult(SDL_Renderer* screen, int score)
{
    TTF_Font* font = TTF_OpenFont("vibe.ttf", 45);

    Base menu;
    bool ret1 = menu.LoadImg("img//res.png", screen);
    if (ret1 == false) std::cout << 11;

    int b2 = 0;
    LButton but2;
    but2.LoadImg("img//button.png", screen);
    but2.set_clips();
    but2.Set(450, 330);

    Text scorie;
    scorie.setColor(0);

    bool quit = false;
    SDL_Event e;
    while (quit == false)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                return 3;
            }
            but2.handleEvent(&e, b2);
        }
        menu.Render(screen);

        std::string finalscore = "Score: ";
        std::string temp = std::to_string(score);
        finalscore += temp;
        scorie.SetText(finalscore);
        scorie.loadFromRenderedText(font, screen);
        scorie.RenderText(screen, 550, 250);

        but2.Show(screen);

        SDL_RenderPresent(screen);

        if (b2 == 1) return 1;
    }
    return 1;
}

int Menu::CreatePause(SDL_Renderer* screen)
{
    Base menu;
    bool ret1 = menu.LoadImg("img//pause.png", screen);
    if (ret1 == false) std::cout << 11;

    int b1 = 0;
    LButton but;
    but.LoadImg("img//button.png", screen);
    but.set_clips();
    but.Set(450, 30);

    int b2 = 0;
    LButton but2;
    but2.LoadImg("img//button.png", screen);
    but2.set_clips();
    but2.Set(450, 330);

    bool quit = false;
    SDL_Event e;
    while (quit == false)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                return 3;
            }
            but.handleEvent(&e, b1);
            but2.handleEvent(&e, b2);
        }
        menu.Render(screen);
        but.Show(screen);
        but2.Show(screen);

        SDL_RenderPresent(screen);

        if (b1 == 1) return 4;
        if (b2 == 1) return 2;
    }
    return 1;
}
