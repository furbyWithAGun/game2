#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <string>
#include "Texture.h"
#include <unordered_map>
#include "SaveFile.h"
#include "GameScene.h"
#include <stdlib.h>
#include <time.h>
#include <SDL_thread.h>
#include "Animation.h"
#include <cmath>

class BaseGameEngine
{
    public:
        //attributes
        std::unordered_map<int, Texture> textures;
        std::unordered_map<std::string, int> textTextures;
        int screenHeight;
        int screenWidth;
        TTF_Font* mainFont;
        bool gameRunning;
        bool sceneRunning;
        SDL_SpinLock sceneRunningLock;
        SDL_SpinLock sceneLock;
        double tickDelay;

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
        int createImageTexture(int textureKey, std::string imagePath);
        int createImageTexture(std::string imagePath);
        int createTextTexture(int textureKey, std::string text, SDL_Color colour = { 0, 0 ,0 });
        int createTextTexture(std::string text, SDL_Color colour = { 0, 0 ,0 });
        bool createMultipleTextures(std::unordered_map<int, std::string> texturesToCreate);
        SDL_Texture* loadTextureImageFromFile(std::string path);
        bool loadTextureImage(Texture* texture);
        SDL_Texture* loadTextureFromText(std::string text, SDL_Color colour = { 0, 0 ,0 });
        void renderTexture(Texture* texture, int x, int y);
        void renderTexture(Texture* texture, int x, int y, int width, int height);
        void renderTexture(int textureKey, int x, int y);
        void renderTexture(int textureKey, int x, int y, int width, int height);
        void renderText(std::string textToRender, int x, int y, SDL_Color colour = { 0, 0 ,0 });
        void renderText(std::string textToRender, int x, int y, int width, int height, SDL_Color colour = { 0, 0 ,0 });
        void renderAnimation(Animation* animation, int x, int y);
        void renderAnimation(Animation* animation, int x, int y, int width, int height);
        void renderRectangle(int x, int y, int width, int height, int r, int g, int b);
        void renderRectangle(int x, int y, int width, int height, int r, int g, int b, int a);
        void addScene(int sceneId, GameScene* sceneToAdd);
        void setNextScene(int sceneId);
        double randomDouble();
        int randomInt(int maxValue);
        int randomInt(int minValue, int maxValue);
        int getTextureWidth(int textureKey);
        int getTextureHeight(int textureKey);
        int getTextTextureWidth(std::string text);
        int getTextTextureHeight(std::string text);
        double getProbFromSigmoid(double skill, double difficulty);
        void setSigmoidFunction(double omega, double alpha);
        double sigmoid(double x);

    protected:
        
    private:
        //attributes
        int windowWidth;
        int windowHeight;
        std::string windowTitle;
        SDL_Renderer* mainRenderer;
        SDL_Window* mainWindow;
        GameScene* currentScene;
        GameScene* nextScene;
        std::unordered_map<int, GameScene*> scenes;
        int auto_texturekey;
        double sigmoidOmega, sigmoidAlpha;
        

        //methods
        SDL_Window* createWindow(const char* title, int height, int width);
        SDL_Renderer* createRenderer(SDL_Window* window);
        bool initNextScene();
        bool loadSceneTextures(GameScene * newScene);
        bool clearTextures();
        
};

int logicThread(void* scene);
