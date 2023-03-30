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
    menu.LoadImg("img//menu//01.png", screen);
    Base menu2;
    menu2.LoadImg("img//menu//01.png", screen);
    menu2.SetRect(1200, 0);
    Base menu3;
    menu3.LoadImg("img//menu//02.png", screen);
    Base menu4;
    menu4.LoadImg("img//menu//02.png", screen);
    menu4.SetRect(1200, 0);
    Base menu5;
    menu5.LoadImg("img//menu//03.png", screen);
    Base menu6;
    menu6.LoadImg("img//menu//03.png", screen);
    menu6.SetRect(1200, 0);
    Base menu7;
    menu7.LoadImg("img//menu//04.png", screen);
    Base menu8;
    menu8.LoadImg("img//menu//04.png", screen);
    menu8.SetRect(1200, 0);

    Base menu9;
    menu9.LoadImg("img//menu//05.png", screen);

    int b1 = 0;
    Button but;
    but.LoadImg("img//buttons//continue.png", screen);
    but.set_button_clips(200);
    but.Set(160, 300);

    int b2 = 0;
    Button but2;
    but2.LoadImg("img//buttons//close.png", screen);
    but2.set_button_clips(150);
    but2.Set(530, 450);

    int b3 = 0;
    Button but3;
    but3.LoadImg("img//buttons//tutorial.png", screen);
    but3.set_button_clips(200);
    but3.Set(840, 300);

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
            but3.handleEvent(e, b3);
        }

        SDL_SetRenderDrawColor(screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
        SDL_RenderClear(screen);

        menu.Render(screen);
        menu.Move();
        menu2.Render(screen);
        menu2.Move2();

        menu3.Render(screen);
        menu3.Move3();
        menu4.Render(screen);
        menu4.Move4();

        menu5.Render(screen);
        menu5.Move5();
        menu6.Render(screen);
        menu6.Move6();

        menu7.Render(screen);
        menu7.Move7();
        menu8.Render(screen);
        menu8.Move8();

        menu9.Render(screen);

        but.Show(screen);
        but2.Show(screen);
        but3.Show(screen);
       

        SDL_RenderPresent(screen);
       
        SDL_Delay(100);
        

        if (b1 == 1) return 2;
        if (b2 == 1) return 3;
        if (b3 == 1) return 7;
    }
    return 3;
}

