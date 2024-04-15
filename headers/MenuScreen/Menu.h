#pragma once
#include "../Moving.h"
#include "../GamePlay/Level.h"
#include "../GamePlay/Game.h"
#include "Account.h"
#include "Leaderboard.h"
#include "Guide.h"

struct MenuScene {
    bool isChanged = 0;
    Texture2D background;
    TextBox title[2];
    TextBox buttons[2][3];
    Selector2D selector = {0, 0};
    char* username;

    void setup();
    Scene draw(bool& isSigned);
};