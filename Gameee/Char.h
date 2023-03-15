#pragma once

#include "Func.h"
#include "Base.h"
#include "gamemap.h"
#include <iostream>

#define Char_Width 230
#define Char_Height 230

class Char : public Base
{
public:
    Char();
    ~Char();

    enum WalkType
    {
        WALK_NONE = 0,
        WALK_RIGHT = 1,
        WALK_LEFT = 2,
    };

    void set_clips();

    void MapMo(Map& map_data)
    {
        map_data.start_x_ += 5;
    };

    bool LoadImg(std::string path, SDL_Renderer* screen);
    void Show(SDL_Renderer* des);
    //void HandleInputAction(SDL_Event events, SDL_Renderer * screen);

    void SetMapXY(const int map_x, const int map_y) { map_x_ = map_x, map_y_ = map_y; };

    void Movement(SDL_Event events, int x);
    void Set() {
        rect_.x = 120;
        rect_.y = 270;
    };

    void Mappa(Map& g_map, int x, SDL_Event event, int& run);

    void Long(Map& g_map, int x);
    void Long2(Map& g_map, int x, int& run);

    int GetStreak();
    void StreakPlus(double x);

    void CheckEnd(Map& g_map, int x, int& end);

    void PointPlus(double x);
    int GetPoint();
private:

    SDL_Rect frame_clip_[8];
    int map_x_;
    int map_y_;

    float x_val_;
    float y_val_;
    float x_pos_;
    float y_pos_;

    int width_frame_;
    int height_frame_;

    int frame_;
    int status_;
    Input input_type_;

    double streak;
    double points;
};
