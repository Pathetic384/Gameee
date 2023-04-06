#pragma once

#include "Func.h"
#include "Base.h"
#include "gamemap.h"
#include <iostream>
#include "Effects.h"


#define GRAVITY_SPEED 1
#define MAX_FALL_SPEED 10
#define PLAYER_HIGHT_VAL 15


class Char : public Base
{
public:
    Char();
    ~Char();

    void set_clips();
    bool LoadImg(std::string path, SDL_Renderer* screen);
    void Show(SDL_Renderer* des);
    void HandleInputAction(SDL_Event events, SDL_Renderer* screen);
    void SetMapXY(const int map_x, const int map_y) { map_x_ = map_x, map_y_ = map_y; };

    void Physics(Map& g_map, int speed);

    void Collide(Map& g_map, int& action);

    void CheckMode(Map& g_map, int& model, int& action);

    void SetSprite(int t);

    void Set()
    {
        x_pos_ = 100;
        y_pos_ = 0;
    }

    void SetSpeed(Map& map_data, int speed)
    {
        map_data.start_x_ += speed;
        x_val_ = speed;
    };
    
    void SetFrame()
    {
        frame_ = 0;
    }

    int GetX()
    {
        return rect_.x;
    }
    int GetY()
    {
        return rect_.y;
    }

private:

    bool is_jump_;
    int frame_;

    SDL_Rect frame_clip_[20];
    
    int jumping;
    int holding;

    bool on_ground_;
    bool dead;
    bool won;

    int map_x_;
    int map_y_;

    float x_val_;
    float y_val_;
    float x_pos_;
    float y_pos_;

    int movin;

    int mode;

    int width_frame_;
    int height_frame_;

    std::string move;
    std::string jump;
    std::string die;
    std::string win ;
    std::string ufo;
    std::string ufo_dead;
    std::string plane_up;
    std::string plane_down;
    std::string plane_dead;
};





/*
#define jumpval 20;

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

    void MapMo(Map& map_data, int move)
    {
        map_data.start_x_ += move;
    };

    bool LoadImg(std::string path, SDL_Renderer* screen);
    void Show(SDL_Renderer* des);
    //void HandleInputAction(SDL_Event events, SDL_Renderer * screen);

    void SetMapXY(const int map_x, const int map_y) { map_x_ = map_x, map_y_ = map_y; };

    void Movement(SDL_Event events, int x);
    void Set() {
        rect_.x = 130;
        rect_.y = 400;
    };

    void Mappa(Map& g_map, int x);

    void CheckEnd(Map& g_map, int x, int& end, int& speed);


private:

    SDL_Rect frame_clip_[54];
    int map_x_;
    int map_y_;

    int width_frame_;
    int height_frame_;

    int frame_;
    int status_;
    Input input_type_;

    Effects Eff;
    Effects Eff2;

    bool fly;
    bool ground;
    bool jump;
    bool jumping;
    bool hold;

    int down;
    int up;
    
    int t;
    int t2;
    int t3;
    int t4;
};
*/