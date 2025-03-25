#pragma once
#include "state.h"
#include "uiStates.h"
#include "stack"

using myStates = std::unique_ptr<State>;

// GAME STATE IDENTIFICATION //
// Play State --> 1
// Main Menu --> 2
// Game Over --> 3

class stateController
{
public:
    stateController();
    int get_current_state();
    void add_new_state(int state_flag);
    void pop_state();
    void change_state(int state_flag);
    void init();
    void run_current_state();
    State &getstate();

private:
    std::stack<myStates> state_container;
};