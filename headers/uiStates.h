#pragma once
#include "../include/raylib.h"
#include "state.h"

class UIUtils
{

public:
    UIUtils() = default;
    int MessageBox(float Width, float Height, Vector2 position,
                   const char *title, const char *message, const char *buttons);

    bool Button(float Width, float Height, Vector2 pos, const char *title);

    int RenderMainMenu();
};

class RenderUIMenuState : public State
{
private:
    UIUtils ui;

    void RenderMainMenu();

public:
    RenderUIMenuState() = default;
    void m_Update() override;
    void m_Render() override;
    void m_KeyboardInput() override;
};