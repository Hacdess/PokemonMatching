#pragma once
#include "../Moving.h"

struct GameModeScene {
    float time;
    Color background;
    TextBox TextBoxs[3];
    short selector;

    void setup();
    bool draw(GameAction& action);
};

struct LevelScene {
    float time;
    Color background;
    TextBox TextBoxs[5];
    short selector;

    void setup();
    Level draw(GameAction& action);
};