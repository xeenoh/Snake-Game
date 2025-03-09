#pragma once
#include "../headers/entity.h"
#include "../headers/snake.h"
#include "../headers/render.h"
#include "../headers/ui.h"

//  FINITE STATE MACHINE //

// PURE ABSTARCT CLASS TO MANAGE GAME STATES
class State
{

public:
    virtual void Render() = 0;
    virtual void Update() = 0;
    virtual ~State() = 0;
};

class PlayState : public State
{
};

class RenderUIMenuState : public State
{
};

class RenderUIPauseMenu : public State
{
};