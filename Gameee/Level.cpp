#include "Level.h"
#include <iostream>
#include "Effects.h"
#include "Res.h"

Level::Level()
{

}
Level::~Level()
{

}
int Level::CreateLevel(SDL_Renderer* screen, int& score)
{
    Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 4096);
    ImpTimer fps;
    TTF_Font* g_font_text = TTF_OpenFont("vibe.ttf", 45);

    Base layer11;
    layer11.LoadImg("img//bk1//1.png", screen);
    Base layer12;
    layer12.LoadImg("img//bk1//1.png", screen);
    layer12.SetRect(1200, 0);
    Base layer21;
    layer21.LoadImg("img//bk1//2.png", screen);
    Base layer22;
    layer22.LoadImg("img//bk1//2.png", screen);
    layer22.SetRect(1200, 0);
    Base layer31;
    layer31.LoadImg("img//bk1//3.png", screen);
    Base layer32;
    layer32.LoadImg("img//bk1//3.png", screen);
    layer32.SetRect(1200, 0);
    Base layer41;
    layer41.LoadImg("img//bk1//4.png", screen);
    Base layer42;
    layer42.LoadImg("img//bk1//4.png", screen);
    layer42.SetRect(1200, 0);
    Base layer51;
    layer51.LoadImg("img//bk1//5.png", screen);
    Base layer52;
    layer52.LoadImg("img//bk1//5.png", screen);
    layer52.SetRect(1200, 0);
    Base layer61;
    layer61.LoadImg("img//bk1//6.png", screen);
    Base layer62;
    layer62.LoadImg("img//bk1//6.png", screen);
    layer62.SetRect(1200, 0);

    Char p_player;
    p_player.LoadImg("img//char.png", screen);
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

    Effects eff;
    eff.LoadImg("img//ee.png", screen);
    eff.set_clips();
    eff.Set(120, 80);
    Res good;
    good.LoadImg("img//good.png", screen);
    good.set_clips();
    good.Set(120, 180);
    Res perfect;
    perfect.LoadImg("img//perfect.png", screen);
    perfect.set_clips();
    perfect.Set(120, 180);

    Effects eff2;
    eff2.LoadImg("img//ee.png", screen);
    eff2.set_clips();
    eff2.Set(120, 500);
    Res good2;
    good2.LoadImg("img//good.png", screen);
    good2.set_clips();
    good2.Set(120, 400);
    Res perfect2;
    perfect2.LoadImg("img//perfect.png", screen);
    perfect2.set_clips();
    perfect2.Set(120, 400);

    GameMap game_map;
    game_map.LoadMap("map//map01.dat");
    game_map.LoadMapTiles(screen);

    Mix_Music* mus;
    mus = Mix_LoadMUS("songs//Roll.mp3");
    Mix_PlayMusic(mus, 1);
    Mix_PauseMusic();

    Text textin;
    textin.setColor(2);

    Text pointin;
    pointin.setColor(2);

    int run = 0;
    int xmove = 0;
    double t = 160;

    int idk = 0;

    int speed = 0;
    int speedtemp = 0;

    int niw = 0;
    int v = 0;
    int v2 = 0;
    int ef = 0;

    int x = 200;
    int mapend = 1;
    bool is_quit = false;
    SDL_Event e;
    while (is_quit == false)
    {
        v2 = 0;
        Map help = game_map.GetMap();

        if (mapend == 1)
        {
            p_player.MapMo(help, speed);
            t += speed;
        }

        while (SDL_PollEvent(&e))
        {

            if (e.type == SDL_QUIT)
            {
                is_quit = true;
                Mix_HaltMusic();
                return 3;
                break;
            }

            p_player.Movement(e, x);
            butt.handleEvent(e, v);
            butt2.handleEvent(e, v2);
            p_player.Mappa(help, t, e, run, screen, ef, niw);
        }

        SDL_SetRenderDrawColor(screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
        SDL_RenderClear(screen);

        p_player.CheckEnd(help, t, mapend);
        p_player.Long2(help, t, run, niw);

        //int bonusspeed = speed * 2;
        


        if (run == 1)
        {
            p_player.Long(help, t);
            p_player.StreakPlus(0.1);
            p_player.PointPlus(0.1);
        }

        if (idk == 1)
        {
            layer11.Move();
            layer12.Move2();
            layer21.Move3();
            layer22.Move4();
            layer31.Move5();
            layer32.Move6();
            layer41.Move7();
            layer42.Move8();
            layer51.Move7();
            layer52.Move8();
            layer61.Move9();
            layer62.Move10();
        }   

        layer11.Render(screen, NULL);
        layer12.Render(screen, NULL);
        layer21.Render(screen, NULL);
        layer22.Render(screen, NULL);
        layer31.Render(screen, NULL);
        layer32.Render(screen, NULL);
        layer41.Render(screen, NULL);
        layer42.Render(screen, NULL);
        layer51.Render(screen, NULL);
        layer52.Render(screen, NULL);
        layer61.Render(screen, NULL);
        layer62.Render(screen, NULL);

        butt.Show(screen);
        butt2.Show(screen);
        p_player.Show(screen);

        game_map.SetMap(help);
        game_map.DrawMap(screen);

        if (ef != 0)
        {
            if (ef == 1)
            {
                eff.Reset();
                perfect.Reset();
            }
            if (ef == 2)
            {
                eff.Reset();
                good.Reset();
            }
            if (ef == 3)
            {
                eff2.Reset();
                perfect2.Reset();
            }
            if (ef == 4)
            {
                eff2.Reset();
                good2.Reset();
            }
        }
        good.Show(screen);
        perfect.Show(screen);
        eff.Show(screen);
        good2.Show(screen);
        perfect2.Show(screen);
        eff2.Show(screen);
        ef = 0;

        textin.Free();
        pointin.Free();

        int poi = p_player.GetStreak();
        std::string poin = std::to_string(poi);
        std::string point = "Streak: ";
        point += poin;
        textin.SetText(point);
        textin.loadFromRenderedText(g_font_text, screen);
        textin.RenderText(screen, SCREEN_WIDTH * 0.5, 20);

        int r = p_player.GetPoint();
        std::string re = std::to_string(r);
        std::string res = "Points: ";
        res += re;
        pointin.SetText(res);
        pointin.loadFromRenderedText(g_font_text, screen);
        pointin.RenderText(screen, 20, 20);

        SDL_RenderPresent(screen);
       
        if (mapend == 0)
        {
            Mix_HaltMusic();

            return 5;
        }
        if (v == 1)
        {
            Mix_PauseMusic();
            Menu temp;
            int tmp = temp.CreatePause(screen);
            if (tmp == 4 && idk == 1)
            {
                v = 0;
                Mix_ResumeMusic();
            }
            else if (tmp == 4 && idk == 0)
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
            idk = 1;
            Mix_ResumeMusic();
            speed = 8;
            butt2.Free();
        }

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






/**
int Level::CreateLevel(SDL_Renderer* screen, int& score)
{
    Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 4096);
    ImpTimer fps;
    TTF_Font* g_font_text = TTF_OpenFont("vibe.ttf", 45);

    Base g_background;
    g_background.LoadImg("img//paris.png", screen);
    Char p_player;
    p_player.LoadImg(g_name_main_right, screen);
    p_player.set_clips();
    p_player.Set();

    LButton butt;
    bool rett = butt.LoadImg(helpme, screen);
    if (rett == false) return 0;
    butt.set_clips();
    butt.Set(1000, 100);

    GameMap game_map;
    game_map.LoadMap("map//map01.dat");
    game_map.LoadMapTiles(screen);

    Mix_Music* mus;
    mus = Mix_LoadMUS("RushE.mp3");
    Mix_PlayMusic(mus, 1);
    
    Text textin;
    textin.setColor(2);

    Text pointin;
    pointin.setColor(2);

    int run = 0;
    int xmove = 0;
    int t = 160;

    int v = 0;

    int x = 200;
    int mapend = 1;
    bool is_quit = false;
    SDL_Event e;
    while (is_quit == false)
    {
        Map help = game_map.GetMap();

        if (mapend == 1)
        {
            p_player.MapMo(help);
            t += 5;
        }

        while (SDL_PollEvent(&e))
        {

            if (e.type == SDL_QUIT)
            {
                is_quit = true;
                Mix_HaltMusic();
                return 2;
                break;
            }

            p_player.Movement(e, x);
            butt.handleEvent(&e, v);
            p_player.Mappa(help, t, e, run);
        }

        SDL_SetRenderDrawColor(screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
        SDL_RenderClear(screen);

        p_player.CheckEnd(help, t, mapend);
        p_player.Long2(help, t, run);
        if (run == 1)
        {
            p_player.Long(help, t);
            p_player.StreakPlus(0.1);
            p_player.PointPlus(0.1);
        }


        g_background.Render(screen, NULL);

        butt.Show(screen);
        p_player.Show(screen);

        game_map.SetMap(help);
        game_map.DrawMap(screen);

        

        int poi = p_player.GetStreak();
        std::string poin = std::to_string(poi);
        std::string point = "Streak: ";
        point += poin;
        textin.SetText(point);
        textin.loadFromRenderedText(g_font_text, screen);
        textin.RenderText(screen, SCREEN_WIDTH * 0.5, 20);

        int r = p_player.GetPoint();
        std::string re = std::to_string(r);
        std::string res = "Points: ";
        res += re;
        pointin.SetText(res);
        pointin.loadFromRenderedText(g_font_text, screen);
        pointin.RenderText(screen, 20, 20);

        SDL_RenderPresent(screen);
        int imp_time = fps.get_ticks();
        int time_for_one_frame = 1000 / FRAMES_PER_SECOND;
        if (imp_time < time_for_one_frame)
        {
            SDL_Delay(time_for_one_frame - imp_time);
        }

        if (mapend == 0)
        {
            Mix_HaltMusic();
            score = p_player.GetPoint();
            return 5;
        }
        if (v == 1)
        {
            Mix_HaltMusic();
            return 6;
        }
    }
    //close();
    Mix_HaltMusic();
    return 3;
}

*/