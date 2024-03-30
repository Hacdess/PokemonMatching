#include "../headers/GamePlay/GameScreen.h"

Level ChooseLevel () {
    //Rectangle Show the word choose Level
    Rectangle ChooseLevelBox = {WinWdith / 3, WinHeight / 4, WinWdith / 3, WinHeight/ 4};
    float ChooseLevel_FontSize = WinHeight / 5;
    Vector2 SizeChooseLevel = MeasureTextEx (GameFont, "Choose Level", ChooseLevel_FontSize, ChooseLevel_FontSize / 5);
    Vector2 PosChooseLevel = {float(WinWdith) / 2 - SizeChooseLevel.x / 2, ChooseLevelBox.y + (ChooseLevelBox.height - SizeChooseLevel.y) / 2};


    //Buttons of Levels
    Button* levels = new Button[5];

    levels[0].content = new char[strlen("Easy") + 1];
    strcpy(levels[0].content, "Easy");
    levels[1].content = new char[strlen("Medium") + 1];
    strcpy(levels[1].content, "Medium");
    levels[2].content = new char[strlen("Hard") + 1];
    strcpy(levels[2].content, "Hard");
    levels[3].content = new char[strlen("Custom") + 1];
    strcpy(levels[3].content, "Custom");
    levels[4].content = new char[strlen("Back to Menu") + 1];
    strcpy(levels[4].content, "Back to Menu");

    //Allocate temp pointer variables
    float *HalfWinWidth = new float, 
            Level_FontSize = float(WinHeight) / 8, 
            Level_Spacing = Level_FontSize / 5,
            *LevelBoxHeight = new float;

    *HalfWinWidth = float(WinWdith) / 2,
    *LevelBoxHeight = float(WinHeight) / 7;

    Vector2* LevelBox_Pos = new Vector2;
    *LevelBox_Pos = {WinWdith / 3, float(WinHeight) / 2 + ChooseLevel_FontSize / 5};

    //Get level buttons' parameter
    unsigned int i;
    for (i = 0; i < 5; i ++) {
        levels[i].border = {LevelBox_Pos -> x, LevelBox_Pos -> y, LevelBox_Pos -> x, *LevelBoxHeight};
        levels[i].SizeContent = MeasureTextEx (GameFont, levels[i]. content, Level_FontSize, Level_Spacing);
        levels[i].pos = {LevelBox_Pos -> x, LevelBox_Pos -> y};
        levels[i].FontColor = ButtonsColor;
        levels[i].BorderColor = {137, 137, 137, 1};

        LevelBox_Pos -> y += *LevelBoxHeight;
    }

    //Deallocate temp pointer variables
    delete HalfWinWidth;  
    delete LevelBoxHeight;
    delete LevelBox_Pos;

    Selector1D selector;
    selector.x = 0;

    while (true) {
        ClearBackground (DARKBROWN);

        //Draw "Choose Level" Rectangle
        DrawRectangleRec (ChooseLevelBox, ButtonsColor);
        DrawTextEx (GameFont, "Choose Level", PosChooseLevel, ChooseLevel_FontSize, ChooseLevel_FontSize / 5, RED);

        moveSelector1D (selector);
        if (selector.x < 0)
            selector.x = 4;
        if (selector.x > 4)
            selector.x = 0;

        if (IsKeyDown (KEY_ENTER)) {
            if (selector.x == 4) {
                DeallocateButtons1D (levels, 5);
                return menu;
            }
        }

        //Draw Levels Selections
        for (int i = 0; i < 5; i ++) {
            if (i == selector.x) {
                levels[i].FontColor = BLACK;
                levels[i].BorderColor = WHITE;
            }

            DrawRectangleRec (levels[i].border, levels[i].BorderColor);
            DrawTextEx (GameFont, levels[i].content, levels[i].pos, Level_FontSize, Level_Spacing, levels[i].FontColor);
        }
    
    }

}

void DrawGameBoard(const int& WindowWidth, const int& WindowHeight) {

}

void DrawGameScreen (const int& WindowWidth, const int& WindowHeight, bool& exit, const Texture2D& BackgroundPic, bool& isSigned) {

    while (!exit) {
        //DrawBackground image
        DrawTexturePro (BackgroundPic, {0, 0, 1792.0f, 1024.0f}, {0, 0, float(WindowWidth), float(WindowHeight)}, {0, 0}, 0.0f, WHITE);
        
        ClearBackground (BLACK);


        Level level = ChooseLevel();
        if (level == menu)

        exit ^= 1;
    }



}