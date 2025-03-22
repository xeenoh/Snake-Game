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
};

inline State::~State() {}

class PlayState : public State
{
private:
    int current_score;
    std::shared_ptr<Snake> m_snake;
    std::shared_ptr<Entity> m_snakeHead;
    std::vector<Vector2> m_collectables;
    Render render;

    int targetFrames;
    int counterFrames;
    Direction dir;
    // COLLISION DETECTION//
    bool checkCollision();
    bool bodyCollision();
    bool wallCollision();

    // SNAKE  MOVEMENT //
    Vector2 nextHeadPos();
    void updateSnake();
    void movePerFrame();

    std::shared_ptr<Entity> get_head();

    void ScoreUI();

    Vector2 randomCollectablePosition();

public:
    PlayState();

    void m_Render() override; // Renders Snake , Board , Score UI
    void m_Update() override; // Play State Loop
    void m_KeyboardInput() override;
    void setTargetFrames(int val);
    int getStateIdentifier() const override;
    bool game_over; // Game over flag
};
