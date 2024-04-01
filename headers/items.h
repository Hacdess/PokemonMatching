#pragma once // include once to prevent from struct redefinition
#include "raylib.h"
#include <cstring>
#include <string>
#include <iostream>

const char GameName[] = "Pokemon Matching";

//Define GameFPS
#define GameFPS 60

//Define Game Font
#define GameFont (Font) LoadFont ("resources/font/alpha_beta.png")

//Define Window size
#define WinWdith 1920
#define WinHeight 1080

//Define colors
#define ButtonsColor (Color)  {0, 190, 190, 150}
#define BlackTrans (Color) {0, 0, 0, 100}

//Game Level
enum Status {MENU, SIGNUP, SIGNIN, PLAY, SETTING, RANK, EXIT};
enum Level {EASY, MEDIUM, HARD, CUSTOM};

//Structs
struct TextBox {
    char* content;
    float FontSize, spacing;
    Color FontColor;
    Color BorderColor;
    Vector2 ContentSize;
    Vector2 pos; //position of words
    Rectangle border;
};

struct Selector1D {
    int x;
};

struct Selector2D {
    int x, y;
};

struct Pokemon {
    unsigned int ID;
    Texture2D img;
    Rectangle border;
};

struct GameBoard {
    Texture2D HiddenBackground;
    Rectangle border;
    Color BorderColor;
};

//Functions
void DeallocateButtons1D (TextBox* buttons, const int& size);
void DeallocateButtons2D (TextBox** buttons, const int& rows, const int& col);