#include "Char.h"


Char::Char()
{
    move = "img//slime2//move.png";
    jump = "img//slime2//jump.png";
    die = "img//slime2//dead.png";
    win = "img//slime2//win.png";
    ufo = "img//slime2//ufo.png";
    ufo_dead = "img//slime2//ufo-dead.png";
    plane_up = "img//slime2//up.png";
    plane_down = "img//slime2//down.png";
    plane_dead = "img//slime2//plane-dead.png";

    frame_ = 0;
    x_pos_ = 0;
    y_pos_ = 0;
    x_val_ = 0;
    y_val_ = 0;
    
    width_frame_ = 0;
    height_frame_ = 0;
    
    on_ground_ = false;
    dead = false;
    won = false;

    jumping = 0;
    holding = 0;

    movin = 0;
    mode = 1;
}

Char::~Char()
{
    Free();
}

void Char::HandleInputAction(SDL_Event events, SDL_Renderer* screen)
{
    if (dead == false)
    {
        if (events.type == SDL_MOUSEBUTTONDOWN)
        {
            if (events.button.button == SDL_BUTTON_RIGHT)
            {
                jumping = 1;
                holding = 1;
            }
        }
        else if (events.type == SDL_MOUSEBUTTONUP)
        {
            if (events.button.button == SDL_BUTTON_RIGHT)
            {
                holding = 0;
            }
        }
    }
    else
    {
        jumping = 0;
        holding = 0;
    }
}


bool Char::LoadImg(std::string path, SDL_Renderer* screen)
{
    bool ret = Base::LoadImg(path, screen);

    if (ret == true)
    {
        width_frame_ = rect_.w / 20;
        height_frame_ = rect_.h;
    }

    return ret;
}

void Char::set_clips()
{
    for (int i = 0; i < 20; i++)
    {
        frame_clip_[i].x = width_frame_ * i;
        frame_clip_[i].y = 0;
        frame_clip_[i].w = width_frame_;
        frame_clip_[i].h = height_frame_;
    }
}

void Char::Show(SDL_Renderer* des)
{
    
    if (mode == 1)
    {
        if (dead == true || won == true)
        {
            if(dead == true)      LoadImg(die, des);
            else    LoadImg(win, des);
        }
        else
        {
            if (on_ground_ == true)   LoadImg(move, des);
            else  LoadImg(jump, des);
            set_clips();
            frame_++;
            if (frame_ >= 20)    frame_ = 0;
        }
    }
    if (mode == 2)
    {
        if (dead == true)
        {
            LoadImg(ufo_dead, des);
        }
        else
        {
            LoadImg(ufo, des);
            set_clips();
            frame_++;
            if (frame_ >= 20)    frame_ = 0;
        }
    }
        
    if (mode == 3)
    {
        if (dead == true)
        {
            LoadImg(plane_dead, des);
        }
        else
        {
            if (holding == true) LoadImg(plane_up, des);
            else   LoadImg(plane_down, des);
            set_clips();
            frame_++;
            if (frame_ >= 20)    frame_ = 0;
        }
    }

     
        rect_.x = x_pos_ -map_x_;
        rect_.y = y_pos_ -map_y_;

        SDL_Rect* currentClip = &frame_clip_[frame_];
        SDL_Rect renderQuad = { rect_.x, rect_.y, width_frame_, height_frame_ };
        if (currentClip != NULL)
        {
            renderQuad.w = currentClip->w;
            renderQuad.h = currentClip->h;
        }

        SDL_RenderCopy(des, p_object_, currentClip, &renderQuad);
    
}

void Char::Physics(Map& g_map, int speed)
{
 
    if (mode == 1 || mode == 2 || mode ==4)
    {
        y_val_ += GRAVITY_SPEED;

        if (y_val_ >= MAX_FALL_SPEED)
        {
            y_val_ = MAX_FALL_SPEED;
        }
    }

    if (mode == 1 || mode == 4)
    {
        if (jumping == 1)
        {
            if (on_ground_ == true)
            {
                y_val_ = -PLAYER_HIGHT_VAL;
            }
            on_ground_ = false;
            jumping = 0;
        }
        if (holding == 1)
        {
            if (on_ground_ == true)
            {
                y_val_ = -PLAYER_HIGHT_VAL;
            }
            on_ground_ = false;
        }
    }

    if (mode == 2)
    {
        if (jumping == 1)
        {
            y_val_ = -PLAYER_HIGHT_VAL;
            jumping = 0;
        }
    }

    if (mode == 3)
    {
        if (holding == 1)
        {
            y_val_ = -speed;
        }
        if (holding == 0)
        {
            y_val_ = speed;
        }
    }

}


