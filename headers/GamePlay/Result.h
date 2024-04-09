#pragma once
#include "../Moving.h"

struct ResultScene {
    bool isSet = 0;
    bool isVictory = 0;
    float markTime;
    const Rectangle background = {0, 0, float(WinWdith), float(WinHeight)};
    const Color BackgrounColor = DARKGRAY;
    TextBox result, player, time, score, message;

    void setup();
    Scene draw(GameAction& action);
};