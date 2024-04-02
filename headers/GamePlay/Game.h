#pragma once
#include "../Moving.h"

struct Pokemon {
    unsigned short int ID;
    Texture2D img;
    Color cover = WHITE;
    Rectangle border;
};

struct GameBoard {
    Texture2D HiddenBackground, *PokemonsImg;
    Rectangle border; //Viền
    Color BorderColor;
    unsigned short int row, col;
    Pokemon** pokemons;

    void suffle();
};

struct GameScene {
    Texture2D background;
    GameBoard gameboard;
    Selector2D selector = {1,1};

    Texture2D* readImage(const unsigned short int& quantity);   

    void setup();
    void draw();
};