#pragma once
#include "entity.h"
#include <memory>
#include <vector>

class Snake
{
public:
    Snake();
    void increaseSize();
    void initialState();
    std::vector<std::shared_ptr<Entity>> getBody() const;
    int getSnakeLength() const;

private:
    std::vector<std::shared_ptr<Entity>> body;
    int snakeLength;
};