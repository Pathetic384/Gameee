#include <iostream>
#include "Base.h"
#include "Func.h"
#include "Char.h"
#include "gamemap.h"
#include "Text.h"
#include "Timer.h"
#include <string>
#include "Menu.h"
#include "Buttons.h"
#include "Level.h"

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
    }
    return true;
}


void close()
{

    SDL_DestroyRenderer(g_screen);
    g_screen = NULL;

    SDL_DestroyWindow(g_window);
    g_window = NULL;

    IMG_Quit();
    SDL_Quit();
}


int main(int argc, char* argv[])
{
    if (InitData() == false)
    {
        return -1;
    }
    Menu menuing;
    Level lev;

    int action = 1;
    int score = 0;
    // 1 = to menu // 2 = to level // 3 = quit // 4 = to level // 5 = result

    while (action != 3)
    {
        if (action == 1)
        {
            action = menuing.CreateMenu(g_screen);
        }

        if (action == 3) break;

        if (action == 2)
        {
            Mix_HaltMusic();
            action = menuing.CreateLevels(g_screen, score);
        }

        if (action == 4)
        {
            action = lev.CreateLevel(g_screen, score);
        }

        if (action == 5)
        {
            action = menuing.CreateResult(g_screen, score);
        }

        if (action == 6)
        {
            //action = menuing.CreatePause(g_screen);
        }
    }
     close();
     return 0;
}







     /*
     g_background.LoadImg("img//paris.png", g_screen);
     Char p_player;
     p_player.LoadImg(g_name_main_right, g_screen);
     p_player.set_clips();
     p_player.Set();

     LButton butt;
     bool rett = butt.LoadImg(helpme, g_screen);
     if (rett == false) return 0;
     butt.set_clips();
     butt.Set(100,100);

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

     int v = 0;

     int x = 200;
     int mapend = 1;
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
                 break;
             }

             p_player.Movement(g_event, x);

             p_player.Mappa(help, t, g_event, run);
         }

         SDL_SetRenderDrawColor(g_screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
         SDL_RenderClear(g_screen);

         p_player.CheckEnd(help, t, mapend);
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
     close();*/
 