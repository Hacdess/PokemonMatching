#pragma once
#include "../Moving.h"
#include "Account.h"

struct Player {
    Account account; // Save the username
    Time time;
    short score;
    Player *next;
};

struct StageScene {
    TextBox level;
    Player* list;
};

struct  LeaderboardSceen {
    StageScene stages[3];
};
