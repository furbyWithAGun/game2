#pragma once
#include <SDL.h>

class GameEngine
{
    public:
        GameEngine(int width, int height);
        ~GameEngine();
        bool init();
        void close();

    private:
        int screenWidth;
        int screenHeight;
        SDL_Window* window;
        SDL_Renderer* renderer;
};

