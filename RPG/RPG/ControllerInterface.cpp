#include "ControllerInterface.h"
#include "BaseGameEngine.h"

//constructors
ControllerInterface::ControllerInterface() {

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