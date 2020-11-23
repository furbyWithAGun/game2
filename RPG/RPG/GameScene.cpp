#include "GameScene.h"
#include "BaseGameEngine.h"

//constructors
GameScene::GameScene() {
    init();
}

GameScene::GameScene(BaseGameEngine * newEngine) {
    init();
    engine = newEngine;
}

void GameScene::init() {
    engine = NULL;
    sceneRunning = true;
    gettingTextInput = false;
    controllerInterface = NULL;
}


//public methods

void GameScene::handleInput()
{
    handleTextInput();
}

void GameScene::renderTexture(Texture* texture, int x, int y)
{
    engine->renderTexture(texture, x, y);
}

void GameScene::renderTexture(Texture*  texture, int x, int y, int width, int height)
{
    engine->renderTexture(texture, x, y, width, height);
}

void GameScene::renderTexture(int textureKey, int x, int y)
{
    engine->renderTexture(textureKey, x, y);
}

void GameScene::renderTexture(int textureKey, int x, int y, int width, int height)
{
    engine->renderTexture(textureKey, x, y, width, height);
}

void GameScene::endScene() {
    sceneRunning = false;
    SDL_AtomicUnlock(&engine->sceneRunningLock);
}

void GameScene::openMenu(int menuId) {
    menus[menuId]->open();
}

bool GameScene::sendMessageToMenus(InputMessage* message)
{
    bool messageConsumed = false;
    for (auto menu : menus){
        if (!messageConsumed)
        {
            messageConsumed = menu.second->handleInput(message);
        }
    }
    return messageConsumed;
}

bool GameScene::getNextCommand(InputMessage* message) {
    if (commandQueue.size() > 0)
    {
        *message = *commandQueue[0];
        delete commandQueue[0];
        commandQueue.erase(commandQueue.begin());
        return true;
    }
    else {
        message = NULL;
        return false;
    }
}

void GameScene::addCommand(InputMessage* newMessage) {
    InputMessage* message = new InputMessage();
    *message = *newMessage;
    commandQueue.push_back(message);
}

void GameScene::addCommand(InputMessage newMessage) {
    InputMessage* message = new InputMessage();
    *message = newMessage;
    commandQueue.push_back(message);
}

void GameScene::handleTextInput()
{
    if (controllerInterface != NULL && gettingTextInput)
    {
        controllerInterface->populateTextInputQueue();
        InputMessage* message = new InputMessage();
        while (controllerInterface->getNextTextInput(message))
        {
            switch (message->id)
            {
            case END_SCENE:
                endScene();
                break;
            case K_ESC:
            case K_BACKSPACE:
            case K_ENTER:
            case TEXT_INPUT:
            case SELECT_ON:
            case SELECT_OFF:
            case SCROLL_UP:
            case SCROLL_DOWN:
                sendMessageToMenus(message);
                break;
            default:
                break;
            }
        }
        delete message;
    }
}
