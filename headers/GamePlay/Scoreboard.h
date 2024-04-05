#pragma once
#include "../Moving.h"

struct ScoreBoard {
    Rectangle border = {float (WinWdith) / 3 * 2, float (WinHeight) / 4, float (WinHeight) / 2, float (WinHeight) / 2};
    Color background = BlackTrans;



    TextBox Title,
            Player,
            Score,
            Hint;

    float HealthFull = float (WinHeight) / 3,
            HealthUnit = HealthFull / 5;
    
    short health = 5;

    Rectangle HP_Full = {border.x + (border.width - HealthFull) / 2, 0, 0, 0 }

}