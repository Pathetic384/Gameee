#include "Char.h"

Char::Char()
{
    frame_ = 0;
    width_frame_ = 0;
    height_frame_ = 0;
    status_ = 0;
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
        width_frame_ = rect_.w / 45;
        height_frame_ = rect_.h;
    }

    return ret;
}

void Char::set_clips()
{
     for (int i = 0; i < 45; ++i)
     {
       frame_clip_[i].x = width_frame_ * i;
       frame_clip_[i].y = 0;
       frame_clip_[i].w = width_frame_;
       frame_clip_[i].h = height_frame_;
     }  
}

void Char::Show(SDL_Renderer* des)
{

    if (status_ == 0)
    {
        if (input_type_.left_ == 0 && input_type_.right_ == 0)
        {
            frame_++;
        }
        if (frame_ >= 43)
        {
            frame_ = 0;
        }
        if (input_type_.left_ == 0 && input_type_.right_ == 1)
        {
            frame_ = 44;
        }
        if (input_type_.left_ == 1 && input_type_.right_ == 0)
        {
            frame_ = 43;
        }
    }

    if (status_ == 1)
    {
        if (input_type_.right_ == 1 && input_type_.left_ == 1) frame_++;

        if (frame_ >= 43)
        {
            frame_ = 0;
        }
        if (input_type_.left_ == 0 && input_type_.right_ == 1)
        {
            frame_ = 44;
        }
        if (input_type_.left_ == 1 && input_type_.right_ == 0)
        {
            frame_ = 43;
        }
    }


    SDL_Rect* currentClip = &frame_clip_[frame_];
    SDL_Rect renderQuad = { rect_.x, rect_.y, width_frame_, height_frame_ };


    SDL_RenderCopy(des, p_object_, currentClip, &renderQuad);

}

void Char::Movement(SDL_Event events, int x)
{
    if (events.type == SDL_KEYDOWN)
    {
        // while (x > 200) x -= 10;
        if (events.key.keysym.sym == SDLK_j)
        {
            rect_.y += 200;
            //status_ = WALK_RIGHT;
            input_type_.right_ = 1;
            status_ = 1;

        }
        else if (events.key.keysym.sym == SDLK_f)
        {
            rect_.y -= 200;
            //status_ = WALK_LEFT;
            input_type_.left_ = 1;
            status_ = 1;
        }
        if (rect_.y > 600) rect_.y -= 200;
        if (rect_.y < 0) rect_.y += 200;
    }
    else if (events.type == SDL_KEYUP)
    {
        if (events.key.keysym.sym == SDLK_j)
        {
            rect_.y -= 200;
            input_type_.right_ = 0;
            status_ = 0;
        }
        else if (events.key.keysym.sym == SDLK_f)
        {
            rect_.y += 200;
            input_type_.left_ = 0;
            status_ = 0;
        }
        if (rect_.y > 600) rect_.y -= 200;
        if (rect_.y < 0) rect_.y += 200;
    }
}

