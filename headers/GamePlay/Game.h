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

//Load images from folder to get the backgrounds, then turn them into textures
Texture2D* readImageBackground (const short int& quantity);
//Load images from folder to get pokemons images, then turn them into textures
Texture2D* readImagePokemon (const short int& quantity);
//Load images from folder to get hidden backgrounds of the gameboard, then turn them into textures
Texture2D* readImageHidden(const short int& quantity);
void shuffle1D(Pokemon* Po1D, const short& size);

struct GameBoard {
    float width, height;
    Texture2D HiddenBackground, *PokemonsImg, *Hiddens;

    short row, col;
    Pokemon** pokemons;
    Selector2D selector, selected, player2, selected2;

    Node *path = NULL, *path2 = NULL;
    float MatchingTime = 0, MatchingTime2 = 0;
    MatchingType MatchType = None, MatchType2 = None;
    Selector2D checkMatch1, checkMatch2;
    Selector2D hint1_1, hint1_2, hint2_1, hint2_2;

    void createTable (const short& quantity);
    bool isEmpty();
    bool checkMatchAble();
    void draw(const bool& isDual);
};

struct GameScene {
    Texture2D background, *backgrounds;
    GameBoard gameboard;
    ScoreBoard scoreboard;
    ResultScene ResultScreen;

    float EndTime;

    void setup();
    Scene draw(GameAction& action, bool& isDual, Level& level, GameModeScene& GameModeScreen, LevelScene& LevelScreen, const char* username);
};