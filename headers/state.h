#pragma once
#include "../headers/entity.h"
#include "../headers/snake.h"
#include "../headers/render.h"
#include <iostream>

enum Direction
{
    LEFT,
    RIGHT,
    UP,
    DOWN
};
//  FINITE STATE MACHINE //

// PURE ABSTARCT CLASS TO MANAGE GAME STATES
class State
{

public:
    State() = default;
    virtual void m_Render() = 0;
    virtual void m_Update() = 0;
    virtual void m_KeyboardInput() = 0;
    virtual int getStateIdentifier() const = 0;
    virtual ~State() = 0;
    bool updateState;
};

inline State::~State() {}

class PlayState : public State
{
private:
    Render render;
    Direction dir;

    int current_score;
    std::shared_ptr<Snake> m_snake;
    std::shared_ptr<Entity> m_snakeHead;
    std::vector<Vector2> m_collectables;
    std::shared_ptr<Entity> get_head();

    int targetFrames;
    int counterFrames;

    // COLLISION DETECTION//
    bool checkCollision();
    bool bodyCollision();
    bool wallCollision();

    bool checkWin();
    bool increaseScore(const Vector2 &pos); // check collisoin with the collectable

    // SNAKE  MOVEMENT //
    Vector2 nextHeadPos();
    void updateSnake();
    void movePerFrame();

    Vector2 randomCollectablePosition();

    void ScoreUI();
    void ControlsUI();

    bool win_flag = false;
    bool updateState = false;

public:
    PlayState();

    void m_Render() override; // Renders Snake , Board , Score UI
    void m_Update() override; // Play State Loop
    void m_KeyboardInput() override;
    void setTargetFrames(int val);
    int getStateIdentifier() const override;
    bool game_over; // Game over flag
};
