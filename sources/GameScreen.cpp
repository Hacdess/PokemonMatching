#include "../headers/GamePlay/GameScreen.h"

void DrawGameScreen (const int& WindowWidth, const int& WindowHeight, Color ColorBackground) {
    InitWindow(WindowWidth, WindowHeight, GameName);
    SetTargetFPS (GameFPS);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground (BLACK);

        EndDrawing();
    }

}