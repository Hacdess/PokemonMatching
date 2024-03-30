#pragma once // include once to prevent from struct redefinition
#include "raylib.h"
#include <cstring>
#include <string>

const char GameName[] = "Pokemon Matching";

//define GameFPS
#define GameFPS 60

//define Game Font
#define GameFont (Font) LoadFont ("resources/font/alpha_beta.png")

//Define numbers
#define WinWdith 1920
#define WinHeight 1080

//define colors
#define ButtonsColor (Color)  {0, 190, 190, 150}

//Structs
struct Button {
    Vector2 pos; //position of words
    Rectangle border;
    Color FontColor;
    Color BorderColor;
    char* content;
    Vector2 SizeContent;
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
void DeallocateButtons1D (Button* buttons, const int& size);
void DeallocateButtons2D (Button** buttons, const int& rows, const int& col);