#pragma once

#include "../include/raylib.h"
#include <vector>
#define WIDTH 900
#define HEIGHT 600
#define CELL 30
#define WINDOW_HEIGHT 800
// TODO Delete Entity Forward Decelartion after implementing the entity class
class Entity;

using snake = std::vector<Entity>;

class Render
{
public:
    Render() = default;
    void DrawEntity(Entity &e);
    void DrawSnake(snake &s);
    void DrawGameBoard();
};