void Char::Mappa(Map& g_map, int x, SDL_Event event, int& run, SDL_Renderer* screen, int& ef, int& niw)
{
    int ak = 0;
    int x1 = x / TILE_SIZE; //(rect_.x) / TILE_SIZE ;
    int y1 = 1;//(rect_.y) / TILE_SIZE;
    int val = g_map.tile[y1][x1];
    int val2 = g_map.tile[8][x1];
    if (event.type == SDL_KEYDOWN)
    {
        if (event.key.keysym.sym == SDLK_f)
        {
            if (niw == 0)
            {
                if (val == 4)
                {
                    ak = 1;
                    g_map.tile[y1][x1] = 0;
                    StreakPlus(1);
                    PointPlus(2);
                    ef = 1;
                    niw = 1;
                }
                if (val == 3)
                {
                    ak = 1;
                    run = 1;
                    StreakPlus(1);
                    PointPlus(2);
                    ef = 1;
                }
                if (val == 6)
                {
                    streak = 0;
                    run = 0;
                    niw = 1;
                }
            }
        }
        if (event.key.keysym.sym == SDLK_j)
        {
            if (niw == 0)
            {
                if (val2 == 4)
                {
                    ak = 1;
                    g_map.tile[8][x1] = 0;
                    StreakPlus(1);
                    PointPlus(2);
                    ef = 3;
                    niw = 1;
                }
                if (val2 == 3)
                {
                    ak = 1;
                    run = 1;
                    StreakPlus(1);
                    PointPlus(2);
                    ef = 3;
                }
                if (val2 == 6)
                {
                    streak = 0;
                    run = 0;
                    niw = 1;
                }
            }
        }
    }
    if (event.type == SDL_KEYUP)
    {
        if (val != 3 || val2 !=3)
        {
            run = 0;
        }
        if (val == 6)
        {
            ef = 2;
        }
        if (val2 == 6)
        {
            ef = 4;
        }
        niw = 0;
    }

    if (ak == 0)
    {
        int x2 = x / TILE_SIZE + 1; //(rect_.x) / TILE_SIZE ;
        int y2 = 1;//(rect_.y) / TILE_SIZE;
        int val3 = g_map.tile[y2][x2];
        int val4 = g_map.tile[8][x2];
        if (event.type == SDL_KEYDOWN)
        {
            if (niw == 2) niw = 0;
            if (event.key.keysym.sym == SDLK_f)
            {
                if (niw == 0)
                {
                    if (val3 == 4)
                    {
                        g_map.tile[y2][x2] = 0;
                        StreakPlus(1);
                        PointPlus(1);
                        ef = 2;
                        niw = 1;
                    }
                    if (val3 == 3)
                    {
                        run = 1;
                        StreakPlus(1);
                        PointPlus(1);
                        ef = 2;
                    }
                    if (val3 == 6)
                    {
                        //streak = 0;
                        //run = 0;
                    }
                }
            }
            if (event.key.keysym.sym == SDLK_j)
            {
                if (niw == 0)
                {
                    if (val4 == 4)
                    {
                        g_map.tile[8][x2] = 0;
                        StreakPlus(1);
                        PointPlus(1);
                        ef = 4;
                        niw = 1;
                    }
                    if (val4 == 3)
                    {
                        run = 1;
                        StreakPlus(1);
                        PointPlus(1);
                        ef = 4;
                    }
                    if (val4 == 6)
                    {
                        //streak = 0;
                        //run = 0;
                    }
                }
            }
        }
        if (event.type == SDL_KEYUP)
        {
            if (val3 != 3 || val4!=3)
            {
                run = 0;
            }
            if (val3 == 6)
            {
                ef = 1;
            }
            if (val4 == 6)
            {
                ef = 3;
            }
            niw = 0;
        }
        
    }
    if (x >= MAX_MAP_X) x -= 5;


}

void Char::Long(Map& map, int x)
{
    int x1 = x / TILE_SIZE; ;//(rect_.x) / TILE_SIZE ;
    int y1 = 1;// (rect_.y) / TILE_SIZE;
    map.tile[y1][x1] = 0;
    map.tile[8][x1] = 0;
}

void Char::Long2(Map& map, int x, int& run, int& niw)
{
    int x1 = x / TILE_SIZE;//(rect_.x) / TILE_SIZE ;
    int y1 = 1;// (rect_.y) / TILE_SIZE;
    //std::cout << map.tile[y1][x1] << " ";
    if (map.tile[y1][x1] == 6)
    {
        run = 0;
        //niw = 0;
    }
    if (map.tile[8][x1] == 6)
    {
        run = 0;
        //niw = 0;
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
    int y2 = 8;
    //std::cout << g_map.tile[y1][x1] << " ";
    if (g_map.tile[y1][x1] == 4 || g_map.tile[y1][x1] == 3 || g_map.tile[y1][x1] == 5 || g_map.tile[y1][x1] == 9)
    {
        streak = 0;
    }
    if (g_map.tile[y2][x1] == 4 || g_map.tile[y2][x1] == 3 || g_map.tile[y2][x1] == 5 || g_map.tile[y2][x1] == 9)
    {
        streak = 0;
    }
    if (g_map.tile[y1][x1] == 7)
    {
        end = 0;
    }
}