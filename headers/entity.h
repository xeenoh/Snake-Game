#pragma once
#include "../include/raylib.h";
#include "../include/raymath.h";

class Entity
{
public:
    Entity(Vector2 position_);
    Vector2 getPosition() const;
    void setPosition();

private:
    Vector2 position;
};