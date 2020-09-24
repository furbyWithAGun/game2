#include "RpgGameEngine.h"
#include "ZoneMap.h"
#include "MapTile.h"

//global vars
const int TILE_HEIGHT = 100;
const int TILE_WIDTH = 100;

enum TILE_TYPES 
{
    GRASSLAND,
    FOREST,
    WATER
};

RpgGameEngine::RpgGameEngine(std::string title, int width, int height) : BaseGameEngine( title, width, height) {
    
}

void RpgGameEngine::setUpGame() {

    mapTiles[GRASSLAND] = MapTile(true, addTexture(Texture("images/grass.png")));
    ZoneMap zoneOne = ZoneMap({
        {GRASSLAND, GRASSLAND, GRASSLAND, GRASSLAND, GRASSLAND},
        {GRASSLAND, GRASSLAND, GRASSLAND, GRASSLAND, GRASSLAND},
        {GRASSLAND, GRASSLAND, GRASSLAND, GRASSLAND, GRASSLAND},
        {GRASSLAND, GRASSLAND, GRASSLAND, GRASSLAND, GRASSLAND},
        {GRASSLAND, GRASSLAND, GRASSLAND, GRASSLAND, GRASSLAND}
        });
    currentZone = zoneOne;
}

void RpgGameEngine::handleInput() {
    SDL_Event e;

    //Handle events on queue
    while (SDL_PollEvent(&e) != 0)
    {
        //User requests quit
        if (e.type == SDL_QUIT)
        {
            gameRunning = false;
        }
    }
}

void RpgGameEngine::gameLogic() {

}

void RpgGameEngine::gameRendering() {
    SDL_SetRenderDrawColor(getMainRenderer(), 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(getMainRenderer());

    //draw zone
    for (int i = 0; i < currentZone.tileMap.size(); i++) {
        for (int j = 0; j < currentZone.tileMap[i].size(); j++) {
            renderTexture(textures[mapTiles[currentZone.tileMap[i][j]].textureKey], TILE_WIDTH * j, TILE_HEIGHT * i);
        }
    }

    //Render texture to screen
    SDL_RenderCopy(getMainRenderer(), textures[0].texture, NULL, NULL);

    //Update screen
    SDL_RenderPresent(getMainRenderer());

}