#include <iostream>
#include "Base.h";
#include "Func.h";
#include "Char.h";
#include "gamemap.h";
#include "Text.h";
#include "Timer.h";
#include <string>;

Base g_background;
TTF_Font* g_font_text = NULL;

bool InitData()
{
    int ret = SDL_Init(SDL_INIT_VIDEO);
    if (ret < 0) return false;

    //Create window
    g_window = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (g_window == NULL)
    {
        return false;
    }
    else
    {
        g_screen = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);
        if (g_screen == NULL)
            return false;
        else
        {
            SDL_SetRenderDrawColor(g_screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
            int imgFlags = IMG_INIT_PNG;
            if (!(IMG_Init(imgFlags) && imgFlags))
                return false;
        }
        if (SDL_Init(SDL_INIT_AUDIO) < 0) return false;

        if (TTF_Init() == -1)
        {
            return false;
        }
        g_font_text = TTF_OpenFont("D://VS//sdl2cl//sdl2cl//vibe.ttf", 45);
        if (g_font_text == NULL)
        {
            return false;
        }

    }
    return true;
}

bool LoadBackground()
{
    bool ret = g_background.LoadImg("img//paris.png", g_screen);
    if (ret == false)
    {
        return false;
    }
    return true;
}

void close()
{
    g_background.Free();

    SDL_DestroyRenderer(g_screen);
    g_screen = NULL;

    SDL_DestroyWindow(g_window);
    g_window = NULL;

    IMG_Quit();
    SDL_Quit();
}


int main(int argc, char* argv[])
{
    Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 4096);
    ImpTimer fps;
    if (InitData() == false)
    {
        return -1;
    }
    if (!LoadBackground())
    {
        return -1;
    }

    Char p_player;
    p_player.LoadImg(g_name_main_right, g_screen);
    p_player.set_clips();
    p_player.Set();

    GameMap game_map;
    game_map.LoadMap("map//map01.dat");
    game_map.LoadMapTiles(g_screen);

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
    bool is_quit = false;
    int x = 200;
    while (is_quit == false)
    {
        Map help = game_map.GetMap();
 
        p_player.MapMo(help);
        t += 5;

        while (SDL_PollEvent(&g_event))
        {

            if (g_event.type == SDL_QUIT)
            {
                is_quit = true;
                break;
            }
            // p_player.HandleInputAction(g_event, g_screen);
            p_player.Movement(g_event, x);


            p_player.Mappa(help, t, g_event, run);
        }

        SDL_SetRenderDrawColor(g_screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
        SDL_RenderClear(g_screen);

        p_player.CheckEnd(help, t);
        p_player.Long2(help, t, run);
        if (run == 1)
        {
            p_player.Long(help, t);
            p_player.StreakPlus(0.1);
            p_player.PointPlus(0.1);
        }


        g_background.Render(g_screen, NULL);

        p_player.Show(g_screen);

        game_map.SetMap(help);
        game_map.DrawMap(g_screen);

        int poi = p_player.GetStreak();
        std::string poin = std::to_string(poi);
        std::string point = "Streak: ";
        point += poin;
        textin.SetText(point);
        textin.loadFromRenderedText(g_font_text, g_screen);
        textin.RenderText(g_screen, SCREEN_WIDTH * 0.5, 20);

        int r = p_player.GetPoint();
        std::string re = std::to_string(r);
        std::string res = "Points: ";
        res += re;
        pointin.SetText(res);
        pointin.loadFromRenderedText(g_font_text, g_screen);
        pointin.RenderText(g_screen, 20, 20);

        SDL_RenderPresent(g_screen);
        int imp_time = fps.get_ticks();
        int time_for_one_frame = 1000 / FRAMES_PER_SECOND;
        if (imp_time < time_for_one_frame)
        {
            SDL_Delay(time_for_one_frame - imp_time);
        }
    }
    close();
    return 0;
}
