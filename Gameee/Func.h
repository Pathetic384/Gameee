#pragma once

#include <windows.h>
#include <vector>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <iostream>
static char g_name_main_right[] = { "img//player_right.png" };
static char helpme[] = { "D://VS//Gameee//Gameee//img//button.png" };

static  SDL_Window* g_window = NULL;
static SDL_Renderer* g_screen = NULL;
static SDL_Event g_event;

const int FRAMES_PER_SECOND = 60;
const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 600;
const int SCREEN_BPP = 32;
const int SPEED_SCREEN = 2;


const int RENDER_DRAW_COLOR = 0XFF;

const int COLOR_KEY_R = 255;
const int COLOR_KEY_G = 255;
const int COLOR_KEY_B = 255;

#define TILE_SIZE 64
#define BLANK_TILE 0

#define MAX_MAP_X 400
#define MAX_MAP_Y 10

#define NumQuit 7;


namespace Func
{

    bool CheckCollision(const SDL_Rect& object1, const SDL_Rect& object2);

}

typedef struct Input
{
    int left_;
    int right_;
    int up_;
    int down_;
    int jump_;
} Input;

typedef struct Map
{
    int start_x_;
    int start_y_;
    int max_x_;
    int max_y_;
    int tile[MAX_MAP_Y][MAX_MAP_X];
    const char* file_name_;
} Map;