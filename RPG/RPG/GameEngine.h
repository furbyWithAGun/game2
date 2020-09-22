#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <string>

class GameEngine
{
    public:
        GameEngine(std::string title, int width, int height);
        ~GameEngine();
        bool init();
        void close();
        void free();
        SDL_Window* getMainWindow();
        SDL_Renderer* getMainRenderer();
        

    private:
        int screenWidth;
        int screenHeight;
        SDL_Window* mainWindow;
        SDL_Renderer* mainRenderer;
        TTF_Font* mainFont;
        std::string windowTitle;
        SDL_Window* createWindow(const char* title, int height, int width);
        SDL_Renderer* createRenderer(SDL_Window* window);
};

