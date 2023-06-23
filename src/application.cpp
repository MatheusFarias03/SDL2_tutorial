#include "../include/application.hpp"
#include <unistd.h>
#include <limits.h>


// Helper function to load BMP images.
SDL_Surface *load_surface(char const *path)
{
    SDL_Surface *image_surface = SDL_LoadBMP(path);

    if(!image_surface)
        return 0;

    return image_surface;
}


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

    m_image = load_surface("src/snail.bmp");

    m_image_position.x = 0;
    m_image_position.y = 0;
    m_image_position.w = 256;
    m_image_position.h = 256;
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
    m_image_x = m_image_x + (5 * delta_time);
    m_image_position.x = m_image_x;
}


void Application::draw()
{
    SDL_UpdateWindowSurface(m_window);
    SDL_FillRect(m_window_surface, NULL, SDL_MapRGB(m_window_surface->format, 0, 0, 0));
    SDL_BlitSurface(m_image, NULL, m_window_surface, &m_image_position);
}