void Char::Collide(Map& g_map, int& action)
{
    int x1 = 0;
    int x2 = 0;
    int y1 = 0;
    int y2 = 0;

    if (mode == 1 || mode == 2)
    {
        //Check Horizontal
        int height_min = height_frame_ < TILE_SIZE ? height_frame_ : TILE_SIZE;

        x1 = (x_pos_ + x_val_) / TILE_SIZE;
        x2 = (x_pos_ + x_val_ + width_frame_ - 1 - 10) / TILE_SIZE;

        y1 = (y_pos_) / TILE_SIZE;
        y2 = (y_pos_ + height_min - 1) / TILE_SIZE;

        if (x1 >= 0 && x2 < MAX_MAP_X && y1 >= 0 && y2 < MAX_MAP_Y)
        {
            if (x_val_ > 0)
            {
                int val1 = g_map.tile[y1][x2];
                int val2 = g_map.tile[y2][x2];

                if (val1 != 0 || val2 != 0)
                {
                    x_pos_ = x2 * TILE_SIZE;
                    x_pos_ -= width_frame_;
                    x_pos_ += 11;
                    x_val_ = 0;

                    action = 3;
                    dead = true;
                }

            }
        }

        // Check vertical
        int width_min = width_frame_ < TILE_SIZE ? width_frame_ : TILE_SIZE;

        x1 = (x_pos_ + 20) / TILE_SIZE;
        x2 = (x_pos_ + width_min) / TILE_SIZE;

        y1 = (y_pos_ + y_val_) / TILE_SIZE;
        y2 = (y_pos_ + y_val_ + height_frame_ - 1) / TILE_SIZE;

        if (x1 >= 0 && x2 < MAX_MAP_X && y1 >= 0 && y2 < MAX_MAP_Y)
        {
            if (y_val_ > 0)
            {
                //Similar for vertical
                int val1 = g_map.tile[y2][x1];
                int val2 = g_map.tile[y2][x2];


                if (val1 != 0 || val2 != 0)
                {
                    y_pos_ = y2 * TILE_SIZE;
                    y_pos_ -= height_frame_;
                    y_pos_ += 1;

                    y_val_ = 0;

                    on_ground_ = true;
                }

                if (val1 == 9 || val2 == 9)
                {
                    action = 3;
                    dead = true;
                }

            }
            else if (y_val_ < 0)
            {
                int val1 = g_map.tile[y1][x1];
                int val2 = g_map.tile[y1][x2];

                if ((val1 != BLANK_TILE) || (val2 != BLANK_TILE))
                {
                    y_pos_ = (y1 + 1) * TILE_SIZE;
                    //y_pos_ -= 10;
                    y_val_ = 0;
                }

            }
        }
    }
    else if (mode == 3)
    {
        //Check Horizontal
        int height_min = height_frame_ < TILE_SIZE ? height_frame_ : TILE_SIZE;

        x1 = (x_pos_ + x_val_) / TILE_SIZE;
        x2 = (x_pos_ + x_val_ + width_frame_ - 1 - 10) / TILE_SIZE;

        y1 = (y_pos_) / TILE_SIZE;
        y2 = (y_pos_ + height_min - 1) / TILE_SIZE;

        if (x1 >= 0 && x2 < MAX_MAP_X && y1 >= 0 && y2 < MAX_MAP_Y)
        {
            if (x_val_ > 0)
            {
                int val1 = g_map.tile[y1][x2];
                int val2 = g_map.tile[y2][x2];

                if (val1 != 0 || val2 != 0)
                {
                    x_pos_ = x2 * TILE_SIZE;
                    x_pos_ -= width_frame_;
                    x_pos_ += 11;
                    x_val_ = 0;

                    action = 3;
                    dead = true;
                }

            }
        }

        // Check vertical
        int width_min = width_frame_ < TILE_SIZE ? width_frame_ : TILE_SIZE;

        x1 = (x_pos_) / TILE_SIZE;
        x2 = (x_pos_ + width_min) / TILE_SIZE;

        y1 = (y_pos_ + y_val_) / TILE_SIZE;
        y2 = (y_pos_ + y_val_ + height_frame_ - 1) / TILE_SIZE;

        if (x1 >= 0 && x2 < MAX_MAP_X && y1 >= 0 && y2 < MAX_MAP_Y)
        {
            if (y_val_ > 0)
            {
                //Similar for vertical
                int val1 = g_map.tile[y2][x2];
                int val2 = g_map.tile[y2][x2];


                if (val1 != 0 || val2 != 0)
                {
                    y_pos_ = y2 * TILE_SIZE;
                    y_pos_ -= height_frame_;
                    y_pos_ += 1;

                    y_val_ = 0;

                    on_ground_ = true;
                }

                if (val1 == 9 || val2 == 9)
                {
                    action = 3;
                    dead = true;
                }

            }
            else if (y_val_ < 0)
            {
                int val1 = g_map.tile[y1][x2];
                int val2 = g_map.tile[y1][x2];

                if ((val1 != BLANK_TILE) || (val2 != BLANK_TILE))
                {
                    y_pos_ = (y1 + 1) * TILE_SIZE;
                    //y_pos_ -= 10;
                    y_val_ = 0;
                }

            }
        }
    }

    //If there is not collision with map tile. 
    x_pos_ += x_val_;
    y_pos_ += y_val_;


    if (y_pos_ < 0)
    {
        y_pos_ = 0;
    }
    else if (y_pos_ + height_frame_ >= 600)
    {
        y_pos_ = 600 - height_frame_;
    }
    
    
}


