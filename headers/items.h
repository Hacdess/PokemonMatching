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
#define SlightGrayTrans (Color) {204, 204, 204, 150}
#define PokeBack (Color) {255, 205, 230, 255};

//Game Level
enum Scene {MENU, SIGNUP, SIGNIN, PLAY, SETTING, RANK, EXIT};
enum Level {EASY, MEDIUM, HARD, NOT_CHOSE};
enum GameAction {ChooseLevel, LoadGame, PlayGame, End};
enum MatchingType {None, I, L, U, Z};

//General Structs
struct TextBox {
    char* content;
    float FontSize;
    Color FontColor;
    Color BorderColor;
    float ContentLength;
    Vector2 pos; //position of words
    Rectangle border;
};

struct Selector2D {
    short x, y;
};

struct Time {
    short hour, min, sec;
    void formatTime();
};

//Functions
void DeallocateButtons1D (TextBox* buttons, const short& size);
void DeallocateButtons2D (TextBox** buttons, const short& rows, const short& col);
bool isSameColor (const Color& Color1, const Color& Color2);