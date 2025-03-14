#include "include/raylib.h"
// ! TO BE DELETED
#include "headers/uiStates.h"
#include "raygui.h"
#include <iostream>

int main()
{

    // TODO
    /*
        1. Remove Render and make a class that encapsulate the game loop
        2. Add RENDER, GAME STATE in that class
        3. Run the class in the main.cpp
    */

    UIUtils ui;
    std::shared_ptr<State> game;
    std::cout << "Hello From the Rewrite\n";

    InitWindow(WIDTH, WINDOW_HEIGHT, "SNAKE GAME");
    GuiLoadStyle("./Styles/style_terminal.rgs");

    game = std::make_shared<PlayState>();
    bool iMenu = true;
    while (!WindowShouldClose())
    {

        if (IsKeyPressed(KEY_X))
            break;

        BeginDrawing();
        ClearBackground(BLACK);
        if (iMenu)
        {
            if (ui.test() == 1 || ui.test() == 3)
                break;
            else if (ui.test() == 2)
                iMenu = false;
        }
        else
        {

            game->m_Update();
        }

        EndDrawing();
    }
    CloseWindow();
    return 0;
}