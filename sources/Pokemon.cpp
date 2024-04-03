#include "raylib.h"
#include "../headers/SceneManager.h"
#include <iostream>

void init(SceneManager& scene) {
    scene.MenuScreen.setup();
    scene.LevelScreen.setup();
}

int main() {
    bool isSigned = 0;
    Scene status = MENU;
    GameStatus GameState = ChooseLevel;
    Level level;

    //Init Window
    InitWindow (WinWdith, WinHeight, GameName);
    SetTargetFPS(GameFPS);

    //Create icon
    Image icon = LoadImage("resources/img/logo.png");
    SetWindowIcon (icon);

    SceneManager scene;
    init(scene);

    while (!WindowShouldClose()) {
        BeginDrawing();
        std::cout << GetFPS() << std::endl;

        switch (status) {
        case EXIT: {
            CloseWindow();
            UnloadImage(icon);
            UnloadFont(GameFont);
            return 0;
            break;
        }

        case PLAY:
            scene.GameScreen.draw(GameState, status, level, scene.LevelScreen);
            break;
        
        default:
            status = scene.MenuScreen.draw(isSigned);
            break;
        }
        
        EndDrawing();
    }
    


    return 0;
}