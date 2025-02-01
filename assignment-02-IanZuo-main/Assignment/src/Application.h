#ifndef APPLICATION_H
#define APPLICATION_H

#include <SDL2/SDL.h>
#include <iostream>

class Application {
public:
    Application();
    ~Application();
    void run();

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool isRunning;
    SDL_Color backgroundColor = {0, 0, 255, 255}; // Default blue

    void processInput();
    void update();
    void render();
};

#endif // APPLICATION_H
