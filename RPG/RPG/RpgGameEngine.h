#pragma once
#include "BaseGameEngine.h"
#include "ZoneMap.h"
#include "MapTile.h"

enum GAME_STATES {
    MAIN_MENU,
    OVERWORLD,
    LEVEL_DESIGN,
    BUILDING,
    COMBAT
};

enum TILE_TYPES
{
    GRASS,
    TREE,
    WATER
};

class RpgGameEngine: public BaseGameEngine
{
    public:
        //attributes
        std::unordered_map<int, MapTile> mapTiles;
        int gameState;

        //contructor
        RpgGameEngine(std::string title, int width, int height);

        //methods
        void setUpGame();
        void handleInput() override;
        void gameLogic() override;
        void gameRendering() override;
        bool addTile(int key, MapTile tile);
        void getTileIndexFromScreenCoords(int x, int y, int tileIndices[2]);

    private:
        //attributes
        ZoneMap currentZone;
        int tileHeight;
        int tileWidth;

        //methods
        void drawMenu();
};

