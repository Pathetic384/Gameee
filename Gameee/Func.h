#pragma once

#include <windows.h>
#include <vector>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <iostream>

static  SDL_Window* g_window = NULL;
static SDL_Renderer* g_screen = NULL;

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


typedef struct Map
{
    int start_x_;
    int start_y_;
    int max_x_;
    int max_y_;
    int tile[MAX_MAP_Y][MAX_MAP_X];
    const char* file_name_;
} Map;