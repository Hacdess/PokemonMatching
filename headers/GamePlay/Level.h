#pragma once
#include "../Moving.h"
#include "../GamePlay/Music.h"

struct GameModeScene {
    float time;
    Color background;
    TextBox TextBoxs[4];
    short selector;

    void setup();
    bool draw(GameAction& action, gameMusic& MusicAndSound);
};

struct LevelScene {
    float time;
    Color background;
    TextBox TextBoxs[5];
    short selector;

    void setup();
    Level draw(GameAction& action, gameMusic& musicAndSound);
};