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
#define WinWdith 1920
#define WinHeight 1080

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
    char* content;       //Word that the textbox contains
    float FontSize;      //The height of the words
    Color FontColor;     //Color of the words
    Color BorderColor;   //Color of the textbox
    float ContentLength; // length of the words
    Vector2 pos;         //position of words
    Rectangle border;    //The coordinates of four important points to draw the rectangle
};

struct Selector2D {
    short x, y;          //The position of the cursor in 2-dimension arrray
};

struct Time {
    short hour, min, sec; //The time
    void formatTime();    //Format the time like normal (Example: 10:04:09 means 10 hours 4 minutes 9 seconds)
};

//Functions
void DeallocateTextbox1D (TextBox* textbox, const short& size);     //Deallocate the Text box

bool isSameColor (const Color& Color1, const Color& Color2);        //Check whether two colors are the same
void addText (char*& dest, const char* content);                    //Add text to the dynamic variable
void updateText (char*& dest, const char* content);                 //Adjust text
char* StoA (const string& s);                                       //Convert string to dynamicchar array
string TimeToString (Time time);                                    //Cobert time to string
short compareTime (const Time& time1, const Time& time2);           //A function to comapre the time