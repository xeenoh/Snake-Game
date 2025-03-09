#pragma once
#include "entity.h"
#include <memory>
#include <vector>
#include <deque>

using Body = std::deque<std::shared_ptr<Entity>>;

class Snake
{
public:
    Snake();
    void increaseSize();
    void initialState();
    Body getBody() const;
    int getSnakeLength() const;

private:
    Body m_body;
    int m_snakeLength;
};