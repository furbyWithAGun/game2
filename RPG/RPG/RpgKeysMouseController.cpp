#include "RpgKeysMouseController.h"
#include "BaseGameEngine.h"
#include "RpgGameConstants.h"

//constructors
RpgKeysMouseController::RpgKeysMouseController() : ControllerInterface() {

}

//methods
void RpgKeysMouseController::populateMessageQueue() {
    SDL_Event e;
    int x, y;
    SDL_GetMouseState(&x, &y);

    addMessage(InputMessage(POINTER_STATE, x, y));
    while (SDL_PollEvent(&e) != 0) {
        SDL_GetMouseState(&x, &y);
        latestXpos = x;
        latestYpos = y;
        switch (e.type)
        {
        case SDL_QUIT:
            addMessage(InputMessage(END_SCENE, x, y));
            break;
        case SDL_MOUSEBUTTONDOWN:
            switch (e.button.button)
            {
            case SDL_BUTTON_LEFT:
                addMessage(InputMessage(SELECT_ON, x, y));
                break;
            case SDL_BUTTON_RIGHT:
                addMessage(InputMessage(BUTTON_5_ON, x, y));
                break;
            default:
                break;
            }
            break;
        case SDL_MOUSEBUTTONUP:
            switch (e.button.button)
            {
            case SDL_BUTTON_LEFT:
                addMessage(InputMessage(SELECT_OFF, x, y));
                break;
            case SDL_BUTTON_RIGHT:
                addMessage(InputMessage(BUTTON_5_OFF, x, y));
                break;
            default:
                break;
            }
            break;
        case SDL_MOUSEMOTION:
            addMessage(InputMessage(POINTER_MOVEMENT, x, y));
            break;
        case SDL_KEYDOWN:
            switch (e.key.keysym.sym) {
            case SDLK_w:
                addMessage(InputMessage(BUTTON_1_ON));
                break;
            case SDLK_s:
                addMessage(InputMessage(BUTTON_2_ON));
                break;
            case SDLK_a:
                addMessage(InputMessage(BUTTON_3_ON));
                break;
            case SDLK_d:
                addMessage(InputMessage(BUTTON_4_ON));
                break;
            }
            break;
        case SDL_KEYUP:
            switch (e.key.keysym.sym) {
            case SDLK_w:
                addMessage(InputMessage(BUTTON_1_OFF));
                break;
            case SDLK_s:
                addMessage(InputMessage(BUTTON_2_OFF));
                break;
            case SDLK_a:
                addMessage(InputMessage(BUTTON_3_OFF));
                break;
            case SDLK_d:
                addMessage(InputMessage(BUTTON_4_OFF));
                break;
            }
            break;
        default:
            break;
        }
    }
}
