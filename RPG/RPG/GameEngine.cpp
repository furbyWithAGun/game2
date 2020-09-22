#include "GameEngine.h"
#include <stdio.h>
#include <iostream>

GameEngine::GameEngine(std::string title, int width, int height) {
    windowTitle = title;
    screenWidth = width;
    screenHeight = height;
    mainWindow = NULL;
    mainRenderer = NULL;
    mainFont = NULL;
}

GameEngine::~GameEngine() {
    free();
}

void GameEngine::free() {

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

    windowTitle = "";
    screenWidth = 0;
    screenHeight = 0;
    mainWindow= NULL;
    mainRenderer = NULL;
    mainFont = NULL;

}

SDL_Window* GameEngine::createWindow(const char* title, int height, int width) {
    SDL_Window* newWindow = NULL;
    newWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, height, width, SDL_WINDOW_SHOWN);
    if (newWindow == NULL)
    {
        printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
    }

    return newWindow;
}

SDL_Renderer* GameEngine::createRenderer(SDL_Window* window) {
    SDL_Renderer* newRenderer = NULL;

    //Set texture filtering to linear
    if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
    {
        printf("Warning: Linear texture filtering not enabled!");
    }

    //Create vsynced renderer for window
    newRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (newRenderer == NULL)
    {
        printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
        return NULL;
    }

    //Initialize renderer color
    SDL_SetRenderDrawColor(newRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

    return newRenderer;
}

bool GameEngine::init() {

    //init sdl
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        return false;
    }

    //create window
    mainWindow = createWindow(windowTitle.c_str(), screenHeight, screenWidth);
    if (mainWindow == NULL)
    {
        return false;
    }

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

    return true;
}

void GameEngine::close() {
    free();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

SDL_Window* GameEngine::getMainWindow() {
    return mainWindow;
}

SDL_Renderer* GameEngine::getMainRenderer() {
    return mainRenderer;
}

void GameEngine::startMainGameLoop() {

    gameRunning = true;

    while (gameRunning)
    {
        handleInput();
        gameLogic();
        gameRendering();
    }
}