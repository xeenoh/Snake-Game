#pragma once

#include "../include/raylib.h"
#include "../headers/entity.h"
#include "../headers/snake.h"
#include <vector>
#define WIDTH 900
#define HEIGHT 600
#define CELL 30
#define WINDOW_HEIGHT 800

class Snake;
// TODO Replace Snake with a snake class
class Render
{
public:
    Render() = default;
    void DrawEntity(Entity &e);
    void DrawSnake(const Snake &s);
    void DrawGameBoard();

    // TODO : Draw Textures of COLLECTABLES
};
