#pragma once
#include "../items.h"
#include "../Moving.h"
#include "../GamePlay/Level.h"

struct MenuScene {
    Texture2D background;
    TextBox title[2];
    TextBox buttons[2][3];
    Selector2D selector = {0, 0};

    void setup();
    Scene draw(bool& isSigned);
};