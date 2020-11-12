#pragma once
#include "InputMessage.h"
#include <vector>

enum BASIC_INPUT_MESSAGES {
    END_SCENE,
    K_ESC,
    SELECT_ON,
    SELECT_OFF,
    KEY_INPUT,
    POINTER_STATE,
    SCROLL_UP,
    SCROLL_DOWN,
    NUM_BASIC_MESSAGES
};

class ControllerInterface
{
public:
    //attributes
    std::vector<InputMessage*> messageQueue;
    std::vector<InputMessage*> textInputQueue;
    int latestXpos, latestYpos;
    bool selectOn;

    //constructors
    ControllerInterface();

    //methods
    virtual void populateMessageQueue() {};
    void populateTextInputQueue();
    bool getNextMessage(InputMessage* message);
    void addMessage(InputMessage* message);
    void addMessage(InputMessage message);
    bool getNextTextInput(InputMessage* message);
    void addTextInput(InputMessage* message);
    void addTextInput(InputMessage message);
};

