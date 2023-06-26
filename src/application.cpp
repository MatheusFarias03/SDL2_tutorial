#include "../include/application.hpp"
#include <unistd.h>
#include <limits.h>


Application::Application()
{
    m_window = SDL_CreateWindow("SDL2 Window",
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                680, 480,
                                0);


    if(!m_window)
    {
        std::cout << "Failed to create window." << std::endl;
        std::cout << "SDL2 ERROR: " << SDL_GetError() << std::endl;
        return;
    }

    m_window_surface = SDL_GetWindowSurface(m_window);

    if(!m_window_surface)
    {
        std::cout << "Failed to get the surface from the window" << std::endl;
        std::cout << SDL_GetError() << std::endl;
        return;
    }
}


Application::~Application()
{
    SDL_FreeSurface(m_window_surface);
    SDL_DestroyWindow(m_window);
}


void Application::loop()
{
    bool keep_window_open = true;
    while(keep_window_open)
    {
        while(SDL_PollEvent(&m_window_event) > 0)
        {
            m_stick_figure.handle_events(m_window_event);
            switch(m_window_event.type)
            {
                case SDL_QUIT:
                    keep_window_open = false;
                    break;
                
                default:
                    break;
            }
        }

        update(1.0/60.0);
        draw();
    }
}


void Application::update(double delta_time)
{
    m_stick_figure.update(delta_time);
}


void Application::draw()
{
    SDL_FillRect(m_window_surface, nullptr, SDL_MapRGB(m_window_surface->format, 255, 255, 255));
    
    m_stick_figure.draw(m_window_surface);
    
    SDL_UpdateWindowSurface(m_window);
}