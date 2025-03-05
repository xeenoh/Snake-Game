#include "../headers/entity.h"

Entity::Entity(Vector2 position_) : position(position_) {}

Vector2 Entity::getPosition() const
{
    return position;
}

void Entity::setPosition(Vector2 pos)
{
    this->position = pos;
}