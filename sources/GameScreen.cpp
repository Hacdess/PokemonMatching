#include "../headers/GamePlay/GameScreen.h"


void DrawGameScreen (const int& WindowWidth, const int& WindowHeight, bool& exit, const Texture2D& BackgroundPic, bool& isSigned) {
    while (!exit) {
        //DrawBackground image
        DrawTexturePro (BackgroundPic, {0, 0, 1792.0f, 1024.0f}, {0, 0, float(WindowWidth), float(WindowHeight)}, {0, 0}, 0.0f, WHITE);
        ClearBackground (BLACK);

        exit ^= 1;
    }



}