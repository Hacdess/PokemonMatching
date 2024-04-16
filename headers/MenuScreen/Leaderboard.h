#pragma once
#include "../Moving.h"
#include "Account.h"
#include "../GamePlay/Music.h"
struct Player {
    short score;
    Time time;
    TextBox rank, name, ScoreText, TimeText;
};

struct PlayerNode {
    Player data;
    PlayerNode *next;
    PlayerNode (Player input) {
        data.score = input.score;
        data.time.hour = input.time.hour;
        data.time.min = input.time.min;
        data.time.sec = input.time.sec;
        addText (data.name.content, input.name.content);
        addText (data.ScoreText.content, input.ScoreText.content);
        addText (data.TimeText.content, input.TimeText.content); 
        next = NULL;
    }
};

struct PlayerList {
    PlayerNode *head, *tail;
};

struct StageScene {
    const Color background = WHITE;
    TextBox constant[5];
    PlayerList list;
    short lengthList;
    void getList(const Level& level);
    void setup(const Level& level);
    void draw();
};

struct LeaderboardSceen {
    bool isSet = 0;
    StageScene stages[3];
    short selector;
    void setup();
    Scene draw(gameMusic& musicAndSound);
};