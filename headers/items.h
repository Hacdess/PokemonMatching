#pragma once // include once to prevent from struct redefinition
#include "raylib.h"

const char GameName[] = "Pokemon Matching";

//define GameFPS
#define GameFPS 60

//Define numbers
#define WinWdith 1920
#define WinHeight 1080

//define colors
#define ButtonsColor (Color)  {0, 190, 190, 150}

//Structs
struct Button {
    Vector2 pos;
    Rectangle border;
    Color FontColor;
    Color BorderColor;
    char* content;
    Vector2 SizeContent;
};

struct Selctor1D {
    int x;
};

struct Selector2D {
    int x, y;
};