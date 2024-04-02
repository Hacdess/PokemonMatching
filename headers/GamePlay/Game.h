#pragma once
#include "../Moving.h"
#include "Level.h"
#include "../SceneManager.h"

enum GameStatus {ChooseLevel, LoadGame, PlayGame};

struct Pokemon {
    unsigned short int ID;
    Texture2D img;
    Color cover;
    Vector2 pos;
    float size;
};

struct GameBoard {
    Texture2D HiddenBackground, *PokemonsImg;
    Rectangle border; //Viền
    Color BorderColor;
    unsigned short int row, col;
    Pokemon** pokemons;

    Texture2D* readImage(const unsigned short int& quantity);   
    void suffle();
    Pokemon **createTable(const unsigned short& row, const unsigned short& col, Texture2D* texture, const unsigned short& quantity);
};

struct GameScene {
    Texture2D background;
    GameBoard gameboard;
    Selector2D selector = {1,1};


    void setup();
    void draw(GameStatus& action, SceneManager scene);
};