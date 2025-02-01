#include "Application.h"

// Constructor: Initializes SDL, creates a window, and sets up the renderer
Application::Application() : window(nullptr), renderer(nullptr), isRunning(true) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {  // SDL_INIT_VIDEO initializes the video subsystem
        std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
        isRunning = false;
        return;
    }

    // Create SDL window (800x600 resolution, centered)
    window = SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    if (!window) {  // Check if window creation failed
        std::cerr << "Failed to create SDL window: " << SDL_GetError() << std::endl;
        isRunning = false;
        return;
    }

    // Create SDL renderer (hardware accelerated)
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {  // Check if renderer creation failed
        std::cerr << "Failed to create SDL renderer: " << SDL_GetError() << std::endl;
        isRunning = false;
    }
}

// Destructor: Cleans up SDL resources
Application::~Application() {
    SDL_DestroyRenderer(renderer);  // Destroy the renderer
    SDL_DestroyWindow(window);      // Destroy the window
    SDL_Quit();                     // Quit SDL
}

// Main application loop: runs continuously until isRunning is false
void Application::run() {
    while (isRunning) {
        processInput();  // Handle user input (keyboard, window events)
        update();        // Update game logic (currently empty)
        render();        // Render the updated screen
    }
}

// Handles user input (keyboard and window events)
void Application::processInput() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {  // Check for events in the queue
        if (event.type == SDL_QUIT) {  // If the user closes the window
            isRunning = false;
        }

        // Handle keyboard input
        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_1:  // Press "1" to change background to Red
                    backgroundColor = {255, 0, 0, 255};
                    break;
                case SDLK_2:  // Press "2" to change background to Green
                    backgroundColor = {0, 255, 0, 255};
                    break;
                case SDLK_3:  // Press "3" to change background to Blue
                    backgroundColor = {0, 0, 255, 255};
                    break;
                case SDLK_ESCAPE:  // Press "ESC" to exit the program
                    isRunning = false;
                    break;
            }
        }
    }
}

// Placeholder for future game logic updates (currently empty)
void Application::update() {
}

// Renders the screen with the current background color
void Application::render() {
    // Set the renderer draw color based on backgroundColor
    SDL_SetRenderDrawColor(renderer, backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a);
    
    SDL_RenderClear(renderer);  // Clear the screen with the new color
    SDL_RenderPresent(renderer); // Display the updated color
}
