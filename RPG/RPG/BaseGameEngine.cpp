#include "BaseGameEngine.h"
#include <stdio.h>
#include <iostream>
#include <fstream>

//constants
const int KEY_R_VALUE = 255;
const int KEY_G_VALUE = 0;
const int KEY_B_VALUE = 255;

BaseGameEngine::BaseGameEngine(std::string title, int width, int height) {
    textures.clear();
    screenHeight = 0;
    screenWidth = 0;
    windowTitle = title;
    windowWidth = width;
    windowHeight = height;
    mainWindow = NULL;
    mainRenderer = NULL;
    mainFont = NULL;
}

BaseGameEngine::~BaseGameEngine() {
    free();
}

void BaseGameEngine::free() {
    
    if (mainWindow!= NULL)
    {
        SDL_DestroyWindow(mainWindow);
    }

    if (mainRenderer != NULL)
    {
        SDL_DestroyRenderer(mainRenderer);
    }
    if (mainFont != NULL)
    {
        TTF_CloseFont(mainFont);
    }

    textures.clear();
    windowHeight = 0;
    windowWidth = 0;
    windowTitle = "";
    screenWidth = 0;
    screenHeight = 0;
    mainWindow= NULL;
    mainRenderer = NULL;
    mainFont = NULL;
    mainFontColor = {0, 0, 0};
}

SDL_Window* BaseGameEngine::createWindow(const char* title, int height, int width) {
    SDL_Window* newWindow = NULL;

    //Set texture filtering to linear
    if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
    {
        printf("Warning: Linear texture filtering not enabled!");
    }

    newWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    //newWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN_DESKTOP);
    if (newWindow == NULL)
    {
        printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
    }

    
    return newWindow;
}

SDL_Renderer* BaseGameEngine::createRenderer(SDL_Window* window) {
    SDL_Renderer* newRenderer = NULL;

    //Create vsynced renderer for window
    newRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (newRenderer == NULL)
    {
        printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
        return NULL;
    }

    //Initialize renderer color
    SDL_SetRenderDrawColor(newRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_GetRendererOutputSize(newRenderer, &screenWidth, &screenHeight);

    return newRenderer;
}

bool BaseGameEngine::init() {

    //init sdl
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        return false;
    }

    //create window
    mainWindow = createWindow(windowTitle.c_str(), windowHeight, windowWidth);
    if (mainWindow == NULL)
    {
        return false;
    }

    //create main window renderer
    mainRenderer = createRenderer(mainWindow);
    if (mainRenderer == NULL)
    {
        return false;
    }

    //Initialize PNG loading
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags))
    {
        printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
        return false;
    }

    //Initialize SDL_ttf
    if (TTF_Init() == -1)
    {
        printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
        return false;
    }

    //load assets (this method will be overriden in child class)
    loadAssets();

    return true;
}

void BaseGameEngine::close() {
    free();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

SDL_Window* BaseGameEngine::getMainWindow() {
    return mainWindow;
}

SDL_Renderer* BaseGameEngine::getMainRenderer() {
    return mainRenderer;
}

SDL_Texture* BaseGameEngine::loadTextureImageFromFile(std::string path) {
    SDL_Texture* newTexture = NULL;
    
    //load the image from the file
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL)
    {
        printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
        return NULL;
    }

    //set transparent color
    SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, KEY_R_VALUE, KEY_G_VALUE, KEY_B_VALUE));
    
    //convert to texture
    newTexture = SDL_CreateTextureFromSurface(mainRenderer, loadedSurface);
    if (newTexture == NULL)
    {
        printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
        return NULL;
    }

    //Get rid of old loaded surface
    SDL_FreeSurface(loadedSurface);
    
    return newTexture;
}

bool BaseGameEngine::loadTextureImageFromFile(Texture* texture) {

    texture->texture = NULL;

    //load the image from the file
    SDL_Surface* loadedSurface = IMG_Load(texture->filePath.c_str());
    if (loadedSurface == NULL)
    {
        printf("Unable to load image %s! SDL_image Error: %s\n", texture->filePath.c_str(), IMG_GetError());
        return false;
    }

    //set transparent color
    SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, KEY_R_VALUE, KEY_G_VALUE, KEY_B_VALUE));

    //convert to texture
    texture->texture = SDL_CreateTextureFromSurface(mainRenderer, loadedSurface);
    if (texture->texture == NULL)
    {
        printf("Unable to create texture from %s! SDL Error: %s\n", texture->filePath.c_str(), SDL_GetError());
        return false;
    }

    texture->height = loadedSurface->h;
    texture->width = loadedSurface->w;


    //Get rid of old loaded surface
    SDL_FreeSurface(loadedSurface);

    return true;
}

SDL_Texture* BaseGameEngine::loadTextureFromText(std::string text) {
    SDL_Texture* textTexture;
    SDL_Surface* textSurface = TTF_RenderText_Solid(mainFont, text.c_str(), mainFontColor);
    if (textSurface == NULL)
    {
        printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
        return NULL;
    }

    textTexture = SDL_CreateTextureFromSurface(mainRenderer, textSurface);
    if (textTexture == NULL)
    {
        printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
        return NULL;
    }

    SDL_FreeSurface(textSurface);
    return textTexture;
}

int BaseGameEngine::addTexture(Texture texture) {
    int index;
    loadTextureImageFromFile(&texture);
    index = textures.size();
    textures[index] = texture;
    return index;
}

bool BaseGameEngine::createMultipleTextures(std::unordered_map<int, std::string> texturesToCreate) {
    for (auto i = texturesToCreate.begin(); i != texturesToCreate.end(); ++i)
    {
        textures[i->first] = Texture(i->second);
        loadTextureImageFromFile(&textures[i->first]);
    }
    return true;
}

void BaseGameEngine::renderTexture(Texture texture, int x, int y) {
    SDL_Rect renderQuad = { x, y, texture.width, texture.height };
    
    SDL_RenderCopy(mainRenderer, texture.texture, NULL, &renderQuad);
}

void BaseGameEngine::renderTexture(Texture texture, int x, int y, int width, int height) {
    SDL_Rect renderQuad = { x, y, width, height };

    SDL_RenderCopy(mainRenderer, texture.texture, NULL, &renderQuad);
}

//this method will be ovverridden in child class
void BaseGameEngine::loadAssets() {

}

//this method will be ovverridden in child class
void BaseGameEngine::handleInput() {
    
}

//this method will be ovverridden in child class
void BaseGameEngine::gameLogic() {

}

//this method will be ovverridden in child class
void BaseGameEngine::gameRendering() {

}

void BaseGameEngine::startMainGameLoop() {

    gameRunning = true;

    while (gameRunning)
    {
        handleInput();
        gameLogic();
        gameRendering();
    }
}
