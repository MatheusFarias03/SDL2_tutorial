#pragma once

#include <SDL2/SDL.h>
#include "../include/spritesheet.hpp"

class StickFigure
{
public:

    enum class Direction
    {
        NONE,
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

    StickFigure();
    ~StickFigure() = default;

    void update(double delta_time);
    void draw(SDL_Surface *window_surface);
    void handle_events(SDL_Event const &event);

private:
    Spritesheet m_spritesheet;
    Direction   m_direction; 
    int         m_spritesheet_column;

    SDL_Rect    m_position;
    double      m_x;
    double      m_y;
};