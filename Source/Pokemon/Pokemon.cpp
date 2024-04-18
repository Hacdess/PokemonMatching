#include "../headers/SceneManager.h"
#include "../headers/Music.h"
#include <iostream>

//Init some features that can be reused many times
//This makes it slow at the beginning but faster when enjoying the game
void init(SceneManager& game) {
    game.MenuScreen.setup();
    game.GameModeScreen.setup();
    game.LevelScreen.setup();
    game.GuideScreen.setup();
    game.GameScreen.backgrounds = readImageBackground(11);
    game.GameScreen.gameboard.PokemonsImg = readImagePokemon(50);
    game.GameScreen.gameboard.Hiddens = readImageHidden(6);
}

int main() {
    //Some special variables for setting up the game
    bool isSigned = 0;                  //At first, the user has not signed in yet
    Scene scene = MENU;                 //The game starts with the menu
    GameAction action = ChooseGameMode; //When it comes to GameScene, the first thing to do is to choose the game mode: single or dual
    bool isDual;                        //This bool-type variable is to let the game know if the user is choosing single or dual mode
    Level level;                        //This is for choosing the level to play

    //Init Window and set the fps target to 60
    InitWindow (WinWdith, WinHeight, GameName);
    ToggleFullscreen();
    SetTargetFPS(GameFPS);

    //Create game's icon
    Image icon = LoadImage("Source/img/logo.png");
    SetWindowIcon (icon);

    //Create a scene manager to manage the game scenes
    SceneManager game;
    init(game); //Init some features that can be reused many times

    //Add sound
    gameMusic musicAndSound;
    musicAndSound.initMusicAndSound();
    float timePlayed = 0.0f;                   //The variable is used to update the music stream after being paused
    PlayMusicStream(musicAndSound.themeMusic); //Start playing the background music

    //The loop to draw the Game
    while (!WindowShouldClose()) {
        musicAndSound.updateMusicStream(musicAndSound.themeMusic, timePlayed);
        cout << GetFPS() << endl;   //print the game FPS for checking
        BeginDrawing();             //Start drawing here

        //Check the scene variable to manage the game
        switch (scene) {
            case MENU:
                scene = game.MenuScreen.draw(isSigned, musicAndSound);
                break;

            case GUIDE:
                //Setup the Guide screen before drawing
                if (!game.GuideScreen.set)
                    game.GuideScreen.setup();
                else
                    scene = game.GuideScreen.draw (musicAndSound);
                break;

            case SIGNUP:
                //Setup the Sign Up screen before drawing
                if (!game.SignUpScreen.set)
                    game.SignUpScreen.setup();
                else {
                    scene = game.SignUpScreen.draw (isSigned, game.MenuScreen.username, musicAndSound);
                    //After ending Signing Up, the bool variabl "set" to check if set or not turns to 0, the deallocate some dynamic variables.
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
                //Setup the Sign In screen before drawing
                if (!game.SignInScreen.set)
                    game.SignInScreen.setup();
                else {
                    scene = game.SignInScreen.draw (isSigned, game.MenuScreen.username, musicAndSound);
                    //After ending Signing In, the bool variabl "set" to check if set or not turns to 0, the deallocate some dynamic variables.
                    if (!game.SignInScreen.set) {
                        //Refresh for the next Sign In
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
                //Setup the Leader Board screen before drawing
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