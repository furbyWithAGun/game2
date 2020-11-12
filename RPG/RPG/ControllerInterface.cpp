#include "ControllerInterface.h"
#include "BaseGameEngine.h"

//constructors
ControllerInterface::ControllerInterface() {
    latestXpos = latestYpos = 0;
}

//public methods
bool ControllerInterface::getNextMessage(InputMessage* message) {
    if (messageQueue.size() > 0)
    {
        *message = *messageQueue[0];
        delete messageQueue[0];
        messageQueue.erase(messageQueue.begin());
        return true;
    }
    else {
        message = NULL;
        return false;
    }
}

void ControllerInterface::addMessage(InputMessage* newMessage) {
    InputMessage* message = new InputMessage();
    *message = *newMessage;
    messageQueue.push_back(message);
}

void ControllerInterface::addMessage(InputMessage newMessage) {
    InputMessage* message = new InputMessage();
    *message = newMessage;
    messageQueue.push_back(message);
}

bool ControllerInterface::getNextTextInput(InputMessage* message) {
    if (textInputQueue.size() > 0)
    {
        *message = *textInputQueue[0];
        delete textInputQueue[0];
        textInputQueue.erase(textInputQueue.begin());
        return true;
    }
    else {
        message = NULL;
        return false;
    }
}

void ControllerInterface::addTextInput(InputMessage* newMessage) {
    InputMessage* message = new InputMessage();
    *message = *newMessage;
    textInputQueue.push_back(message);
}

void ControllerInterface::addTextInput(InputMessage newMessage) {
    InputMessage* message = new InputMessage();
    *message = newMessage;
    textInputQueue.push_back(message);
}

void ControllerInterface::populateTextInputQueue()
{
    SDL_Event e;
    int xpos, ypos;
    while (SDL_PollEvent(&e) != 0) {
        SDL_GetMouseState(&xpos, &ypos);
        latestXpos = xpos;
        latestYpos = ypos;
        switch (e.type)
        {
        case SDL_QUIT:
            addTextInput(InputMessage(END_SCENE, xpos, ypos));
            break;
        case SDL_MOUSEBUTTONDOWN:
            addTextInput(InputMessage(SELECT_ON, xpos, ypos));
            break;
        case SDL_KEYDOWN:
            addTextInput(InputMessage(KEY_INPUT, xpos, ypos, e.text.text));
            break;
        default:
            break;
        }
    }
}