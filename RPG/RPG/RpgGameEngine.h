#pragma once
#include "BaseGameEngine.h"
#include "ZoneMap.h"

class RpgGameEngine: public BaseGameEngine
{
    public:
        RpgGameEngine(std::string title, int width, int height);
        void handleInput() override;
        void gameLogic() override;
        void gameRendering() override;
    private:
        ZoneMap currentZone;
};

