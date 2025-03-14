#include "../headers/render.h"

Render::Render()
{
    LoadCollectableTexture();
}

void Render::LoadCollectableTexture()
{

    if (texture.id != 0)
    {
        std::cout << "Already loaded\n";
        return;
    }
    const char *path = "./Assets/textures/heart.png";
    if (!FileExists(path))
    {
        std::cerr << "This file doesn't exist\n";
        return;
    }

    Image image = LoadImage(path);
    if (image.data == nullptr)
    {
        std::cerr << "Failed to load image data\n";
        return;
    }

    ImageResize(&image, CELL, CELL);
    this->texture = LoadTextureFromImage(image);

    if (texture.id == 0)
    {
        std::cerr << "\n\nFailed to load the texture!!\n";
        UnloadImage(image);
        return;
    }

    UnloadImage(image);
}
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

void Render::DrawEntity(Entity &e)
{
    Vector2 position = e.getPosition();
    DrawRectangle(position.x, position.y, CELL, CELL, GREEN);
    DrawRectangleLines(position.x, position.y, CELL, CELL, BLACK);
}

void Render::DrawSnake(const Snake &s)
{
    for (auto &i : s.getBody())
    {
        DrawEntity(*i);
    }
}

void Render::DrawCollectable(const Vector2 &pos)
{
    DrawTexture(texture, pos.x, pos.y, WHITE);
}
Render::~Render()
{
    if (texture.id != 0)
        UnloadTexture(texture);
}