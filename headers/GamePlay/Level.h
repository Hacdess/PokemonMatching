#pragma once
#include "../Moving.h"

struct LevelScene {
    unsigned short int count;
    Color background;
    TextBox TextBoxs[5];
    Selector1D selector;

    void setup();
    Level draw(GameStatus& action);
};