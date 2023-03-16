#include "Char.h"

Char::Char()
{
    frame_ = 0;
    x_pos_ = 0;
    y_pos_ = 0;
    x_val_ = 0;
    y_val_ = 0;
    width_frame_ = 0;
    height_frame_ = 0;
    status_ = -1;
    input_type_.left_ = 0;
    input_type_.right_ = 0;
    input_type_.down_ = 0;
    input_type_.jump_ = 0;
    input_type_.up_ = 0;
    streak = 0;
    points = 0;
}
Char::~Char()
{

}

bool Char::LoadImg(std::string path, SDL_Renderer* screen)
{
    bool ret = Base::LoadImg(path, screen);

    if (ret == true)
    {
        width_frame_ = rect_.w / 8;
        height_frame_ = rect_.h;
    }

    return ret;
}

void Char::set_clips()
{
    //Clip the sprites
    if (width_frame_ > 0 && height_frame_ > 0)
    {
        frame_clip_[0].x = 0;
        frame_clip_[0].y = 0;
        frame_clip_[0].w = width_frame_;
        frame_clip_[0].h = height_frame_;

        frame_clip_[1].x = width_frame_;
        frame_clip_[1].y = 0;
        frame_clip_[1].w = width_frame_;
        frame_clip_[1].h = height_frame_;

        frame_clip_[2].x = width_frame_ * 2;
        frame_clip_[2].y = 0;
        frame_clip_[2].w = width_frame_;
        frame_clip_[2].h = height_frame_;

        frame_clip_[3].x = width_frame_ * 3;

        frame_clip_[3].y = 0;
        frame_clip_[3].w = width_frame_;
        frame_clip_[3].h = height_frame_;

        frame_clip_[4].x = width_frame_ * 4;
        frame_clip_[4].y = 0;
        frame_clip_[4].w = width_frame_;
        frame_clip_[4].h = height_frame_;

        frame_clip_[5].x = width_frame_ * 5;
        frame_clip_[5].y = 0;
        frame_clip_[5].w = width_frame_;
        frame_clip_[5].h = height_frame_;

        frame_clip_[6].x = width_frame_ * 6;
        frame_clip_[6].y = 0;
        frame_clip_[6].w = width_frame_;
        frame_clip_[6].h = height_frame_;

        frame_clip_[7].x = width_frame_ * 7;
        frame_clip_[7].y = 0;
        frame_clip_[7].w = width_frame_;
        frame_clip_[7].h = height_frame_;
    }
}

void Char::Show(SDL_Renderer* des)
{

    if (input_type_.right_ == 1 && input_type_.left_ == 1) frame_++;

    else if (input_type_.right_ == 0 && input_type_.left_ == 0) frame_++;

    else if (input_type_.right_ == 1 || input_type_.left_ == 1)
    {
        frame_ = 1;

    }



    if (frame_ >= 8)
    {
        frame_ = 0;
    }


    SDL_Rect* currentClip = &frame_clip_[frame_];
    SDL_Rect renderQuad = { rect_.x, rect_.y, width_frame_, height_frame_ };


    SDL_RenderCopy(des, p_object_, currentClip, &renderQuad);

}

void Char::Movement(SDL_Event events, int x)
{
    if (events.type == SDL_MOUSEBUTTONDOWN)
    {
        // while (x > 200) x -= 10;
        if (events.button.button == SDL_BUTTON_LEFT)
        {
            rect_.y += x;
            //status_ = WALK_RIGHT;
            input_type_.right_ = 1;

        }
        else if (events.button.button == SDL_BUTTON_RIGHT)
        {
            rect_.y -= x;
            //status_ = WALK_LEFT;
            input_type_.left_ = 1;

        }
    }
    else if (events.type == SDL_MOUSEBUTTONUP)
    {
        if (events.button.button == SDL_BUTTON_LEFT)
        {
            rect_.y -= x;
            input_type_.right_ = 0;
        }
        else if (events.button.button == SDL_BUTTON_RIGHT)
        {
            rect_.y += x;
            input_type_.left_ = 0;
        }
    }
}

void Char::Mappa(Map& g_map, int x, SDL_Event event, int& run)
{
    int x1 = x / TILE_SIZE; ;//(rect_.x) / TILE_SIZE ;
    int y1 = (rect_.y) / TILE_SIZE;
    int val = g_map.tile[y1][x1];
    if (event.type == SDL_MOUSEBUTTONDOWN)
    {
        if (val == 4)
        {
            g_map.tile[y1][x1] = 0;
            StreakPlus(1);
            PointPlus(1);
        }
        if (val == 3)
        {
            run = 1;
            StreakPlus(1);
            PointPlus(1);
        }
    }
    if (event.type == SDL_MOUSEBUTTONUP)
    {
        if (val != 3)
        {
            run = 0;
        }
    }
    if (x >= MAX_MAP_X) x -= 5;
}

void Char::Long(Map& map, int x)
{
    int x1 = x / TILE_SIZE; ;//(rect_.x) / TILE_SIZE ;
    int y1 = (rect_.y) / TILE_SIZE;
    map.tile[y1][x1] = 0;
}

void Char::Long2(Map& map, int x, int& run)
{
    int x1 = x / TILE_SIZE; ;//(rect_.x) / TILE_SIZE ;
    int y1 = (rect_.y) / TILE_SIZE;
    //std::cout << map.tile[y1][x1] << " ";
    if (map.tile[y1][x1] == 4)
    {
        run = 0;
    }
   
}

void Char::StreakPlus(double x)
{
    streak += x;
}

int Char::GetStreak()
{
    return streak;
}
int Char::GetPoint()
{
    return points;
}
void Char::PointPlus(double x)
{
    if (streak < 10)
    {
        points += 5*x;
    }
    else if (streak < 20)
    {
        points += 10*x;
    }
    else if (streak < 50)
    {
        points += 15*x;
    }

}

void Char::CheckEnd(Map& g_map, int x, int& end)
{
    int x1 = x / TILE_SIZE - 1;
    int y1 = 1;
    int y2 = 9;
    std::cout << g_map.tile[y1][x1] << " ";
    if (g_map.tile[y1][x1] != 0)
    {
        streak = 0;
    }
    if (g_map.tile[y1][x1] == 7)
    {
        end = 0;
    }
}