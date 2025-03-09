#include "../headers/snake.h"

Snake::Snake() : m_snakeLength(3)
{

    initialState();
}

void Snake::initialState()
{
    if (!m_body.empty())
    {
        m_body.clear();
    }

    std::vector<Vector2> initialpositions = {Vector2{30.0f, 30.0f},
                                             Vector2{60.0f, 30.0f},
                                             Vector2{90.0f, 30.0f}};

    m_body.emplace_back(std::make_shared<Entity>(initialpositions[0]));
    m_body.emplace_back(std::make_shared<Entity>(initialpositions[1]));
    m_body.emplace_back(std::make_shared<Entity>(initialpositions[2]));
    m_snakeLength = 3;
}

Body Snake::getBody() const
{
    return m_body;
}

void Snake::increaseSize()
{
    Vector2 lastSegment = m_body.back()->getPosition();
    Vector2 secondLastSegment = m_body[m_body.size() - 2]->getPosition();
    Vector2 direction = Vector2Subtract(lastSegment, secondLastSegment);
    Vector2 newpos = Vector2Add(lastSegment, direction);
    std::shared_ptr<Entity> newSegement = std::make_shared<Entity>(newpos);
    m_body.emplace_back(newSegement);
    ++m_snakeLength;
}

int Snake::getSnakeLength() const
{
    return m_snakeLength;
}