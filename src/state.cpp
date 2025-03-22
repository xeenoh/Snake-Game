#include "../headers/state.h"

#define NORMAL_SPEED 150
#define HIGH_SPEED 100

PlayState::PlayState() : targetFrames(NORMAL_SPEED), dir(RIGHT), counterFrames(0), current_score(0), game_over(false)
{

    m_snake = std::make_shared<Snake>();
    m_snakeHead = get_head();
}

//=======================================HELPER FUNCTION==================================//

std::shared_ptr<Entity> PlayState::get_head()
{
    return m_snake->getBody().front();
}

// ======================================= COLLISION DETECTION ==========================//

bool PlayState::checkCollision()
{
    return bodyCollision() || wallCollision();
}

bool PlayState::bodyCollision()
{
    const int current_length = m_snake->getSnakeLength();
    if (current_length == 3)
        return false;

    for (size_t i = 1; i < m_snake->getSnakeLength(); ++i)
    {
        if (m_snakeHead->getPosition() == m_snake->getBody()[i]->getPosition())
        {
            return true;
        }
    }

    return false;
}

bool PlayState::wallCollision()
{
    m_snakeHead = get_head();
    Vector2 head_pos = m_snakeHead->getPosition();

    if (head_pos.x < 0 || head_pos.x + CELL > WIDTH)
        return true;
    else if (head_pos.y < 0 || head_pos.y + CELL > HEIGHT)
        return true;
    return false;
}

// ========================================= Handle Keyboard Inputs ============================//

void PlayState::m_KeyboardInput()
{
    if (IsKeyPressed(KEY_RIGHT) && dir != LEFT)
        dir = RIGHT;
    else if (IsKeyPressed(KEY_LEFT) && dir != RIGHT)
        dir = LEFT;
    else if (IsKeyPressed(KEY_UP) && dir != DOWN)
        dir = UP;
    else if (IsKeyPressed(KEY_DOWN) && dir != UP)
        dir = DOWN;
    else if (IsKeyDown(KEY_LEFT_SHIFT))
        setTargetFrames(HIGH_SPEED);
    else if (IsKeyReleased(KEY_LEFT_SHIFT))
        setTargetFrames(NORMAL_SPEED);
    // else if (IsKeyPressed(KEY_P))
    // {
    //     this->current_score++;
    // }
}
//========================================== MOVEMENT ==========================================//
void PlayState::movePerFrame()
{
    if (counterFrames >= targetFrames)
    {
        updateSnake();
        counterFrames = 0;
    }
    else
    {

        counterFrames++;
    }
}

void PlayState::setTargetFrames(int val)
{
    this->targetFrames = val;
}

Vector2 PlayState::nextHeadPos()
{
    m_snakeHead = get_head();
    Vector2 currentPos = m_snakeHead->getPosition();
    if (dir == RIGHT)
        return Vector2Add(currentPos, Vector2{CELL, 0});
    else if (dir == LEFT)
        return Vector2Add(currentPos, Vector2{-CELL, 0});
    else if (dir == UP)
        return Vector2Add(currentPos, Vector2{0, -CELL});
    else
        return Vector2Add(currentPos, Vector2{0, CELL});
}

// TODO SNAKE MOVEMENT

void PlayState::updateSnake()
{
    if (checkCollision())
    {
        std::cout << "You LOST at pos " << m_snakeHead->getPosition().x << ' ' << m_snakeHead->getPosition().y << "\n";
        this->current_score = 0;
        game_over = true;
    }
    std::shared_ptr<Entity> tail = m_snake->getBody().back();
    Vector2 tailPos = tail->getPosition();

    tail->setPosition(nextHeadPos());
    Body new_body = m_snake->getBody();
    new_body.push_front(tail);
    new_body.pop_back();
    m_snake->setBody(new_body);
}

void PlayState::m_Render()
{
    //  Render the Game board
    render.DrawGameBoard();

    // Render the Snake
    render.DrawSnake(*m_snake);

    if (m_collectables.empty())
    {
        Vector2 collectable_position = randomCollectablePosition();
        m_collectables.push_back(collectable_position);
    }
    for (auto const &i : m_collectables)
    {

        render.DrawCollectable(i);
    }

    // TODO Render the collectables
    // TODO Render UI Score board
}

void PlayState::m_Update()
{

    if (game_over)
        return;
    m_KeyboardInput();
    movePerFrame();
    m_Render();
    ScoreUI();
}

void PlayState::ScoreUI()
{

    int score = this->current_score;
    std::string scoreText = std::to_string(score);

    DrawText("Score", 20, 700, 40, RED);
    DrawText(scoreText.c_str(), 200, 700, 40, ORANGE);
}

Vector2 PlayState::randomCollectablePosition()
{
    float posx = (float)GetRandomValue(0, WIDTH - CELL);
    float posy = (float)GetRandomValue(0, HEIGHT - CELL);

    std::cout << "\n\nCollectable Position: " << posx << ' ' << posy << '\n';
    return Vector2{posx, posy};
}

int PlayState::getStateIdentifier() const { return 1; }