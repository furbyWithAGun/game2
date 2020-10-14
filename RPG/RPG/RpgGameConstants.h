#pragma once

//constants
const std::string GAME_TITLE = "RPG";
const int SCREEN_WIDTH = 1900;
const int SCREEN_HEIGHT = 1000;
//player stats
const int PLAYER_SPEED = 4;

//enums
enum OBJECTS {
    ZONE_MAP,
    ZONE_PORTAL
};

enum MENUS {
    BUILD_MENU
};

enum ANIMATIONS {
    IDLE,
    MOVE_UP,
    MOVE_DOWN,
    MOVE_RIGHT,
    MOVE_LEFT
};

enum TEXTURE_NAMES
{
    GRASS,
    TREE,
    WATER,
    MOUNTAIN,
    BUTTON_BACKGROUND,
    PLAYER_IDLE_SHEET,
    PLAYER_MOVE_DOWN_SHEET,
    RAT,
    NUM_TEXTURES
};

enum DIRECTIONS {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    UP_RIGHT,
    UP_LEFT,
    DOWN_RIGHT,
    DOWN_LEFT,
    NUM_DIRECTIONS
};

enum SCENES {
    WORLD_BUILDER,
    OVERWORLD
};