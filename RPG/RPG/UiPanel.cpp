#include "UiPanel.h"

UiPanel::UiPanel()
{
    init();
}

UiPanel::UiPanel(int xpos, int ypos, int panelWidth, int panelHeight)
{
    init(xpos, ypos, panelWidth, panelHeight);
}

UiPanel::UiPanel(int xpos, int ypos, int panelWidth, int panelHeight, SDL_Color panelColour)
{
    init(xpos, ypos, panelWidth, panelHeight);
    colour = panelColour;
}

void UiPanel::init()
{
    x = y = width = height = 0;
    colour = { 0, 0, 0 };
    active = true;
}

void UiPanel::init(int xpos, int ypos, int panelWidth, int panelHeight)
{
    init();
    x = xpos;
    y = ypos;
    width = panelWidth;
    height = panelHeight;
}
