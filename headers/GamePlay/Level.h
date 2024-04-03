#pragma once
#include "../Moving.h"

struct LevelScene {
    unsigned short int count;
    Color background;
    TextBox TextBoxs[5];
    short int selector;

    void setup();
    Level draw(GameAction& action);
};