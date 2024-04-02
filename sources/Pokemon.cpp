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

    //Init Window
    InitWindow (WinWdith, WinHeight, GameName);
    ToggleFullscreen();
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
        
        default:
            status = scene.MenuScreen.draw(isSigned);
            break;
        }
        //scene.LevelScreen.draw();    

        EndDrawing();
    }
    


    return 0;
}