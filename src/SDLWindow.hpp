#ifndef ENGINE_SDLWINDOW_H
#define ENGINE_SDLWINDOW_H

#include <SDL2/SDL.h>
#include <memory>
#include <string>

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

        class SDLWindow
        {
            public:
            SDLWindow()
            {
            }

            bool initialize( const std::string &window_name = "Game",
                             int screen_width               = 800,
                             int screen_height              = 600 );

            inline auto raw_pointer()
            {
                return game_window_.get();
            }

            private:
            std::unique_ptr< SDL_Window, SDLWindowDeleter > game_window_;
        };
    }
}
#endif
