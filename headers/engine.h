#pragma once
#include "stateController.h"
#include "raygui.h"

class Engine
{
public:
    Engine() = default;
    void init();
    void startGame();

private:
    stateController state_controller;
    void m_KeyboardInput();
};
