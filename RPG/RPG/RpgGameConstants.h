#pragma once

//constants
const std::string GAME_TITLE = "RPG";
const int SCREEN_WIDTH = 1900;
const int SCREEN_HEIGHT = 1000;

//enums
enum OBJECTS {
    ZONE_MAP,
    ZONE_PORTAL
};

enum MENUS {
    BUILD_MENU
};

enum TEXTURE_NAMES
{
    GRASS,
    TREE,
    WATER,
    MOUNTAIN,
    BUTTON_BACKGROUND,
    PLAYER,
    NUM_TEXTURES
};

enum MOVEMENT {
    MOVE_UP,
    MOVE_DOWN,
    MOVE_LEFT,
    MOVE_RIGHT
};

enum SCENES {
    WORLD_BUILDER
};