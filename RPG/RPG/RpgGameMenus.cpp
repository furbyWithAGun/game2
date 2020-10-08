#pragma once
#include "RpgGameButtons.cpp"

//constants
const double LEFT_MENU_SIZE = 0.1;

class ZoneBuilderMenu : public GameMenu {
public:
    //constructors
    ZoneBuilderMenu() : GameMenu() {
        engine = NULL;
    }

    ZoneBuilderMenu(RpgGameEngine* gameEngine, int newId, int newWidth, int newHeight, int newXPos, int newYPos) : GameMenu((BaseGameEngine*)gameEngine, newId, newWidth, newHeight, newXPos, newYPos) {
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
        int x = 0;
        for (auto i = engine->mapTiles.begin(); i != engine->mapTiles.end(); i++)
        {
            MapBuilderTileButton* button;
            button = new MapBuilderTileButton(&i->second, engine);
            button->xpos = button->width / 2 + button->width * (x % 2) + button->width * (x % 2);
            button->ypos = (button->height * floor(x / 2) + button->height * floor(x / 2)) + engine->screenHeight * 0.05;
            buttons.push_back(button);
            x++;
        }

        SaveMapBuilderButton* button = new SaveMapBuilderButton(&engine->textures[BUTTON_BACKGROUND], engine);
        button->xpos = width * 0.2;
        button->ypos = height * 0.7;
        button->setText("Save Map");
        button->textTexture.height = button->textTexture.height * 0.75;
        button->textTexture.width = button->textTexture.width * 0.75;
        button->textXoffset = button->textTexture.width * 0.09;
        button->textYoffset = button->textTexture.height * 0.11;
        buttons.push_back(button);
    }
};