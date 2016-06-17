#ifndef ENGINE_SDLBASE_H
#define ENGINE_SDLBASE_H

#include <SDL2/SDL.h>
#include <iostream>
#include <memory>

namespace game
{
namespace engine
{
    struct SDLWindowDeleter
    {
        void operator()( SDL_Window *window )
        {
            SDL_DestroyWindow( window );
        }
    };

    class SDLBase
    {
        public:
        SDLBase()
            : screen_surface_( NULL )
        {
        }
        ~SDLBase()
        {
            SDL_Quit();
        }

        bool initialize( const std::string &window_name = "Game",
                         int screen_width               = 800,
                         int screen_height              = 600 );

        inline auto const get_screen() const
        {
            return screen_surface_;
        }

        inline void update_screen()
        {
            SDL_UpdateWindowSurface( game_window_.get() );
        }

        inline void delay_ms( unsigned int delay_time )
        {
            SDL_Delay( delay_time );
        }

        private:
        std::unique_ptr< SDL_Window, SDLWindowDeleter > game_window_;
        SDL_Surface *screen_surface_;

        bool initialize_sdl();

        bool initialize_window( const std::string &window_name,
                                int screen_width,
                                int screen_height );

        bool initialize_screen_surface();
    };
}
}

#endif
