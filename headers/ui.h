#pragma once
#include "../include/raylib.h"

class UIUtils
{

public:
    UIUtils() = default;
    int MessageBox(int Width, int Height, Vector2 position,
                   const char *title, const char *message, const char *buttons);
};

// class UIMainMenu
// {

// public:
// private:
// };
