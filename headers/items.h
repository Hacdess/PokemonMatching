#pragma once // include once to prevent from struct redefinition
#include "raylib.h"
#include <cstring>
#include <string>
#include <iostream>
#include "stdlib.h"
#include "time.h"
#include <fstream>
#include <sstream>

using namespace std;

//Game Name
const char GameName[] = "Pokemon Matching";

//Define GameFPS
#define GameFPS 60

//Define Game Font
const Font GameFont = GetFontDefault();

//Define Window size
#define WinWdith 2560
#define WinHeight 1440

//Define colors
#define CYAN (Color)  {0, 255, 255, 255}
#define DarkCyanTrans (Color)  {0, 190, 190, 150}
#define DarkCyan (Color) {0, 180, 180, 255}
#define MoreDarkCyan (Color) {0, 125, 125, 0}
#define BlackTrans (Color) {0, 0, 0, 100}
#define SlightGray (Color) {204, 204, 204, 255}
#define SlightGrayTrans (Color) {204, 204, 204, 150}
#define PokeBack (Color) {255, 205, 230, 255}

//Game Level
enum Scene {MENU, SIGNUP, SIGNIN, PLAY, GUIDE, RANK, EXIT};
enum Level {EASY, MEDIUM, HARD, NOT_CHOSE_LEVEL};
enum GameAction {ChooseGameMode,ChooseLevel, LoadGame, PlayGame, ShowResult, End};
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
void DeallocateTextbox1D (TextBox* textbox, const short& size);
void DeallocateDynamicTextbox1D (TextBox* textbox, const short& size);
void DeallocateDynamicTextbox2D (TextBox** textbox, const short & row, const short& col);
bool isSameColor (const Color& Color1, const Color& Color2);
void addText (char*& dest, const char* content);
void updateText (char*& dest, const char* content);
char* StoA (const string& s);
string TimeToString (Time time);
short compareTime (const Time& time1, const Time& time2);