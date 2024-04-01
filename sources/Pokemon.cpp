#include "raylib.h"
#include "../headers/MenuScreen/Menu.h"
#include <iostream>

void init(MenuScene& MenuScreen) {
    MenuScreen.setup();
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

    MenuScene MenuScreen;
    init(MenuScreen);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground (BLACK);

        switch (status) {
        case EXIT: {
            std::cout << "bye\n";
            CloseWindow();
            UnloadImage(icon);
            UnloadFont(GameFont);
            return 0;
            break;
        }
        
        default:
            std::cout << "hi\n";
            status = MenuScreen.draw(isSigned);
            break;
        }

        EndDrawing();
    }
    


    return 0;
}