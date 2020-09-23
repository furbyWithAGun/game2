#include "RpgGameEngine.h"

RpgGameEngine::RpgGameEngine(std::string title, int width, int height) : BaseGameEngine( title, width, height) {
    
}

void RpgGameEngine::handleInput() {
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

void RpgGameEngine::gameLogic() {

}

void RpgGameEngine::gameRendering() {

}
