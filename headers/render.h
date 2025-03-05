#pragma once

#include "../include/raylib.h"
#include "../headers/entity.h"
#include <vector>
#define WIDTH 900
#define HEIGHT 600
#define CELL 30
#define WINDOW_HEIGHT 800

// TODO Replace Snake with a snake class
using snake = std::vector<Entity>;

class Render
{
private:
    Entity entity;

public:
    Render() = default;
    void DrawEntity(Entity &e);
    void DrawSnake(snake &s);
    void DrawGameBoard();

    // TODO : Draw Textures of COLLECTABLES
};
