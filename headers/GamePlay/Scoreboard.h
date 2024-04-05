#pragma once
#include "../Moving.h"

struct ScoreBoard {
    const Rectangle border = {float (WinWdith) / 3 * 2,
                float (WinHeight) / 4, float (WinHeight) / 2, float (WinHeight) / 2};
    const Color background = BlackTrans;

    TextBox Title, Player, Score, Hint;

    short ScoreNum;
    char* ScoreText;

    float HealthFull = float (WinHeight) / 3,
            HealthUnit = HealthFull / 5;
    
    short health = 5;

    Rectangle HP_Bar = {border.x + (border.width - HealthFull) / 2, , HealthFull, HealthUnit};
    Rectangle HP = {HP_Full.x, HP_Full.y, HealthUnit * health, HP_Full.height};

    Color HP_Bar_Color = RED;
    Color HP_Color = GREEN;

    bool showHint;

    void getScore();
    void setup();
    void updatePlayer(char* name);
    void updateHint();
    void draw();
}