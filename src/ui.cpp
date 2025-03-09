#define RAYGUI_IMPLEMENTATION
#include "../include/raygui.h"
#include "../headers/ui.h"

int UIUtils::MessageBox(int Width, int Height,
                        Vector2 position, const char *title, const char *message, const char *buttons)
{
    return GuiMessageBox((Rectangle){position.x, position.y, Width, Height}, title,
                         message, buttons);
}