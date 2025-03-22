#include "../headers/stateController.h"

stateController::stateController()
{
    init();
}
void stateController::init()
{
    add_new_state(2);
}
int stateController::get_current_state()
{
    return state_container.top()->getStateIdentifier();
}

void stateController::add_new_state(int state_flag)
{
    myStates new_state;
    if (state_flag == 1)
        new_state = std::make_unique<PlayState>();
    else if (state_flag == 2)
        new_state = std::make_unique<UIMenuState>();
    else if (state_flag == 3)
        new_state = std::make_unique<UIGameOverState>();

    state_container.push(std::move(new_state));
}

void stateController::pop_state()
{
    if (!state_container.empty())
        state_container.pop();
}

void stateController::change_state(int state_flag)
{
    pop_state();
    add_new_state(state_flag);
}

void stateController::run_current_state()
{
    // int current_state_flag = get_current_state();
    // myStates current_state;
    // if (current_state_flag == 1)
    //     current_state = std::make_unique<PlayState>();
    // else if (current_state_flag == 2)
    //     current_state = std::make_unique<UIMenuState>();
    // else if (current_state_flag == 3)
    //     current_state = std::make_unique<UIGameOverState>();

    // current_state->m_Update();

    if (!state_container.empty())
    {
        state_container.top()->m_Update();
    }
}