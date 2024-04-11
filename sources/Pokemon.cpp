#include "raylib.h"
#include "../headers/SceneManager.h"
#include <iostream>

void init(SceneManager& game) {
    game.MenuScreen.setup();
    game.LevelScreen.setup();
    game.GameScreen.gameboard.PokemonsImg = readImage(50);
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


            case SIGNUP:
                if (!game.SignUpScreen.set)
                    game.SignUpScreen.setup();
                else {
                    scene = game.SignUpScreen.draw (isSigned, game.MenuScreen.username);
                    if (!game.SignUpScreen.set) {
                        //Refresh for the next Sign Up
                        DeallocateTextbox1D (game.SignUpScreen.title, 2);
                        DeallocateTextbox1D (game.SignUpScreen.constant, 2);
                        DeallocateTextbox1D (game.SignUpScreen.input, 2);
                        DeallocateTextbox1D (game.SignUpScreen.confirm, 2);
                        delete[] game.SignUpScreen.command.content;
                        scene = MENU;
                    }
                }
                break;

            case SIGNIN:
                if (!game.SignInScreen.set)
                    game.SignInScreen.setup();
                else {
                    scene = game.SignInScreen.draw (isSigned, game.MenuScreen.username);
                    if (!game.SignInScreen.set) {
                        //Refresh for the next Sign Up
                        DeallocateTextbox1D (game.SignInScreen.title, 2);
                        DeallocateTextbox1D (game.SignInScreen.constant, 2);
                        DeallocateTextbox1D (game.SignInScreen.input, 2);
                        DeallocateTextbox1D (game.SignInScreen.confirm, 2);
                        delete[] game.SignInScreen.command.content;
                        scene = MENU;
                    }
                }
                break;

            case PLAY:
                scene = game.GameScreen.draw(action, scene, level, game.LevelScreen, game.MenuScreen.username);
                break;

            case RANK:
                if (!game.LeaderboardScreen.isSet)
                    game.LeaderboardScreen.setup();
                scene = game.LeaderboardScreen.draw();
                break;
            
            //Exit the game
            default:
                CloseWindow();
                UnloadImage(icon);
                UnloadFont(GameFont);
                
                //deadllocate
                short i;
                for (i = 0; i < 50; i ++)
                    UnloadTexture (game.GameScreen.gameboard.PokemonsImg[i]);
                delete[] game.GameScreen.gameboard.PokemonsImg;
                return 0;
        }
        
        EndDrawing();
    }
    

    return 0;
}