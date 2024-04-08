#pragma once
#include "../Moving.h"
#include "../GamePlay/Level.h"
#include "../GamePlay/Game.h"
#include "Account.h"

struct MenuScene {
    bool isChanged = 0;
    Texture2D background;
    TextBox title[2];
    TextBox buttons[2][3];
    Selector2D selector = {0, 0};
    Account account;

    void setup();
    Scene draw(bool& isSigned);
};