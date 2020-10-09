#pragma once
#include "RpgWorldBuilderSceneButtons.cpp"


class ZoneBuilderMenu : public GameMenu {
public:
    //constructors
    ZoneBuilderMenu() : GameMenu() {
        engine = NULL;
        scene = NULL;
    }

    ZoneBuilderMenu(RpgWorldBuilderScene* gameScene, int newId, int newWidth, int newHeight, int newXPos, int newYPos) : GameMenu(gameScene->engine, newId, newWidth, newHeight, newXPos, newYPos) {
        scene = gameScene;
        engine = gameScene->engine;
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
                scene->placingTile = false;
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
        GameMenu::handleEvent(e);
    }

private:
    //attributes
    BaseGameEngine* engine;
    RpgWorldBuilderScene* scene;

    //methods
    void buildButtons() {
        int x = 0;
        for (auto i = scene->mapTiles.begin(); i != scene->mapTiles.end(); i++)
        {
            MapBuilderTileButton* button;
            button = new MapBuilderTileButton(&i->second, scene);
            button->xpos = button->width / 2 + button->width * (x % 2) + button->width * (x % 2);
            button->ypos = (button->height * floor(x / 2) + button->height * floor(x / 2)) + engine->screenHeight * 0.05;
            buttons.push_back(button);
            x++;
        }

        SaveMapBuilderButton* button = new SaveMapBuilderButton(&scene->engine->textures[BUTTON_BACKGROUND],scene);
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