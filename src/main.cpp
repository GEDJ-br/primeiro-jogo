#include <SDL2/SDL.h>
#include <iostream>
#include <memory>

#include "SDLBase.hpp"

namespace ge = game::engine;

int main()
{
    using std::cout;
    using std::endl;

    ge::SDLBase base;

    if( !base.initialize() )
    {
        cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
        return 1;
    }

    auto screen_surface = base.get_screen();

    SDL_FillRect(
        screen_surface, NULL, SDL_MapRGB( screen_surface->format, 0xFF, 0xFF, 0xFF ) );

    base.update_screen();

    // Wait two seconds
    base.delay_ms( 2000 );

    cout << "Game closed." << endl;

    return 0;
}
