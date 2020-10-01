#pragma once
#include "RpgGameButtons.cpp"

class ZoneBuilderMenu : public GameMenu {    
    public:        
        //constructors
        ZoneBuilderMenu() : GameMenu() {
            engine = NULL;
        }

        ZoneBuilderMenu(RpgGameEngine* gameEngine, int newId, int newWidth, int newHeight, int newXPos, int newYPos) : GameMenu ((BaseGameEngine*) gameEngine, newId, newWidth, newHeight, newXPos, newYPos){
            engine = gameEngine;
            buildButtons();
        }

        //methods
        void handleEvent(SDL_Event* e) {
            switch (e->type)
            {
            case SDL_MOUSEBUTTONDOWN:
                switch (e->button.button)
                {
                case SDL_BUTTON_LEFT:
                    break;
                case SDL_BUTTON_RIGHT:
                    engine->placingTile = false;
                    break;
                default:
                    break;
                }
            default:
                break;
            }
            GameMenu::handleEvent(e);
        }

    private:
        //attributes
        RpgGameEngine* engine;

        //methods
        void buildButtons() {
            for (int i = 0; i < engine->mapTiles.size(); i++)
            {
                MapBuilderTileButton* button;
                button = new MapBuilderTileButton(&engine->mapTiles[i], engine);
                button->xpos = engine->tileWidth / 2 + engine->tileWidth * (i % 2) + engine->tileWidth * (i % 2);
                button->ypos = engine->tileHeight * floor(i / 2) + engine->tileHeight * floor(i / 2);
                buttons.push_back(button);
            }
        }
};