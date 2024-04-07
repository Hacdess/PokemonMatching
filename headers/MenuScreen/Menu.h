#pragma once
#include "../Moving.h"
#include "../GamePlay/Level.h"
#include "../GamePlay/Game.h"
#include "Account.h"

struct MenuScene {
    Texture2D background;
    TextBox title[2];
    TextBox buttons[2][3];
    Selector2D selector = {0, 0};
    Account account;

    void setup();
    Scene draw(bool& isSigned);
};