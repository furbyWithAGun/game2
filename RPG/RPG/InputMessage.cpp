#include "InputMessage.h"

//constructors
InputMessage::InputMessage() {
    init();
}

InputMessage::InputMessage(int messageId) {
    init(messageId);
}

InputMessage::InputMessage(int messageId, int xVal, int yVal) {
    init(messageId);
    x = xVal;
    y = yVal;
}

//private methods
void InputMessage::init() {
    id = x = y = misc = -1;
}

void InputMessage::init(int messageId) {
    init();
    id = messageId;
}
