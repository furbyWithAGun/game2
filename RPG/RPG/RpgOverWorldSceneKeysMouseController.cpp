#include "RpgOverWorldSceneKeysMouseController.h"
#include "BaseGameEngine.h"
#include "RpgGameConstants.h"
#include "RpgOverWorldScene.h"

//constructors
RpgOverWorldSceneKeysMouseController::RpgOverWorldSceneKeysMouseController() :  ControllerInterface() {

}

//methods
void RpgOverWorldSceneKeysMouseController::populateMessageQueue() {
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
        switch (e.type)
        {
        case SDL_QUIT:
            addMessage(InputMessage(END_SCENE));
            break;
        case SDL_MOUSEBUTTONDOWN:
            switch (e.button.button)
            {
            case SDL_BUTTON_LEFT:
                addMessage(InputMessage(MAIN_ATTACK));
                break;
            default:
                break;
            }

            break;
        case SDL_MOUSEBUTTONUP:
            switch (e.button.button)
            {
            case SDL_BUTTON_LEFT:
                break;
            default:
                break;
            }
            break;
        case SDL_MOUSEMOTION:
            break;
        case SDL_KEYDOWN:
            switch (e.key.keysym.sym) {
            case SDLK_w:
                addMessage(InputMessage(START_MOVE_UP));
                break;
            case SDLK_s:
                addMessage(InputMessage(START_MOVE_DOWN));
                break;
            case SDLK_a:
                addMessage(InputMessage(START_MOVE_LEFT));
                break;
            case SDLK_d:
                addMessage(InputMessage(START_MOVE_RIGHT));
                break;
            }
            break;
        case SDL_KEYUP:
            switch (e.key.keysym.sym) {
            case SDLK_w:
                addMessage(InputMessage(STOP_MOVE_UP));
                break;
            case SDLK_s:
                addMessage(InputMessage(STOP_MOVE_DOWN));
                break;
            case SDLK_a:
                addMessage(InputMessage(STOP_MOVE_LEFT));
                break;
            case SDLK_d:
                addMessage(InputMessage(STOP_MOVE_RIGHT));
                break;
            }
            break;
        default:
            break;
        }
    }
}
