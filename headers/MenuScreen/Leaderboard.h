#pragma once
#include "../Moving.h"
#include "Account.h"

struct Player {
    short score;
    Time time;
    TextBox name, ScoreText, TimeText;
    Player *next;
};

struct StageScene {
    const Color background = WHITE;
    TextBox constant[5];
    Player* list;
    void setup();
    void draw();
};

struct LeaderboardSceen {
    StageScene stages[3];
    short selector;
    void setup();
    Scene draw();
};