int Menu::CreateLevels(SDL_Renderer* screen, int& score, int& score2, int& score3, int& score4, int& per, int& per2, int& per3, int& per4)
{

    Base menu;
    menu.LoadImg("img//levels.png", screen);

    int b1 = 0;
    Button but;
    but.LoadImg("img//buttons//play.png", screen);
    but.set_button_clips(75);
    but.Set(295, 150);

    int b2 = 0;
    Button but2;
    but2.LoadImg("img//buttons//return.png", screen);
    but2.set_button_clips(65);
    but2.Set(1125, 10);

    int b3 = 0;
    Button but3;
    but3.LoadImg("img//buttons//play.png", screen);
    but3.set_button_clips(75);
    but3.Set(835, 150);

    int b4 = 0;
    Button but4;
    but4.LoadImg("img//buttons//play.png", screen);
    but4.set_button_clips(75);
    but4.Set(295, 435);

    int b5 = 0;
    Button but5;
    but5.LoadImg("img//buttons//play.png", screen);
    but5.set_button_clips(75);
    but5.Set(835, 435);

    Text scorie;
    scorie.setColor(0);
    Text scori;
    scori.setColor(0);
    Text perc;
    perc.setColor(0);

    Text scorie2;
    scorie2.setColor(0);
    Text scori2;
    scori2.setColor(0);
    Text perc2;
    perc2.setColor(0);

    Text scorie3;
    scorie3.setColor(0);
    Text scori3;
    scori3.setColor(0);
    Text perc3;
    perc3.setColor(0);

    Text scorie4;
    scorie4.setColor(0);
    Text scori4;
    scori4.setColor(0);
    Text perc4;
    perc4.setColor(0);


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
            but3.handleEvent(e, b3);
            but4.handleEvent(e, b4);
            but5.handleEvent(e, b5);
        }
        SDL_SetRenderDrawColor(screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
        SDL_RenderClear(screen);

        menu.Render(screen);
        but.Show(screen);
        but2.Show(screen);
        but3.Show(screen);
        but4.Show(screen);
        but5.Show(screen);


        std::string highscore = "HighScore:";
        scorie.SetText(highscore);
        std::string tmp = std::to_string(score);
        scori.SetText(tmp);
        std::string highscore2 = "HighScore:";
        scorie2.SetText(highscore2);
        std::string tmp2 = std::to_string(score2);
        scori2.SetText(tmp2);
        std::string highscore3 = "HighScore:";
        scorie3.SetText(highscore3);
        std::string tmp3 = std::to_string(score3);
        scori3.SetText(tmp3);
        std::string highscore4 = "HighScore:";
        scorie4.SetText(highscore4);
        std::string tmp4 = std::to_string(score4);
        scori4.SetText(tmp4);

        std::string percent = "Completion:";
        std::string temp = std::to_string(per);
        percent += temp;
        percent += '%';
        perc.SetText(percent);
        std::string percent2 = "Completion:";
        std::string temp2 = std::to_string(per2);
        percent2 += temp2;
        percent2 += '%';
        perc2.SetText(percent2);
        std::string percent3 = "Completion:";
        std::string temp3 = std::to_string(per3);
        percent3 += temp3;
        percent3 += '%';
        perc3.SetText(percent3);
        std::string percent4 = "Completion:";
        std::string temp4 = std::to_string(per4);
        percent4 += temp4;
        percent4 += '%';
        perc4.SetText(percent4);
        

        scorie.loadFromRenderedText(font, screen);
        scorie.RenderText(screen, 250,25);
        scori.loadFromRenderedText(font, screen);
        scori.RenderText(screen, 250, 70);
        perc.loadFromRenderedText(font3, screen);
        perc.RenderText(screen, 240, 110);

        scorie2.loadFromRenderedText(font, screen);
        scorie2.RenderText(screen, 785, 25);
        scori2.loadFromRenderedText(font, screen);
        scori2.RenderText(screen, 785, 70);
        perc2.loadFromRenderedText(font3, screen);
        perc2.RenderText(screen, 775, 110);

        scorie3.loadFromRenderedText(font, screen);
        scorie3.RenderText(screen, 250, 310);
        scori3.loadFromRenderedText(font, screen);
        scori3.RenderText(screen, 250, 355);
        perc3.loadFromRenderedText(font3, screen);
        perc3.RenderText(screen, 240, 399);

        scorie4.loadFromRenderedText(font, screen);
        scorie4.RenderText(screen, 785, 310);
        scori4.loadFromRenderedText(font, screen);
        scori4.RenderText(screen, 785, 355);
        perc4.loadFromRenderedText(font3, screen);
        perc4.RenderText(screen, 775, 395);

        SDL_RenderPresent(screen);

        SDL_Delay(150);

        if (b1 == 1) return 4;
        if (b2 == 1) return 1;
        if (b3 == 1) return 8;
        if (b4 == 1) return 9;
        if (b5 == 1) return 10;
    }
    return 3;
}

