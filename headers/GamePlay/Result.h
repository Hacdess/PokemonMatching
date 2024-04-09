#pragma once
#include "../Moving.h"

struct ResultScene {
    bool isSet = 0;
    bool isVictory = 0;
    short StartCount;
    const Rectangle background = {0, 0, float(WinWdith), float(WinHeight)};
    const Color BackgrounColor = DarkCyan;
    TextBox result, player, time, score, message;

    void setup();
    Scene draw(GameAction& action);
};