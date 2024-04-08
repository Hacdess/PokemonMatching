#pragma once
#include "../Moving.h"

struct ResultScene {
    bool isVictory = 0;
    short StartCount;
    const Rectangle background = {0, 0, float(WinWdith), float(WinHeight)};
    const Color BackgrounColor = DarkCyan;
    TextBox result, player, score, time;

    void setup();
    Scene draw();
};