int Menu::CreateResult(SDL_Renderer* screen, int& score, int& high_score, int& per)
{
    Base menu;
    bool ret1 = menu.LoadImg("img//res.png", screen);
    if (ret1 == false) std::cout << 11;

    if (score > high_score) high_score = score;

    int b2 = 0;
    Button but2;
    but2.LoadImg("img//buttons//menu.png", screen);
    but2.set_button_clips(200);
    but2.Set(970, 245);

    Text scorie;
    scorie.setColor(0);

    Text high;
    high.setColor(0);

    Text percent;
    percent.setColor(1);

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

        std::string temp = std::to_string(score);
        scorie.SetText(temp);
        scorie.loadFromRenderedText(font2, screen);
        scorie.RenderText(screen, 550, 250);

        std::string temp2 = std::to_string(high_score);
        high.SetText(temp2);
        high.loadFromRenderedText(font2, screen);
        high.RenderText(screen, 550, 400);

        double tmp = high_score * 100;
        tmp = tmp / 500;

        per = tmp;
        std::string temp3 = std::to_string(per);
        std::string percentage;
        percentage += temp3;
        percentage += '%';
        percent.SetText(percentage);
        percent.loadFromRenderedText(font2, screen);
        percent.RenderText(screen, 800, 95);

        but2.Show(screen);

        SDL_RenderPresent(screen);

        SDL_Delay(100);

        if (b2 == 1) return 2;
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
    but.LoadImg("img//buttons//continue.png", screen);
    but.set_button_clips(200);
    but.Set(285, 250);

    int b2 = 0;
    Button but2;
    but2.LoadImg("img//buttons//menu.png", screen);
    but2.set_button_clips(200);
    but2.Set(800, 250);

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

        SDL_Delay(100);

        if (b1 == 1) return 4;
        if (b2 == 1) return 2;
    }
    return 3;
}

int Menu::CreateTutorial(SDL_Renderer* screen)
{
    int page = 1;
    Base p1;
    p1.LoadImg("img//tutorial//1.png", screen);
    Base p2;
    p2.LoadImg("img//tutorial//2.png", screen);
    Base p3;
    p3.LoadImg("img//tutorial//3.png", screen);
    Base p4;
    p4.LoadImg("img//tutorial//4.png", screen);
    Base p5;
    p5.LoadImg("img//tutorial//5.png", screen);
    Base p6;
    p6.LoadImg("img//tutorial//6.png", screen);
    Base p7;
    p7.LoadImg("img//tutorial//7.png", screen);
    Base p8;
    p8.LoadImg("img//tutorial//8.png", screen);
    Base p9;
    p9.LoadImg("img//tutorial//9.png", screen);


    int b1 = 0;
    Button but;
    but.LoadImg("img//buttons//backward.png", screen);
    but.set_button_clips(100);
    but.Set(0, 250);

    int b2 = 0;
    Button but2;
    but2.LoadImg("img//buttons//foward.png", screen);
    but2.set_button_clips(100);
    but2.Set(1100, 250);

    int b3 = 0;
    Button but3;
    but3.LoadImg("img//buttons//ok.png", screen);
    but3.set_button_clips(100);
    but3.Set(1100, 250);

    bool quit = false;
    SDL_Event e;
    while (quit == false)
    {
        b1 = 0;
        b2 = 0;
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
                return 3;
            }
            but.handleEvent(e, b1);
            but2.handleEvent(e, b2);
            but3.handleEvent(e, b2);
        }

        SDL_SetRenderDrawColor(screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
        SDL_RenderClear(screen);

        if (b1 == 1) page--;
        if (b2 == 1) page++;
        if (page < 1) page = 1;
        
        if (page == 1)
        {
            p1.Render(screen, NULL);
        }
        if (page == 2)
        {
            p2.Render(screen, NULL);
        }
        if (page == 3)
        {
            p3.Render(screen, NULL);
        }
        if (page == 4)
        {
            p4.Render(screen, NULL);
        }
        if (page == 5)
        {
            p5.Render(screen, NULL);
        }
        if (page == 6)
        {
            p6.Render(screen, NULL);
        }
        if (page == 7)
        {
            p7.Render(screen, NULL);
        }
        if (page == 8)
        {
            p8.Render(screen, NULL);
        }
        if (page == 9)
        {
            p9.Render(screen, NULL);
        }
        

        if (page > 1)
        {
            but.Show(screen);
        }
        
        if (page > 9) return 1;
        if (page < 9)
        {
            but2.Show(screen);
        }
        if (page == 9) but3.Show(screen);


        SDL_RenderPresent(screen);
        
        SDL_Delay(100);
    }
    return 3;
}
