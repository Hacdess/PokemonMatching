#pragma once
#include "../items.h"
#include "../Moving.h"

void updateStatus(bool& isSigned, char*& content1, char*& content2);

struct MenuScene {
    Texture2D background;
    TextBox title[2];
    TextBox buttons[2][3];
    Selector2D selector = {0, 0};

    void setup();
    Status draw(bool& isSigned);
};