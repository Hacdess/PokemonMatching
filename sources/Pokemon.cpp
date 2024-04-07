#include "raylib.h"
#include "../headers/SceneManager.h"
#include <iostream>
#include<cstring>
#include<fstream>
#include<sstream>
using namespace std;
#define MAX_INPUT_CHARS 21

void init(SceneManager &game)
{
    game.MenuScreen.setup();
    game.LevelScreen.setup();
    game.AccountScreen.setupSignUp();
    game.AccountScreen.setupSignIn();
}

int main()
{
    bool isSigned = 0;

    // Init Window
    InitWindow(WinWdith, WinHeight, GameName);
    SetTargetFPS(GameFPS);

    // Create icon
    Image icon = LoadImage("resources/img/logo.png");
    SetWindowIcon(icon);

    SceneManager game;
    init(game);
    Account a;
    
    while (!WindowShouldClose())
    {
        BeginDrawing();

        game.AccountScreen.drawSignIn(isSigned, a);

        EndDrawing();
    }
}
