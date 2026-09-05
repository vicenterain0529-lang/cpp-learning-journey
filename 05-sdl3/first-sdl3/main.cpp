#include <SDL3/SDL.h>
#include <iostream>

int main() {
    int x = 0;
    int y = 0;
    // initialize SDL
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        std::cout << "SDL INITIALIZATION FAILED\n";
    }
    else {
        std::cout << "SDL INITIALIZATION SUCCESSFUL\n";
    }

    // creates window pointer with title, width, height and flags
    SDL_Window* window1 = SDL_CreateWindow(
        "SDL WINDOW 1",
        800,
        600,
        SDL_WINDOW_RESIZABLE | SDL_WINDOW_BORDERLESS
    );

    if (!window1) {
        std::cout << "WINDOW CREATION FAILED\n";
    }
    else {
        std::cout << "WINDOW CREATED SUCCESSFULLY\n";
    }

    SDL_Event event;

    bool isRunning = true;

    while (isRunning) {

        while (SDL_PollEvent(&event)) {

            if (event.type == SDL_EVENT_QUIT) {
                isRunning = false;
            }

            if (event.type == SDL_EVENT_KEY_DOWN) {

                auto keyPressed = event.key.key;

                std::cout << "KEY PRESSED: " << SDL_GetKeyName(keyPressed) << std::endl;

                if (keyPressed == SDLK_ESCAPE) {
                    isRunning = false;
                    std:: cout << "FINAL POSITION: X: " << x << " Y: " << y << std::endl;   
                }

                switch (keyPressed) {

                    case SDLK_W:
                        std::cout << "MOVED UP\n";
                        y--; 
                        std::cout << "X: " << x << " Y: " << y << std::endl;
                        break;

                    case SDLK_A:
                        std::cout << "MOVED LEFT\n";
                        x--;
                        std::cout << "X: " << x << " Y: " << y << std::endl;
                        break;

                    case SDLK_S:
                        std::cout << "MOVED DOWN\n";
                        y++;
                        std::cout << "X: " << x << " Y: " << y << std::endl;    
                        break;

                    case SDLK_D:
                        std::cout << "MOVED RIGHT\n";
                        x++;
                        std::cout << "X: " << x << " Y: " << y << std::endl;
                        break;
                }
            }
        }
    }

    SDL_Quit();

    return 0;
}