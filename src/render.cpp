#include "../headers/render.h"

Render::Render()
{
    LoadCollectableTexture();
}

void Render::LoadCollectableTexture()
{

    const char *path = TEXTURE_PATH;

    if (!FileExists(path))
    {
        std::cerr << "Error: File " << path << " does not exist!\n";
        return;
    }

    Image image = LoadImage(path);
    if (image.data == nullptr)
    {
        std::cerr << "Error: Failed to load image data from " << path << "\n";
        return;
    }

    ImageResize(&image, CELL, CELL);
    texture = std::make_unique<Texture2D>(LoadTextureFromImage(image));

    if (texture->id == 0)
    {
        std::cerr << "Error: Failed to load texture!\n";
        UnloadImage(image);
        return;
    }

    UnloadImage(image);
    std::cout << "Collectable texture loaded successfully!\n";
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

void Render::DrawCollectable(Vector2 &pos)
{
    if (texture)
        DrawTexture(*texture, pos.x, pos.y, WHITE);
}
Render::~Render()
{
    if (texture)
        UnloadTexture(*texture);
}