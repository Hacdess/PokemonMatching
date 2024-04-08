#pragma once
#include "../Moving.h"

struct ResultScene {
    bool Victory = 0;
    const Rectangle background = {0, 0, float(WinWdith), float(WinHeight)};
    const Color BackgrounColor = DarkCyan;
    TextBox result, player, score, time;
    setup();
    draw();
};