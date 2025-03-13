#pragma once

#include "../include/raylib.h"
#include "../headers/entity.h"
#include "../headers/snake.h"
#include <iostream>
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
    Render();
    void DrawEntity(Entity &e);
    void DrawSnake(const Snake &s);
    void DrawGameBoard();

    void DrawCollectable(const Vector2 &pos);

    // TODO : Draw Textures of COLLECTABLES
    ~Render();

private:
    std::shared_ptr<Texture2D> texture;
};
