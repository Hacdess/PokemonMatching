#pragma once
#include "../Moving.h"

struct Pokemon {
    unsigned int ID;
    Texture2D img;
    Color cover = WHITE;
    Rectangle border;
};

struct GameBoard {
    Texture2D HiddenBackground;
    Pokemon** pokemons;
    Rectangle border; //Viền
    Color BorderColor;
};

struct GameScene {
    unsigned int count;
    Texture2D background;
    GameBoard gameboard;
    TextBox TextBoxs[5];
    Selector2D selector = {0,0};

    void setup();
    void draw();
};