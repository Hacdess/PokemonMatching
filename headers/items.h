#pragma once // include once to prevent from struct redefinition
#include "raylib.h"
#include <cstring>
#include <string>
#include <iostream>
#include "stdlib.h"
#include "time.h"

using namespace std;

const char GameName[] = "Pokemon Matching";

//Define GameFPS
#define GameFPS 60

//Define Game Font
const Font GameFont = GetFontDefault();

//Define Window size
#define WinWdith 1920
#define WinHeight 1080

//Define colors
#define DarkCyanTrans (Color)  {0, 190, 190, 150}
#define DarkCyan (Color) {0, 190, 190, 255}
#define MoreDarkCyan (Color) {0, 125, 125, 0}
#define BlackTrans (Color) {0, 0, 0, 100}
#define SlightGray (Color) {204, 204, 204, 255}

//Game Level
enum Scene {MENU, SIGNUP, SIGNIN, PLAY, SETTING, RANK, EXIT};
enum Level {EASY, MEDIUM, HARD, BACK};

//Structs
struct TextBox {
    char* content;
    float FontSize;
    Color FontColor;
    Color BorderColor;
    float ContentLength;
    Vector2 pos; //position of words
    Rectangle border;
};

struct Selector1D {
    short int x;
};

struct Selector2D {
    short int x, y;
};

//Functions
void DeallocateButtons1D (TextBox* buttons, const int& size);
void DeallocateButtons2D (TextBox** buttons, const int& rows, const int& col);
bool isSameColor (const Color& Color1, const Color& Color2);