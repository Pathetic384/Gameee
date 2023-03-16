#include "Level.h"
#include <iostream>

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
    TTF_Font* g_font_text = TTF_OpenFont("D://VS//Gameee//Gameee//vibe.ttf", 45);

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
    while (is_quit == false)
    {
        Map help = game_map.GetMap();

        if (mapend == 1)
        {
            p_player.MapMo(help);
            t += 5;
        }

        while (SDL_PollEvent(&g_event))
        {

            if (g_event.type == SDL_QUIT)
            {
                is_quit = true;
                Mix_HaltMusic();
                return 2;
                break;
            }

            p_player.Movement(g_event, x);
            butt.handleEvent(&g_event, v);
            p_player.Mappa(help, t, g_event, run);
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