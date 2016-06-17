#include <SDL2/SDL.h>
#include <iostream>

const int SCREEN_WIDTH  = 800;
const int SCREEN_HEIGHT = 600;

int main()
{
    using std::cout;
    using std::endl;

    SDL_Window *game_window     = NULL;
    SDL_Surface *screen_surface = NULL;

    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
        return 1;
    }

    game_window = SDL_CreateWindow( "Primeiro Jogo",
                                    SDL_WINDOWPOS_CENTERED,
                                    SDL_WINDOWPOS_CENTERED,
                                    SCREEN_WIDTH,
                                    SCREEN_HEIGHT,
                                    SDL_WINDOW_SHOWN );
    if( game_window == NULL )
    {
        cout << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
        return 1;
    }

    screen_surface = SDL_GetWindowSurface( game_window );

    SDL_FillRect(
        screen_surface, NULL, SDL_MapRGB( screen_surface->format, 0xFF, 0xFF, 0xFF ) );

    SDL_UpdateWindowSurface( game_window );

    // Wait two seconds
    SDL_Delay( 2000 );

    // Destroy window
    SDL_DestroyWindow( game_window );

    // Quit SDL subsystems
    SDL_Quit();

    cout << "Game closed." << endl;

    return 0;
}
