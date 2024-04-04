#pragma once
#include "../Moving.h"
#include "Level.h"

struct Pokemon {
    bool shown = 0, seleected = 0;
    unsigned short int ID;
    Rectangle border;
    Texture2D img;
    Color cover;
    Color back;
    Vector2 pos;
    float size;
    void draw();
};

Texture2D* readImage(const unsigned short int& quantity);
void shuffle1D(Pokemon* Po1D, const unsigned short& size);

struct GameBoard {
    Texture2D HiddenBackground, *PokemonsImg;
    Rectangle border; //Viền
    Color BorderColor;
    unsigned short int row, col;
    float width, height;
    Pokemon** pokemons;
    Selector2D selector = {1,1};

    void createTable (const unsigned short& quantity);
    bool isEmpty();
    void draw();
};

struct GameScene {
    Texture2D background;
    GameBoard gameboard;

    void setup();
    Scene draw(GameAction& action, Scene scene, Level& level, LevelScene& LEVEL);
};