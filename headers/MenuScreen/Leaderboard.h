#pragma once
#include "../Moving.h"
#include "Account.h"

struct Player {
    short score;
    Time time;
    TextBox name, ScoreText, TimeText;
};

struct PlayerNode {
    Player data;
    PlayerNode* next;
    PlayerNode (Player input) {
        data.score = input.score;
        data.time.hour = input.time.hour;
        data.time.min = input.time.min;
        data.time.sec = input.time.sec;
        addText (data.name.content, input.name);
        addText (data.ScoreText.content, input.ScoreText.content);
        addText (data.TimeText.content, input.TimeText.content); 
    }
};

struct StageScene {
    const Color background = WHITE;
    TextBox constant[5];
    Player* list;
    void getList(const Level& level);
    void setup();
    void draw();
};

struct LeaderboardSceen {
    bool isSet = 0;
    StageScene stages[3];
    short selector;
    void setup();
    Scene draw();
};