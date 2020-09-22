// Includes
#include "gameEngine.h"

// Global Constants
const std::string GAME_TITLE = "RPG";
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

void GameEngine::handleInput() {
    SDL_Event e;

    //Handle events on queue
    while (SDL_PollEvent(&e) != 0)
    {
        //User requests quit
        if (e.type == SDL_QUIT)
        {
            gameRunning = false;
        }
    }
}

void GameEngine::gameLogic() {

}

void GameEngine::gameRendering() {

}

int main(int argc, char* args[])
{
    //local vars
    GameEngine engine = GameEngine(GAME_TITLE, SCREEN_WIDTH, SCREEN_HEIGHT);

    //init game engine
    engine.init();

    //main game loop
    engine.startMainGameLoop();

    //terminate the engine
    engine.close();

    return 0;
}