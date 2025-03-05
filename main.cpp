#include "include/raylib.h"
#include "headers/render.h"
#include <iostream>

int main()
{

    // TODO
    /*
        1. Remove Render and make a class that encapsulate the game loop
        2. Add RENDER, GAME STATE in that class
        3. Run the class in the main.cpp
    */
    Render render;
    std::cout << "Hello From the Rewrite\n";

    InitWindow(WIDTH, WINDOW_HEIGHT, "SNAKE GAME");

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_X))
            break;
        BeginDrawing();
        ClearBackground(BLACK);
        render.DrawGameBoard();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}