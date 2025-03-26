#include "../headers/state.h"

#define NORMAL_SPEED 150
#define HIGH_SPEED 90
#define TOTAL_CELLS (WIDTH * HEIGHT) / CELL

PlayState::PlayState() : targetFrames(NORMAL_SPEED), dir(RIGHT), counterFrames(0), current_score(0), game_over(false), win_flag(false)
{

    m_snake = std::make_shared<Snake>();
    m_snakeHead = get_head();
    gameSound.PlayGameMusic();
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
    Body snake_body = m_snake->getBody();
    Vector2 pos = snake_body[0]->getPosition();
    for (size_t i = 1; i < snake_body.size(); ++i)
    {
        if (pos == snake_body[i]->getPosition())
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

    if (head_pos.x < 0 || head_pos.x > WIDTH - CELL || head_pos.y < 0 || head_pos.y > HEIGHT - CELL)
    {
        std::cout << "Wall Collision\n";
        return true;
    }
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
    for (auto &i : m_collectables)
    {

        render.DrawCollectable(i);
    }
}

void PlayState::m_Update()
{

    if (game_over)
    {
        game_over = false;

        m_snake->initialState();
        m_snakeHead = get_head();
        setTargetFrames(NORMAL_SPEED);
        m_collectables.clear();
        dir = RIGHT; // Reset the Direction
        current_score = 0;
        return;
    }
    else if (checkWin())
    {
        std::cout << "YOU WON\n";
    }
    if (increaseScore(m_collectables.back()))
    {
        m_snake->increaseSize();
        current_score++;
    }
    UpdateMusicStream(gameSound.game_music);
    movePerFrame();
    ScoreUI();
    ControlsUI();
}

void PlayState::ScoreUI()
{

    std::string scoreText = std::to_string(current_score);

    DrawText("Score", 20, 700, 40, RED);
    DrawText(scoreText.c_str(), 200, 700, 40, ORANGE);
}

void PlayState::ControlsUI()
{
    DrawText("Controls", 450, 610, 50, WHITE);
    DrawText("Movement: ARROWS", 450, 660, 30, WHITE);
    DrawText("Speed Boost : Hold LSHIFT", 450, 700, 30, WHITE);
    DrawText("Main Menu : Q", 450, 740, 30, WHITE);
}
Vector2 PlayState::randomCollectablePosition()
{
    int posx = GetRandomValue(0, (WIDTH / CELL) - 1);
    int posy = GetRandomValue(0, (HEIGHT / CELL) - 1);

    Vector2 pos = {posx * CELL, posy * CELL};

    // check if valid position (Not on the snake body)
    for (const auto &i : m_snake->getBody())
    {
        if (i->getPosition() == pos)
            randomCollectablePosition();
    }
    std::cout << "\n\nCollectable Position: " << pos.x << ' ' << pos.y << '\n';
    return pos;
}

int PlayState::getStateIdentifier() const { return 1; }

bool PlayState::checkWin()
{
    if (m_snake->getBody().size() == TOTAL_CELLS)
        return true;
    return false;
}

bool PlayState::increaseScore(const Vector2 &pos)
{
    Vector2 pos_head = m_snake->getBody()[0]->getPosition();
    if (pos == pos_head)
    {
        gameSound.PlayCollectableSound();
        m_collectables.clear();
        return true;
    }
    return false;
}
