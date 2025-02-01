#include "Application.h"

Application::Application() : window(nullptr), renderer(nullptr), isRunning(true) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
        isRunning = false;
        return;
    }

    // Create SDL window
    window = SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    if (!window) {
        std::cerr << "Failed to create SDL window: " << SDL_GetError() << std::endl;
        isRunning = false;
        return;
    }

    // Create SDL renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Failed to create SDL renderer: " << SDL_GetError() << std::endl;
        isRunning = false;
    }
}

Application::~Application() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Application::run() {
    while (isRunning) {
        processInput();
        update();
        render();
    }
}

void Application::processInput() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            isRunning = false;
        }

        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_1:
                    backgroundColor = {255, 0, 0, 255}; // Red
                    break;
                case SDLK_2:
                    backgroundColor = {0, 255, 0, 255}; // Green
                    break;
                case SDLK_3:
                    backgroundColor = {0, 0, 255, 255}; // Blue
                    break;
                case SDLK_ESCAPE:
                    isRunning = false;
                    break;
            }
        }
    }
}

void Application::update() {
    // Placeholder for future game logic updates
}

void Application::render() {
    SDL_SetRenderDrawColor(renderer, backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}
