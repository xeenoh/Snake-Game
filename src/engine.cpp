#include "../headers/engine.h"

void Engine::init()
{
    state_controller.init();
}

void Engine::m_KeyboardInput()
{
    /**
     * while state => playstate
                if keypressed is 'ESC'
                    changestate =>  Main Menu
            [TODO]
                if keypressed is 'p'
                add new state => pauseMenu

    */

    int current_state = state_controller.get_current_state();
    if (current_state == 1)
    {
        if (IsKeyPressed(KEY_ESCAPE))
        {
            state_controller.change_state(2);
        }
    }

    return;
}

// GAME LOOP
void Engine::startGame()
{
    InitWindow(WIDTH, WINDOW_HEIGHT, "SNAKE GAME");
    state_controller.init();
    while (!WindowShouldClose())
    {

        m_KeyboardInput();
        if (IsKeyPressed(KEY_X))
            break;

        BeginDrawing();
        ClearBackground(BLACK);
        state_controller.run_current_state();
        EndDrawing();
    }
    CloseWindow();
}