#include "../headers/entity.h"

Entity::Entity(Vector2 position_) : position(position_) {}

Vector2 Entity::getPosition() const
{
    return position;
}

Entity &Entity::setPosition(Vector2 pos)
{
    this->position = pos;
    return *this;
}