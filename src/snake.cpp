#include "../headers/snake.h"

Snake::Snake() : snakeLength(3)
{

    initialState();
}

void Snake::initialState()
{
    if (!body.empty())
    {
        body.clear();
    }

    std::vector<Vector2> initialpositions = {Vector2{30.0f, 30.0f},
                                             Vector2{60.0f, 30.0f},
                                             Vector2{90.0f, 30.0f}};

    std::shared_ptr<Entity> e1 = std::make_shared<Entity>(initialpositions[0]);
    std::shared_ptr<Entity> e2 = std::make_shared<Entity>(initialpositions[1]);
    std::shared_ptr<Entity> e3 = std::make_shared<Entity>(initialpositions[2]);

    body.emplace_back(e1);
    body.emplace_back(e2);
    body.emplace_back(e3);
    snakeLength = 3;
}

std::vector<std::shared_ptr<Entity>> Snake::getBody() const
{
    return body;
}

void Snake::increaseSize()
{
    Vector2 lastSegment = body.back()->getPosition();
    Vector2 secondLastSegment = body[body.size() - 2]->getPosition();
    Vector2 direction = Vector2Subtract(lastSegment, secondLastSegment);
    Vector2 newpos = Vector2Add(lastSegment, direction);
    std::shared_ptr<Entity> newSegement = std::make_shared<Entity>(newpos);
    body.emplace_back(newSegement);
    ++snakeLength;
}

int Snake::getSnakeLength() const
{
    return snakeLength;
}