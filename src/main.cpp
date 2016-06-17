#include <SDL2/SDL.h>
#include <iostream>
#include <memory>

#include "SDLWindow.hpp"

namespace ge = game::engine;

int main()
{
    using std::cout;
    using std::endl;

    ge::SDLWindow game_window;

    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
        return 1;
    }

    if( !game_window.initialize( "Primeiro Jogo" ) )
    {
        return 1;
    }

    SDL_Surface *screen_surface = NULL;
    screen_surface              = SDL_GetWindowSurface( game_window.raw_pointer() );

    SDL_FillRect(
        screen_surface, NULL, SDL_MapRGB( screen_surface->format, 0xFF, 0xFF, 0xFF ) );

    SDL_UpdateWindowSurface( game_window.raw_pointer() );

    // Wait two seconds
    SDL_Delay( 2000 );

    // Quit SDL subsystems
    SDL_Quit();

    cout << "Game closed." << endl;

    return 0;
}
