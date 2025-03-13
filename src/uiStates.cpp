#define RAYGUI_IMPLEMENTATION
#include "../include/raygui.h"
#include "../headers/uiStates.h"

int UIUtils::MessageBox(float Width, float Height,
                        Vector2 position, const char *title, const char *message, const char *buttons)
{

    GuiLoadStyle("./Styles/style_terminal.rgs");
    return GuiMessageBox((Rectangle){position.x, position.y, (float)Width, (float)Height}, title,

                         message, buttons);
}

bool UIUtils::Button(float Width, float Height, Vector2 pos, const char *title)
{
    GuiLoadStyle("./Styles/style_terminal.rgs");
    return GuiButton((Rectangle){pos.x, pos.y, Width, Height}, title);
}

int UIUtils::RenderMainMenu()
{
    // TODO Render a Background

    // Render Window Box
    GuiLoadStyle("./Styles/style_terminal.rgs");
    GuiSetStyle(DEFAULT, TEXT_SIZE, 40);
    if (GuiWindowBox((Rectangle){0, 0, WIDTH, WINDOW_HEIGHT}, ""))
        return 1;

    DrawText("Snake", 350, 200, 70, GREEN);
    // Render Button 1 : Play
    if (GuiButton((Rectangle){350, 450, 200, 70}, "Play"))
        return 2;
    // Render Button 2: Exit
    if (GuiButton((Rectangle){350, 550, 200, 70}, "Exit"))
        return 3;

    return -1;
}
// ===================================== MAIN MENU STATE ================================ //

void RenderUIMenuState::RenderMainMenu()
{
    // TODO Render a Background

    // Render Window Box
    int window_box = GuiWindowBox((Rectangle){0, 0, WIDTH, HEIGHT}, "Hello");

    // Render Text Box with "Snake game"

    // Render Button 1 : Play

    // Render Button 2: Exit
}

void RenderUIMenuState::m_Render()
{
    RenderMainMenu();
}