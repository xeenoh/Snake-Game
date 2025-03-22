#include "include/raylib.h"
// ! TO BE DELETED
#include "headers/uiStates.h"
#include "include/raygui.h"
#include <iostream>
#include "headers/engine.h"

int main()
{

    // TODO
    /*
        1. Remove Render and make a class that encapsulate the game loop
        2. Add RENDER, GAME STATE in that class
        3. Run the class in the main.cpp
    */

    Engine engine;
    engine.init();
    engine.startGame();
}