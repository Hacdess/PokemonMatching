#pragma once
#include "../Moving.h"

struct LevelScene {
    short count;
    Color background;
    TextBox TextBoxs[5];
    short selector;

    void setup();
    Level draw(GameAction& action);
};