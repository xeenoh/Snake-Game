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

    // int current_state = state_controller.get_current_state();
    // if (current_state == 1)
    // {
    //     if (IsKeyPressed(KEY_ESCAPE))
    //     {
    //         state_controller.change_state(2);
    //     }
    // }

    return;
}

// GAME LOOP
void Engine::startGame()
{
    InitWindow(WIDTH, WINDOW_HEIGHT, "SNAKE GAME");
    void *window = GetWindowHandle();
    GuiLoadStyle("./Styles/style_terminal.rgs");
    state_controller.init();
    bool window_exist = !WindowShouldClose();
    while (window_exist)
    {

        m_KeyboardInput();
        BeginDrawing();
        ClearBackground(BLACK);
        int current_state = state_controller.get_current_state();
        State &currentstate = state_controller.getstate();
        if (current_state == 2)
        {
            UIMenuState *menuState = dynamic_cast<UIMenuState *>(&state_controller.getstate());

            if (menuState->close_window)
                break;
            if (menuState->updateState) // transition from main menu to play state
            {
                state_controller.change_state(1);
            }
        }
        else if (current_state == 1)
        {
            PlayState *playState = dynamic_cast<PlayState *>(&state_controller.getstate());
            if (IsKeyPressed(KEY_Q))
                state_controller.change_state(2);
            if (playState->game_over)
            {
                state_controller.change_state(3);
            }
        }
        else if (current_state == 3)
        {

            UIGameOverState *gameoverstate = dynamic_cast<UIGameOverState *>(&state_controller.getstate());
            if (gameoverstate->close_window)
                break;
            if (gameoverstate->updateState)
            {
                std::cout << "Current STATE running is : " << state_controller.get_current_state() << '\n';
                state_controller.change_state(1); // return back to the previous state which was play state
                std::cout << "Current STATE running is : " << state_controller.get_current_state() << '\n';
            }
        }
        state_controller.run_current_state();

        EndDrawing();
    }
    CloseWindow();
}