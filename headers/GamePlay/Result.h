#pragma once
#include "../Moving.h"

struct ResultScene {
    bool isSet = 0;
    bool isVictory = 0;
    float markTime;
    const Rectangle background = {0, 0, float(WinWdith), float(WinHeight)};
    const Color BackgrounColor = DARKGRAY;
    TextBox result, player[2], time, score[2], message;

    void setup(const bool& isDual);
    Scene draw(GameAction& action, const bool& isDual);
};