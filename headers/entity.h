#pragma once
#include "../include/raylib.h"
#include "../include/raymath.h"
#include <cassert>

class Entity
{
public:
    Entity(Vector2 position_);
    Vector2 getPosition() const;
    Entity &setPosition(const Vector2 &pos);

private:
    Vector2 position;
};