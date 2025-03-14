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
    int test();
};

class UIMenuState : public State
{
private:
    UIUtils ui;

    int RenderMainMenu();

public:
    UIMenuState() = default;
    void m_Update() override;
    void m_Render() override;
    void m_KeyboardInput() override;
};

class UIGameOverState : public State
{
private:
    UIUtils ui;
    int RenderGameOverMenu();

public:
    UIGameOverState() = default;
    void m_Update() override;
    void m_Render() override;
    void m_KeyboardInput() override;
};