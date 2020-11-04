#pragma once
#include <string>

//constants
const std::string GAME_TITLE = "RPG";
const int SCREEN_WIDTH = 1900;
const int SCREEN_HEIGHT = 1000;

//enums
enum ATTCK_TYPES {
    MELEE,
    RANGED,
    MAGIC
};

enum OBJECTS {
    ZONE_MAP,
    ZONE_PORTAL
};

enum MENUS {
    BUILD_MENU
};

enum UNIT_STATES {
    UNIT_IDLE,
    UNIT_MOVING,
    UNIT_ATTACKING
};

enum ANIMATIONS {
    IDLE_UP_LEFT,
    IDLE_UP,
    IDLE_UP_RIGHT,
    IDLE_RIGHT,
    IDLE_DOWN_RIGHT,
    IDLE_DOWN,
    IDLE_DOWN_LEFT,
    IDLE_LEFT,
    MOVE_UP,
    MOVE_DOWN,
    MOVE_RIGHT,
    MOVE_LEFT,
    ATTACK_UP_LEFT,
    ATTACK_UP,
    ATTACK_UP_RIGHT,
    ATTACK_RIGHT,
    ATTACK_DOWN_RIGHT,
    ATTACK_DOWN,
    ATTACK_DOWN_LEFT,
    ATTACK_LEFT
};

enum TEXTURE_NAMES
{
    //-------------tiles-------------
    GRASS,
    TREE,
    WATER,
    MOUNTAIN,
    //------------button----------------------
    BUTTON_BACKGROUND,
    //------------player---------------------
    PLAYER_IDLE_UP_LEFT_SHEET,
    PLAYER_IDLE_UP_SHEET,
    PLAYER_IDLE_UP_RIGHT_SHEET,
    PLAYER_IDLE_RIGHT_SHEET,
    PLAYER_IDLE_DOWN_RIGHT_SHEET,
    PLAYER_IDLE_DOWN_SHEET,
    PLAYER_IDLE_DOWN_LEFT_SHEET,
    PLAYER_IDLE_LEFT_SHEET,
    PLAYER_MOVE_UP_SHEET,
    PLAYER_MOVE_DOWN_SHEET,
    PLAYER_MOVE_RIGHT_SHEET,
    PLAYER_MOVE_LEFT_SHEET,
    BASIC_MELEE_ATTACK_SHEET,
    BASIC_MELEE_ATTACK_DOWN_SHEET,
    //------------enemies---------------
    RAT_IDLE_DOWN,
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

enum UNIT_TYPES {
    PLAYER,
    RAT
};