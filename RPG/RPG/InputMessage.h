#pragma once

class InputMessage {
public:
    //attributes
    int id, x, y, misc;

    //constructors
    InputMessage();
    InputMessage(int messageId);
    InputMessage(int messageId, int xVal, int yVal);

    //methods

private:
    void init();
    void init(int messageId);
};
