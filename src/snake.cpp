#include "../headers/snake.h"

Snake::Snake()
{

    std::shared_ptr<Entity> e1 = std::make_shared<Entity>()
}

void Snake::initialState()
{
    if (!body.empty())
    {
        body.clear();
    }

    Vector2 pos1 = Vector2{30.0f, 60.0f};
}