void Char::CheckMode(Map& g_map, int& model, int& action)
{
   int x = (x_pos_) / TILE_SIZE;

   if (g_map.tile[1][x] == 6)
   {
       mode = 2;
       model = mode;
   }

   if (g_map.tile[1][x] == 7)
   {
       mode = 3;
       model = mode;
   }

   if (g_map.tile[1][x] == 8)
   {
       mode = 1;
       model = mode;
   }

   if (g_map.tile[1][x] == 5)
   {
       action = 4;
       won = true;
   }
}

void Char::SetSprite(int sprite)
{
    if (sprite == 1)
    {
        move = "img//slime1//move.png";
        jump = "img//slime1//jump.png";
        die = "img//slime1//dead.png";
        win = "img//slime1//win.png";
        ufo = "img//slime1//ufo.png";
        ufo_dead = "img//slime1//ufo-dead.png";
        plane_up = "img//slime1//up.png";
        plane_down = "img//slime1//down.png";
        plane_dead = "img//slime1//plane-dead.png";
    }
    if (sprite == 2)
    {
        move = "img//slime2//move.png";
        jump = "img//slime2//jump.png";
        die = "img//slime2//dead.png";
        win = "img//slime2//win.png";
        ufo = "img//slime2//ufo.png";
        ufo_dead = "img//slime2//ufo-dead.png";
        plane_up = "img//slime2//up.png";
        plane_down = "img//slime1//down.png";
        plane_dead = "img//slime1//plane-dead.png";
    }
    if (sprite == 3)
    {
        move = "img//slime3//move.png";
        jump = "img//slime3//jump.png";
        die = "img//slime3//dead.png";
        win = "img//slime3//win.png";
        ufo = "img//slime3//ufo.png";
        ufo_dead = "img//slime3//ufo-dead.png";
        plane_up = "img//slime3//up.png";
        plane_down = "img//slime3//down.png";
        plane_dead = "img//slime3//plane-dead.png";
    }
    if (sprite == 4)
    {
        move = "img//slime4//move.png";
        jump = "img//slime4//jump.png";
        die = "img//slime4//dead.png";
        win = "img//slime4//win.png";
        ufo = "img//slime4//ufo.png";
        ufo_dead = "img//slime4//ufo-dead.png";
        plane_up = "img//slime4//up.png";
        plane_down = "img//slime4//down.png";
        plane_dead = "img//slime4//plane-dead.png";
    }
    if (sprite == 5)
    {
        move = "img//slime5//move.png";
        jump = "img//slime5//jump.png";
        die = "img//slime5//dead.png";
        win = "img//slime5//win.png";
        ufo = "img//slime5//ufo.png";
        ufo_dead = "img//slime5//ufo-dead.png";
        plane_up = "img//slime5//up.png";
        plane_down = "img//slime5//down.png";
        plane_dead = "img//slime5//plane-dead.png";
    }
}