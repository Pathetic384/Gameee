
#include "Level3.h"
#include <iostream>
#include "Effects.h"
#include "Res.h"

Level3::Level3()
{

}
Level3::~Level3()
{

}
int Level3::CreateLevel(SDL_Renderer* screen, int& high_score, int sprite, int& percentage)
{
    Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 4096);
    ImpTimer fps;
    TTF_Font* g_font_text = TTF_OpenFont("vibe.ttf", 45);

    Base layer11;
    Base layer12;
    layer12.SetRect(1200, 0);
    Base layer21;
    Base layer22;
    layer22.SetRect(1200, 0);
    Base layer31;
    Base layer32;
    layer32.SetRect(1200, 0);
    Base layer41;
    Base layer42;
    layer42.SetRect(1200, 0);
    Base layer51;
    Base layer52;
    layer52.SetRect(1200, 0);
    Base layer61;
    Base layer62;
    layer62.SetRect(1200, 0);

    Base res;
    res.LoadImg("img//res.png", screen);
    res.SetRect(230, 100);

    Char p_player;
    p_player.SetSprite(sprite);
    //p_player.LoadImg("img//slime1//move.png", screen);
    p_player.set_clips();
    p_player.Set();

    Button butt;
    butt.LoadImg("img//buttons//pausebutton.png", screen);
    butt.set_button_clips(65);
    butt.Set(1125, 10);

    Button butt2;
    butt2.LoadImg("img//buttons//continue.png", screen);
    butt2.set_button_clips(200);
    butt2.Set(500, 300);

    Button butt3;
    butt3.LoadImg("img//buttons//greturn.png", screen);
    butt3.set_button_clips(100);
    butt3.Set(870, 260);

    Button butt4;
    butt4.LoadImg("img//buttons//gmenu.png", screen);
    butt4.set_button_clips(100);
    butt4.Set(240, 260);

    Effects eff;
    eff.LoadImg("img//ee.png", screen);
    eff.set_clips();

    Effects exx;
    if (sprite == 1)        exx.LoadImg("img//ex1.png", screen);
    if (sprite == 2)       exx.LoadImg("img//ex2.png", screen);
    if (sprite == 3)       exx.LoadImg("img//ex3.png", screen);
    if (sprite == 4)       exx.LoadImg("img//ex4.png", screen);
    if (sprite == 5)       exx.LoadImg("img//ex5.png", screen);
    exx.set_clips();

    GameMap game_map;
    game_map.LoadMap("map3//map01.dat");
    game_map.LoadMapTiles3(screen);

    Mix_Music* mus;
    mus = Mix_LoadMUS("songs//Jojo.mp3");
    Mix_PlayMusic(mus, 1);
    Mix_PauseMusic();

    Text pointin;
    pointin.setColor(2);
    Text resin;
    resin.setColor(0);
    Text perc;
    perc.setColor(0);

    int startin = 0;

    int explode = 0;

    double poi = 0;

    int speed = 0;

    int action = 0;
    int mode = 1;

    int m1 = 0;
    int m2 = 0;
    int m3 = 0;

    //buttons
    int v = 0;
    int v2 = 0;
    int v3 = 0;
    int v4 = 0;

    bool is_quit = false;
    SDL_Event e;
    while (is_quit == false)
    {
        //Free
        pointin.Free();
        perc.Free();
        resin.Free();
        p_player.Free();
        //Events
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_KEYDOWN)
            {
                if (action != 3 && action != 4)
                {
                    if (e.key.keysym.sym == SDLK_SPACE)
                    {
                        v = 1;
                    }
                }
            }
            if (e.type == SDL_QUIT)
            {
                is_quit = true;
                Mix_HaltMusic();
                return 3;
                break;
            }

            p_player.HandleInputAction(e, screen);

            butt.handleEvent(e, v);
            butt2.handleEvent(e, v2);
            butt3.handleEvent(e, v3);
            butt4.handleEvent(e, v4);
        }

        SDL_SetRenderDrawColor(screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
        SDL_RenderClear(screen);


        Map ga_map = game_map.GetMap();
        p_player.Collide(ga_map, action);
        p_player.CheckMode(ga_map, mode, action);
        if (action == 3)
        {
            if (explode == 0) exx.Reset();
            speed = 0;
            startin = 0;
            explode = 1;
        }
        if (action == 4)
        {
            eff.Reset();
            speed = 0;
            startin = 0;
        }

        //Load background
        if (mode == 1)
        {
            if (m1 == 0)
            {
                layer11.LoadImg("img//bk3//1.png", screen);       layer12.LoadImg("img//bk3//1.png", screen);
                layer21.LoadImg("img//bk3//2.png", screen);       layer22.LoadImg("img//bk3//2.png", screen);
                layer31.LoadImg("img//bk3//3.png", screen);       layer32.LoadImg("img//bk3//3.png", screen);
                layer41.LoadImg("img//bk3//4.png", screen);       layer42.LoadImg("img//bk3//4.png", screen);
                layer51.LoadImg("img//bk3//5.png", screen);       layer52.LoadImg("img//bk3//5.png", screen);
            }
            m1 = 1;
            m2 = 0;
            m3 = 0;
        }
        if (mode == 2)
        {
            if (m2 == 0)
            {
                layer11.LoadImg("img//bk3//2//1.png", screen);       layer12.LoadImg("img//bk3//2//1.png", screen);
                layer21.LoadImg("img//bk3//2//2.png", screen);       layer22.LoadImg("img//bk3//2//2.png", screen);
                layer31.LoadImg("img//bk3//2//3.png", screen);       layer32.LoadImg("img//bk3//2//3.png", screen);
                layer41.LoadImg("img//bk3//2//4.png", screen);       layer42.LoadImg("img//bk3//2//4.png", screen);
                layer51.LoadImg("img//bk3//2//5.png", screen);       layer52.LoadImg("img//bk3//2//5.png", screen);
            }
            m1 = 0;
            m2 = 1;
            m3 = 0;
        }
        if (mode == 3)
        {
            if (m3 == 0)
            {
                layer11.LoadImg("img//bk3//3//1.png", screen);       layer12.LoadImg("img//bk3//3//1.png", screen);
                layer21.LoadImg("img//bk3//3//2.png", screen);       layer22.LoadImg("img//bk3//3//2.png", screen);
                layer31.LoadImg("img//bk3//3//3.png", screen);       layer32.LoadImg("img//bk3//3//3.png", screen);
                layer41.LoadImg("img//bk3//3//4.png", screen);       layer42.LoadImg("img//bk3//3//4.png", screen);
                layer51.LoadImg("img//bk3//3//5.png", screen);       layer52.LoadImg("img//bk3//3//5.png", screen);
            }
            m1 = 0;
            m2 = 0;
            m3 = 1;
        }

        if (startin == 1)
        {
            layer11.Move();          layer12.Move2();
            layer21.Move3();         layer22.Move4();
            layer31.Move5();         layer32.Move6();
            layer41.Move7();         layer42.Move8();
            layer51.Move7();         layer52.Move8();
            layer61.Move9();         layer62.Move10();
        }
        layer11.Render(screen, NULL);       layer12.Render(screen, NULL);
        layer21.Render(screen, NULL);       layer22.Render(screen, NULL);
        layer31.Render(screen, NULL);       layer32.Render(screen, NULL);
        layer41.Render(screen, NULL);       layer42.Render(screen, NULL);
        layer51.Render(screen, NULL);       layer52.Render(screen, NULL);
        layer61.Render(screen, NULL);       layer62.Render(screen, NULL);

        //Game start
        if (startin == 1)
        {
            p_player.SetSpeed(ga_map, speed);
        }
        //Lost / Havent started
        if (startin == 0)
        {
            p_player.SetSpeed(ga_map, speed);
            p_player.SetFrame();
        }

        //Set map
        game_map.SetMap(ga_map);
        game_map.DrawMap(screen);

        p_player.SetMapXY(ga_map.start_x_, ga_map.start_y_);
        p_player.Physics(ga_map, speed);

        //Render
        p_player.Show(screen);
        butt.Show(screen);
        butt2.Show(screen);

        int x = p_player.GetX() - 10;
        int y = p_player.GetY() + 5;
        eff.Set(x, y);
        eff.Show(screen);
        exx.Set(x, y);
        exx.Show(screen);

        //Show point
        if (action != 3 && startin != 0) poi += 0.1;
        int poin = round(poi);
        std::string re = std::to_string(poin);
        std::string s = "Points: ";
        s += re;
        pointin.SetText(s);
        pointin.loadFromRenderedText(g_font_text, screen);
        pointin.RenderText(screen, 530, 20);

        //Set result
        resin.SetText(re);
        resin.loadFromRenderedText(g_font_text, screen);

        int percent = poi * 100;
        percent /= 303;
        percent += 1;
        if (poi == 303)
        {
            std::string re2 = std::to_string(100);
            re2 += '%';
            perc.SetText(re2);
        }
        else
        {
            std::string re2 = std::to_string(percent);
            re2 += '%';
            perc.SetText(re2);
        }
        perc.loadFromRenderedText(g_font_text, screen);

        //Show result
        if (action == 3 || action == 4)
        {
            if (action == 3)     Mix_HaltMusic();
            res.Render(screen, NULL);
            if (action == 3)      butt3.Show(screen);
            butt4.Show(screen);
            resin.RenderText(screen, 590, 265);
            perc.RenderText(screen, 590, 360);
            butt.Free();
            if (v3 == 1)
            {
                Mix_HaltMusic();
                return 9;
            }
            if (v4 == 1)
            {
                if (poin > high_score) high_score = poin;
                if (percent + 1> percentage) percentage = percent + 1;
                Mix_HaltMusic();
                return 2;
            }
        }

        SDL_RenderPresent(screen);

        //Button events
        if (v == 1)
        {
            Mix_PauseMusic();
            Menu temp;
            int tmp = temp.CreatePause(screen);
            if (tmp == 4 && startin == 1)
            {
                v = 0;
                Mix_ResumeMusic();
            }
            else if (tmp == 4 && startin == 0)
            {
                v = 0;
            }
            else if (tmp == 2)
            {
                Mix_HaltMusic();
                return 2;
            }
        }

        if (v2 == 1)
        {
            startin = 1;
            Mix_ResumeMusic();
            speed = 8;
            butt2.Free();
        }

        //Delay
        int imp_time = fps.get_ticks();
        int time_for_one_frame = 1000 / FRAMES_PER_SECOND;
        if (imp_time < time_for_one_frame)
        {
            SDL_Delay(time_for_one_frame - imp_time);
        }
    }
    //close();
    Mix_HaltMusic();
    return 3;
}