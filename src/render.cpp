#include "../headers/render.h"

void Render::DrawGameBoard()
{
    int k = 0;
    for (int i = 0; i < HEIGHT; i += CELL)
    {
        DrawLine(0, i, WIDTH, i, DARKGREEN);
    }
    // Draw Vertical Lines
    for (int i = 0; i < WIDTH; i += CELL)
    {
        DrawLine(i, 0, i, HEIGHT, DARKGREEN);
    }

    // Drawing the border of the window
    DrawLine(0, HEIGHT, WIDTH, HEIGHT, DARKGREEN);
}