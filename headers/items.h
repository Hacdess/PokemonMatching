#pragma once // include once to prevent from struct redefinition
#include "raylib.h"

#define ButtonsColor (Color)  {0, 190, 190, 150};
const char GameName[] = "Pokemon Matching";
#define GameFPS 60

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