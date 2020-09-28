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

enum TEXTURE_NAMES
{
    GRASS,
    TREE,
    WATER,
    NUM_TEXTURES
};

enum CLASS_IDS{
    ZONE_PORTAL,
    ZONE_MAP
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
        void loadAssets() override;
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
        void createTiles();
};

