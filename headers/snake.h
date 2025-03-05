#pragma once
#include "entity.cpp"
#include <memory>
#include <vector>

class Snake
{
public:
    Snake();
    void increaseSize();

    void initialState();

private:
    std::vector<std::shared_ptr<Entity>> body;
};