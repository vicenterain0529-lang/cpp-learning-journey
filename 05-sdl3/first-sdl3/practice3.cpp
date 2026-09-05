#include <SDL3/SDL.h>
#include <iostream>

SDL_Window* windowCreation();
void windowValidation(SDL_Window* window);
SDL_Renderer* rendererCreation(SDL_Window* window);
void eventHandling(SDL_Event& event, bool& isRunning, int& x, int & y, int& colorState, SDL_Renderer* rendered);
void handleEvents(SDL_Event& event, bool& isRunning, int& x, int& y, int& colorState, SDL_Renderer* rendered);
void handleMouse(SDL_Event& event, int& mouseX, int& mouseY);
void handleKeyboard(SDL_Event& event, bool& isRunning, int& x, int& y, int& colorState);
void handleMovement(int& x, int& y);
void rendererValidation(SDL_Renderer* rendered);
void render(SDL_Renderer* rendered, int x, int y, int mouseX, int mouseY, int colorState);

int main()
{
    int x = 500;
    int y = 400;
    int mouseX = 500;
    int mouseY = 400;
    int colorState = 0;

    bool isRunning = true;
    SDL_Event event;

    SDL_Window* window = windowCreation();
    SDL_Renderer* rendered = rendererCreation(window);

    windowValidation(window);
    rendererValidation(rendered);

    while (isRunning)
    {
        eventHandling(event, isRunning, x, y, colorState, rendered);

        render(rendered, x, y, mouseX, mouseY, colorState);

        SDL_Delay(16);
    }

    SDL_DestroyRenderer(rendered);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

SDL_Window* windowCreation()
{
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        std::cout << "SDL WINDOW INITIALIZATION FAILED\n";
    }
    else
    {
        std::cout << "SDL WINDOW INITIALIZATION SUCCESS!\n";
    }

    SDL_Window* window = SDL_CreateWindow(
        "RAIN WINDOW",
        1000,
        800,
        SDL_WINDOW_RESIZABLE | SDL_WINDOW_BORDERLESS
    );

    return window;
}

void windowValidation(SDL_Window* window)
{
    if (!window)
    {
        std::cout << "Window Creation Failed: "
                  << SDL_GetError() << '\n';

        SDL_Quit();
    }
    else
    {
        std::cout << "Window Creation Success\n";
    }
}

SDL_Renderer* rendererCreation(SDL_Window* window)
{
    SDL_Renderer * rendered = SDL_CreateRenderer(window, NULL);
    return rendered;
}

void rendererValidation(SDL_Renderer* rendered)
{
    if (!rendered)
    {
        std::cout << "Renderer Creation Failed: "
                  << SDL_GetError() << '\n';

        SDL_Quit();
    }
    else
    {
        std::cout << "Renderer Creation Success\n";
    }
}

void eventHandling(SDL_Event& event, bool& isRunning, int& x, int& y, int& colorState, SDL_Renderer* rendered)
{
    handleEvents(event, isRunning, x, y, colorState, rendered);
    handleMovement(x, y);
}

void handleEvents(SDL_Event& event, bool& isRunning, int& x, int& y, int& colorState, SDL_Renderer* rendered)
{
    static int mouseX = 500;
    static int mouseY = 400;

    while (SDL_PollEvent(&event))
    {
        handleMouse(event, mouseX, mouseY);
        handleKeyboard(event, isRunning, x, y, colorState);

        if (event.type == SDL_EVENT_QUIT)
        {
            isRunning = false;
            SDL_Log("FINAL POSITION: X: %d Y: %d", x, y);
        }
    }
}

void handleMouse(SDL_Event& event, int& mouseX, int& mouseY)
{
    if (event.type == SDL_EVENT_MOUSE_BUTTON_DOWN)
    {
        auto mouseButton = event.button.button;

        if (mouseButton == SDL_BUTTON_LEFT)
        {
            mouseX = event.button.x;
            mouseY = event.button.y;

            std::cout << "Mouse X: " << mouseX;
            std::cout << " Mouse Y: " << mouseY << '\n';
        }
    }
}

void handleKeyboard(SDL_Event& event, bool& isRunning, int& x, int& y, int& colorState)
{
    if (event.type == SDL_EVENT_KEY_DOWN)
    {
        if (event.key.key == SDLK_ESCAPE)
        {
            isRunning = false;

            SDL_Log("FINAL POSITION: X: %d Y: %d", x, y);
        }
        else if (event.key.key == SDLK_R)
        {
            colorState++;

            if (colorState > 3)
            {
                colorState = 0;
            }
        }
    }
}

void handleMovement(int& x, int& y)
{
    const bool* keyboardState = SDL_GetKeyboardState(nullptr);

    bool moved = false;

    if (keyboardState[SDL_SCANCODE_W] ||
        keyboardState[SDL_SCANCODE_UP])
    {
        y--;
        moved = true;
    }

    if (keyboardState[SDL_SCANCODE_S] ||
        keyboardState[SDL_SCANCODE_DOWN])
    {
        y++;
        moved = true;
    }

    if (keyboardState[SDL_SCANCODE_A] ||
        keyboardState[SDL_SCANCODE_LEFT])
    {
        x--;
        moved = true;
    }

    if (keyboardState[SDL_SCANCODE_D] ||
        keyboardState[SDL_SCANCODE_RIGHT])
    {
        x++;
        moved = true;
    }

    if (moved)
    {
        SDL_Log("POSITION: X: %d Y: %d", x, y);
    }
}

void render(SDL_Renderer* rendered, int x, int y, int mouseX, int mouseY, int colorState)
{
    SDL_SetRenderDrawColor(rendered, 20, 20, 20, 255);
    SDL_RenderClear(rendered);

    if (colorState == 0)
    {
        SDL_SetRenderDrawColor(rendered, 255, 255, 255, 255);
    }
    else if (colorState == 1)
    {
        SDL_SetRenderDrawColor(rendered, 255, 0, 0, 255);
    }
    else if (colorState == 2)
    {
        SDL_SetRenderDrawColor(rendered, 0, 255, 0, 255);
    }
    else if (colorState == 3)
    {
        SDL_SetRenderDrawColor(rendered, 0, 0, 255, 255);
    }

    SDL_FRect player;
    player.x = x;
    player.y = y;
    player.w = 50;
    player.h = 50;

    SDL_RenderFillRect(rendered, &player);

    SDL_SetRenderDrawColor(rendered, 255, 255, 0, 255);

    SDL_FRect mouseShape;
    mouseShape.x = mouseX - 10;
    mouseShape.y = mouseY - 10;
    mouseShape.w = 20;
    mouseShape.h = 20;

    SDL_RenderFillRect(rendered, &mouseShape);

    SDL_RenderPresent(rendered);
}