#include "include/raylib.h"
#include "headers/render.h"
#include <iostream>

int main()
{

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