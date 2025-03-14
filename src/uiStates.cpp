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

int UIUtils::test()
{

    if (GuiWindowBox((Rectangle){200, 100, 500, 500}, "You Lost"))
        return 1;

    DrawText("Game Over", 350, 300, 40, RED);
    if (GuiButton((Rectangle){250, 500, 150, 40}, "Restart"))
        return 2;
    // Render Button 2: Exit
    if (GuiButton((Rectangle){550, 500, 100, 40}, "Exit"))
        return 3;

    return -1;
}
// ===================================== MAIN MENU STATE ================================ //

int UIMenuState::RenderMainMenu()
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

    // Render Text Box with "Snake game"

    // Render Button 1 : Play

    // Render Button 2: Exit
}

void UIMenuState::m_Render()
{
    RenderMainMenu();
}

void UIMenuState::m_Update() {}
void UIMenuState::m_KeyboardInput() {}

/////////////////////////////////////////////////////////////////////////////////////

int UIGameOverState::RenderGameOverMenu()
{

    GuiLoadStyle("./Styles/style_terminal.rgs");
    if (GuiWindowBox((Rectangle){0, 0, 500, 500}, "You Lost"))
        return 1;

    if (GuiButton((Rectangle){100, 450, 200, 70}, "Restart"))
        return 2;
    // Render Button 2: Exit
    if (GuiButton((Rectangle){150, 450, 200, 70}, "Exit"))
        return 3;

    return -1;
}