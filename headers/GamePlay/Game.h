#pragma once
#include "../Moving.h"
#include "Level.h"
#include "Path.h"
#include "Scoreboard.h"
#include "Result.h"

struct Pokemon {
    bool shown = 0, selected = 0;
    short int ID;
    Rectangle border;
    Texture2D img;
    Color cover;
    Color back;
    Vector2 pos;
    float size;
    void draw();
    void unSeen();
};

Texture2D* readImage(const short int& quantity);
void shuffle1D(Pokemon* Po1D, const short& size);

struct GameBoard {
    float width, height;
    Texture2D HiddenBackground, *PokemonsImg;

    short row, col;
    Pokemon** pokemons;
    Selector2D selector = {1,1}, selected = {0, 0};

    Node* path = NULL;
    float MatchingTime = 0;
    MatchingType MatchType = None;
    Selector2D checkMatch1, checkMatch2;

    void createTable (const short& quantity);
    bool isEmpty();
    bool checkMatchAble();
    void draw();
};

struct GameScene {
    Texture2D background;
    GameBoard gameboard;
    ScoreBoard scoreboard;
    ResultScene ResultScreen;

    void setup();
    Scene draw(GameAction& action, Scene scene, Level& level, LevelScene& LEVEL, const char* username);
};