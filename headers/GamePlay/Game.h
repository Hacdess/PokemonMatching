#pragma once
#include "../Moving.h"
#include "Level.h"
#include "Path.h"

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
    void unSeen();
};

Texture2D* readImage(const unsigned short int& quantity);
void shuffle1D(Pokemon* Po1D, const unsigned short& size);

struct GameBoard {
    float width, height;
    Texture2D HiddenBackground, *PokemonsImg;

    unsigned short int row, col;
    Pokemon** pokemons;
    Selector2D selector = {1,1}, selected = {0, 0}, remove[4];

    Node* path = NULL;
    bool isCounting = 0;
    short TimeCount = 0;
    MatchingType MatchType = None;

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