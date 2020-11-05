#pragma once
#include "ControllerInterface.h"

class RpgOverWorldSceneKeysMouseController :  public ControllerInterface
{
public:
    //constructor
    RpgOverWorldSceneKeysMouseController();

    //methods
    void populateMessageQueue() override;

};

