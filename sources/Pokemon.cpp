#include "../headers/SceneManager.h"
#include "../headers/GamePlay/Music.h"
#include <iostream>

void init(SceneManager& game) {
    game.MenuScreen.setup();
    game.GameModeScreen.setup();
    game.LevelScreen.setup();
    game.GuideScreen.setup();
    //Getting the backgrounds here makes it slow at the beginning but faster when starting playing
    game.GameScreen.backgrounds = readImageBackground(11);
    game.GameScreen.gameboard.PokemonsImg = readImagePokemon(50);
    game.GameScreen.gameboard.Hiddens = readImageHidden(6);
}

int main() {
    bool isSigned = 0;
    Scene scene = MENU;
    GameAction action = ChooseGameMode;
    bool isDual;
    Level level;

    //Init Window
    InitWindow (WinWdith, WinHeight, GameName);
    SetTargetFPS(GameFPS);

    //Create icon
    Image icon = LoadImage("resources/img/logo.png");
    SetWindowIcon (icon);

    SceneManager game;
    init(game);

    //Add sound
    gameMusic musicAndSound;
    musicAndSound.initMusicAndSound();
    float timePlayed = 0.0f;
    PlayMusicStream(musicAndSound.themeMusic);

    while (!WindowShouldClose()) {
        musicAndSound.updateMusicStream(musicAndSound.themeMusic, timePlayed);
        cout << GetFPS() << endl;
        BeginDrawing();

        switch (scene) {
            case MENU:
                scene = game.MenuScreen.draw(isSigned, musicAndSound);
                break;

            case GUIDE:
                if (!game.GuideScreen.set)
                    game.GuideScreen.setup();
                else
                    scene = game.GuideScreen.draw (musicAndSound);
                break;

            case SIGNUP:
                if (!game.SignUpScreen.set)
                    game.SignUpScreen.setup();
                else {
                    scene = game.SignUpScreen.draw (isSigned, game.MenuScreen.username, musicAndSound);
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
                    scene = game.SignInScreen.draw (isSigned, game.MenuScreen.username, musicAndSound);
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
                scene = game.GameScreen.draw (action, isDual, level, game.GameModeScreen, game.LevelScreen, game.MenuScreen.username, musicAndSound);
                break;

            case RANK:
                if (!game.LeaderboardScreen.isSet)
                    game.LeaderboardScreen.setup();
                scene = game.LeaderboardScreen.draw(musicAndSound);
                break;
            
            //Exit the game
            default:
                CloseWindow();

                musicAndSound.deleteMusicAndSound();
                UnloadImage(icon);
                UnloadFont(GameFont);
                UnloadTexture (game.GameScreen.background);
                UnloadTexture (game.GameScreen.gameboard.HiddenBackground);
                UnloadTexture (game.SignInScreen.background);
                UnloadTexture (game.SignUpScreen.background);

                //deadllocate
                short i;
                for (i = 0; i < 50; i ++)
                    UnloadTexture (game.GameScreen.gameboard.PokemonsImg[i]);
                delete[] game.GameScreen.gameboard.PokemonsImg;

                for (i = 0; i < 6; i ++)
                    UnloadTexture (game.GameScreen.gameboard.Hiddens[i]);
                delete[] game.GameScreen.gameboard.Hiddens;

                for (i = 0; i < 11; i ++)
                    UnloadTexture (game.GameScreen.backgrounds[i]);
                delete[] game.GameScreen.backgrounds;

                return 0;
        }
        
        EndDrawing();
    }
    

    return 0;
}