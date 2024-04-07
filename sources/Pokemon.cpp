#include "raylib.h"
#include "../headers/SceneManager.h"
#include <iostream>

void init(SceneManager& game) {
    game.MenuScreen.setup();
    game.LevelScreen.setup();
    game.GameScreen.gameboard.PokemonsImg = readImage(60);
}

int main() {
    bool isSigned = 0;
    Scene scene = MENU;
    GameAction action = ChooseLevel;
    Level level;

    //Init Window
    InitWindow (WinWdith, WinHeight, GameName);
    SetTargetFPS(GameFPS);

    //Create icon
    Image icon = LoadImage("resources/img/logo.png");
    SetWindowIcon (icon);

    SceneManager game;
    init(game);

    while (!WindowShouldClose()) {
        cout << GetFPS() << endl;
        BeginDrawing();

        switch (scene) {
            case MENU:
                scene = game.MenuScreen.draw(isSigned);
                break;

/*
            case SIGNUP:
                status = Scene.AccountScreen.draw(isSigned);
                break;
*/
            case PLAY:
                scene = game.GameScreen.draw(action, scene, level, game.LevelScreen);
                break;
            
            //Exit the game
            default:
                CloseWindow();
                UnloadImage(icon);
                UnloadFont(GameFont);
                
                //deadllocate
                delete[] game.GameScreen.gameboard.PokemonsImg;

                return 0;
        }
        
        EndDrawing();
    }
    


    return 0;
}