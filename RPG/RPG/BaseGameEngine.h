#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <string>
#include "Texture.h"
#include <unordered_map>

class BaseGameEngine
{
    public:
        std::unordered_map<int, Texture> textures;
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
        int addTexture(Texture texture);
        SDL_Texture* loadTextureImageFromFile(std::string path);
        SDL_Texture* loadTextureFromText(std::string text);

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

