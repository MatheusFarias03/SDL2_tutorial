#pragma once

#include <SDL2/SDL.h>


enum class Direction
{
    NONE,
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class StickFigure
{
public:
    StickFigure();
    ~StickFigure() = default;

    void update(double delta_time);
    void draw(SDL_Surface *window_surface);
    void handle_events(SDL_Event const &event);

private:
    SDL_Surface *m_image;
    SDL_Rect    m_position;
    double      m_x;
    double      m_y;
    Direction   m_direction; 
};