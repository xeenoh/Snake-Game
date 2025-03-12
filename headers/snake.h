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
    const Body &getBody() const;
    int getSnakeLength() const;

    void setBody(Body newBody);

private:
    Body m_body;
};