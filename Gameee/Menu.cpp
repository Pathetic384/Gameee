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

    Effects Eff;
    bool ret = Eff.LoadImg("img//ee.png", screen);
    if (ret == false) std::cout << 111;
    Eff.set_clips();
    Eff.Set(300, 300);

    Particle* particles[20];
    //for(int i=0;i<20;i++)
       //bool ret3 = 
      // particles[1]->LoadMedia(screen);
       //if (ret == false) std::cout << 111;
    

    int b1 = 0;
    Button but;
    but.LoadImg("img//button.png", screen);
    but.set_clips();
    but.Set(450, 30);

    int b2 = 0;
    Button but2;
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
                quit = true;
                return 3;
            }
            but.handleEvent(e,b1);
            but2.handleEvent(e,b2);
        }

        SDL_SetRenderDrawColor(screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
        SDL_RenderClear(screen);

        menu.Render(screen);
        but.Show(screen);
        but2.Show(screen);
       
        Eff.Show(screen);


        SDL_RenderPresent(screen);
        SDL_Delay(1);

        if (b1 == 1) return 2;
        if (b2 == 1) return 3;
    }
    return 3;
}

int Menu::CreateLevels(SDL_Renderer* screen, int& score)
{
    Base menu;
    bool ret1 = menu.LoadImg("img//levels.png", screen);
    if (ret1 == false) std::cout << 11;

    int b1 = 0;
    Button but;
    but.LoadImg("img//button.png", screen);
    but.set_clips();
    but.Set(450, 30);

    int b2 = 0;
    Button but2;
    but2.LoadImg("img//button.png", screen);
    but2.set_clips();
    but2.Set(450, 330);

    Text scorie;
    scorie.setColor(0);
    std::string highscore = "HighScore: ";
    std::string tmp = std::to_string(score);
    highscore += tmp;
    scorie.SetText(highscore);

    bool quit = false;
    SDL_Event e;
    while (quit == false)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
                return 3;
            }
            but.handleEvent(e, b1);
            but2.handleEvent(e, b2);
        }
        SDL_SetRenderDrawColor(screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
        SDL_RenderClear(screen);

        menu.Render(screen);
        but.Show(screen);
        but2.Show(screen);

        scorie.loadFromRenderedText(font, screen);
        scorie.RenderText(screen, 100,100);

        SDL_RenderPresent(screen);
        SDL_Delay(10);

        if (b1 == 1) return 4;
        if (b2 == 1) return 1;
    }
    return 3;
}

int Menu::CreateResult(SDL_Renderer* screen, int& score)
{
    Base menu;
    bool ret1 = menu.LoadImg("img//res.png", screen);
    if (ret1 == false) std::cout << 11;

    int b2 = 0;
    Button but2;
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
                quit = true;
                return 3;
            }
            but2.handleEvent(e, b2);
        }
        SDL_SetRenderDrawColor(screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
        SDL_RenderClear(screen);

        menu.Render(screen);

        std::string finalscore = "Score: ";
        std::string temp = std::to_string(score);
        finalscore += temp;
        scorie.SetText(finalscore);
        scorie.loadFromRenderedText(font, screen);
        scorie.RenderText(screen, 550, 250);

        but2.Show(screen);

        SDL_RenderPresent(screen);
        SDL_Delay(10);

        if (b2 == 1) return 1;
    }
    return 3;
}

int Menu::CreatePause(SDL_Renderer* screen)
{
    Base menu;
    bool ret1 = menu.LoadImg("img//pause.png", screen);
    if (ret1 == false) std::cout << 11;

    int b1 = 0;
    Button but;
    but.LoadImg("img//button.png", screen);
    but.set_clips();
    but.Set(450, 30);

    int b2 = 0;
    Button but2;
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
                quit = true;
                return 3;
            }
            but.handleEvent(e, b1);
            but2.handleEvent(e, b2);
        }
        SDL_SetRenderDrawColor(screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
        SDL_RenderClear(screen);

        menu.Render(screen);
        but.Show(screen);
        but2.Show(screen);

        SDL_RenderPresent(screen);
        SDL_Delay(10);

        if (b1 == 1) return 4;
        if (b2 == 1) return 2;
    }
    return 3;
}

