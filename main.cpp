#include "include/raylib.h"
// ! TO BE DELETED
#include "./headers/render.h"
#include "./headers/snake.h"
#include "./headers/ui.h"
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
    UIUtils ui;
    Snake snake;

    std::cout << "Hello From the Rewrite\n";

    InitWindow(WIDTH, WINDOW_HEIGHT, "SNAKE GAME");

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_X))
            break;
        BeginDrawing();
        ClearBackground(BLACK);
        render.DrawGameBoard();
        render.DrawSnake(snake);

        EndDrawing();
    }
    CloseWindow();
    return 0;
}