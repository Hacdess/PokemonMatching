#include "raylib.h"
#include "../headers/SceneManager.h"
#include <iostream>

void init(SceneManager& Scene) {
    Scene.MenuScreen.setup();
    Scene.LevelScreen.setup();
}

int main() {
    bool isSigned = 0;
    Status status = MENU;

    //Init Window
    InitWindow (WinWdith, WinHeight, GameName);
    SetTargetFPS(GameFPS);

    //Create icon
    Image icon = LoadImage("resources/img/logo.png");
    SetWindowIcon (icon);

    SceneManager Scene;
    init(Scene);

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
            status = Scene.MenuScreen.draw(isSigned);
            break;
        }
        //Scene.LevelScreen.draw();    

        EndDrawing();
    }
    


    return 0;
}