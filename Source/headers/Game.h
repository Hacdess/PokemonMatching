#pragma once
#include "Moving.h"
#include "Level.h"
#include "Path.h"
#include "Scoreboard.h"
#include "Result.h"
#include "Music.h"

struct Pokemon {
    bool shown = 0, selected = 0;           //Check if the Pokemon is shown, is selected or not
    short ID;                       //The ID for matching
    Rectangle border;               //Border of the Pokemon cell
    Texture2D img;                  //Pokemon image
    Color cover;                    //The color covering Pokemon
    Color back;                     //The background color of the cell
    Vector2 pos;                    //Position of Pokemon
    float size;                     //Size of the Pokemon
    void draw();                    //Draw the Pokemon
    void unSeen();                  //Turn bool shwon to 0 == delete the Pokemon
};

//Load images from folder to get the backgrounds, then turn them into textures
Texture2D* readImageBackground (const short int& quantity);
//Load images from folder to get Pokemons images, then turn them into textures
Texture2D* readImagePokemon (const short int& quantity);
//Load images from folder to get hidden backgrounds of the gameboard, then turn them into textures
Texture2D* readImageHidden(const short int& quantity);
void shuffle1D(Pokemon* Po1D, const short& size);

struct GameBoard {
    float width, height;                                //Width and height of the gameboard
    Texture2D HiddenBackground, *PokemonsImg, *Hiddens; //The hidden background, the dynamic Texture 2D arrays contain 
                                                        //Pokemons images and hidden backgrounds of the gameboard
    short row, col;                                     //Number of rows and columns of the game board
    Pokemon** pokemons;                                 //Dynamic 2D Pokemons array
    Selector2D selector, selected, player2, selected2;  //Selectors of 2 players

    Node *path = NULL, *path2 = NULL;                   //Paths of 2 players to draw
    float MatchingTime = 0, MatchingTime2 = 0;          //Mark the matching time to calculate and delay time
    MatchingType MatchType = None, MatchType2 = None;   //The matching type of 2 players
    Selector2D checkMatch1, checkMatch2;                //Selectors which are used for checking matching
    Selector2D hint1_1, hint1_2, hint2_1, hint2_2;      //Selectors which are used for making hint

    void createTable (const short& quantity);           //Setup the game board
    bool isEmpty();                                     //Check if the game board is empty to end the game
    bool checkMatchAble();                              //Check if it is still matchable, if it is not, shuffle
    void draw(const bool& isDual);                      //Draw the game board
};

struct GameScene {
    Texture2D background, *backgrounds; //Background and dynamic array of backgrounds
    GameBoard gameboard;                //Game board on the left
    ScoreBoard scoreboard;              //Scoreboard on the right
    ResultScene ResultScreen;           //The result screen for game ending

    float EndTime;  //After clearing the game board, delay time for 0.5s then turn to Result screen
                    //That is why we need the float variable EndTime
    void setup();   //Set up the game
    //Draw the game
    Scene draw(GameAction& action, bool& isDual, Level& level, GameModeScene& GameModeScreen, LevelScene& LevelScreen, const char* username, gameMusic& musicAndSound);
};