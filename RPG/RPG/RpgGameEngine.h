#pragma once
#include "BaseGameEngine.h"
#include "ZoneMap.h"
#include "MapTile.h"

class RpgGameEngine: public BaseGameEngine
{
    public:
        //attributes
        std::unordered_map<int, MapTile> mapTiles;

        //contructor
        RpgGameEngine(std::string title, int width, int height);

        //methods
        void setUpGame();
        void handleInput() override;
        void gameLogic() override;
        void gameRendering() override;
    private:
        ZoneMap currentZone;
        int tileHeight;
        int tileWidth;
};

