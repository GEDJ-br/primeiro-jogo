#include "SDLWindow.hpp"

namespace game
{
    namespace engine
    {
        bool SDLWindow::initialize( const std::string &window_name,
                                    int screen_width,
                                    int screen_height )
        {
            game_window_ = std::unique_ptr< SDL_Window, SDLWindowDeleter >(
                SDL_CreateWindow( window_name.c_str(),
                                  SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED,
                                  screen_width,
                                  screen_height,
                                  SDL_WINDOW_SHOWN ) );

            return game_window_ == nullptr;
        }
    }
}
