#pragma once
#include "InputMessage.h"
#include <vector>

class ControllerInterface
{
public:
    //attributes
    std::vector<InputMessage*> messageQueue;

    //constructors
    ControllerInterface();

    //methods
    virtual void populateMessageQueue() {};
    bool getNextMessage(InputMessage* message);
    void addMessage(InputMessage* message);
    void addMessage(InputMessage message);
};

