#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <string>

class BaseGameEngine
{
    public:
        BaseGameEngine(std::string title, int width, int height);
        ~BaseGameEngine();
        bool init();
        void close();
        void free();
        SDL_Window* getMainWindow();
        SDL_Renderer* getMainRenderer();
        virtual void handleInput();
        virtual void gameLogic();
        virtual void gameRendering();
        void startMainGameLoop();

    protected:
        bool gameRunning;

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

