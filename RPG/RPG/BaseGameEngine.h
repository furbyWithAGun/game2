#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <string>
#include "Texture.h"
#include <unordered_map>
#include "SaveFile.h"

class BaseGameEngine
{
    public:
        //static methods
        static std::string get2DIntVectorSaveString(std::vector<std::vector<int>> vector);
        static std::vector<std::vector<int>> get2dIntVectorFromSaveString(std::string saveString);

        //attributes
        std::unordered_map<int, Texture> textures;
        int screenHeight;
        int screenWidth;

        //constructor
        BaseGameEngine(std::string title, int width, int height);

        //methods
        ~BaseGameEngine();
        bool init();
        void close();
        void free();
        SDL_Window* getMainWindow();
        SDL_Renderer* getMainRenderer();
        virtual void loadAssets();
        virtual void handleInput();
        virtual void gameLogic();
        virtual void gameRendering();
        void startMainGameLoop();
        int addTexture(Texture texture);
        bool createMultipleTextures(std::unordered_map<int, std::string> texturesToCreate);
        SDL_Texture* loadTextureImageFromFile(std::string path);
        SDL_Texture* loadTextureFromText(std::string text);
        void renderTexture(Texture texture, int x, int y);
        void saveStringToFile(std::string string, std::string filePath);
        std::string loadStringFromFile(std::string filePath);
        
        bool loadTextureImageFromFile(Texture* texture);

    protected:
        bool gameRunning;

    private:
        //attributes
        int windowWidth;
        int windowHeight;
        TTF_Font* mainFont;
        std::string windowTitle;
        SDL_Renderer* mainRenderer;
        SDL_Window* mainWindow;

        //methods
        SDL_Window* createWindow(const char* title, int height, int width);
        SDL_Renderer* createRenderer(SDL_Window* window);
};

