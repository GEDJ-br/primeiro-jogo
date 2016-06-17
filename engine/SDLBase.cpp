#include "SDLBase.hpp"

namespace game
{
namespace engine
{
    bool SDLBase::initialize( const std::string &window_name,
                              int screen_width,
                              int screen_height )
    {
        return initialize_sdl() &&
               initialize_window( window_name, screen_width, screen_height ) &&
               initialize_screen_surface();
    }

    bool SDLBase::initialize_sdl()
    {
        // SDL_INIT_TIMER
        //     timer subsystem
        // SDL_INIT_AUDIO
        //     audio subsystem
        // SDL_INIT_VIDEO
        //     video subsystem. Automatically initializes the SDL_INIT_EVENTS
        //     subsystem
        // SDL_INIT_JOYSTICK
        //     joystick subsystem
        // SDL_INIT_HAPTIC
        //     haptic (force feedback) subsystem
        // SDL_INIT_GAMECONTROLLER
        //     controller subsystem. Automatically initializes the SDL_INIT_JOYSTICK
        //     subsystem
        // SDL_INIT_EVENTS
        //     events subsystem
        // SDL_INIT_EVERYTHING
        //     all of the above subsystems
        return SDL_Init( SDL_INIT_VIDEO ) >= 0;
    }

    bool SDLBase::initialize_window( const std::string &window_name,
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

        return game_window_ != nullptr;
    }

    bool SDLBase::initialize_screen_surface()
    {
        screen_surface_ = SDL_GetWindowSurface( game_window_.get() );

        return screen_surface_ != nullptr;
    }
}
}
