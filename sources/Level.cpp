#include "../headers/GamePlay/Level.h"

void GameModeScene::setup() {
    //Background color
    background = DarkCyan;

    //Title Textbox
    addText (TextBoxs[0].content, "CHOOSE GAMEMODE");

    TextBoxs[0].FontColor = YELLOW;
    TextBoxs[0].FontSize = float(WinHeight) / 10;
    TextBoxs[0].ContentLength = float(MeasureText ("CHOOSE GAMEMODE", TextBoxs[0].FontSize));
    TextBoxs[0].pos = {(float(WinWdith) - TextBoxs[0].ContentLength) / 2, float(WinHeight) / 4};

    //Choose Level Textboxs
    addText (TextBoxs[1].content, "SINGLE");
    addText (TextBoxs[2].content, "DUAL");
    addText (TextBoxs[3].content, "GO BACK");

    float   startY = float(WinHeight) / 2,
            height = TextBoxs[0].FontSize,
            FontSize = float(WinWdith) / 25,
            spacing = FontSize / 5;

    short i;
    for (i = 1; i < 4; i ++) {
        TextBoxs[i].FontColor = WHITE;
        TextBoxs[i].BorderColor = SlightGrayTrans;
        TextBoxs[i].FontSize = FontSize;
        TextBoxs[i].ContentLength = float(MeasureText (TextBoxs[i].content, TextBoxs[i].FontSize));
        TextBoxs[i].border = {float(WinWdith)  / 3, startY, float(WinWdith) / 3, height};
        TextBoxs[i].pos = {(float(WinWdith) - TextBoxs[i].ContentLength) / 2, TextBoxs[i].border.y + (height - TextBoxs[i].FontSize) / 2};
        
        startY = startY + height + spacing;
    }

    selector = 1;
    time = GetTime();
}

void LevelScene::setup() {
    //Background color
    background = DarkCyan;

    //Title Textbox
    addText (TextBoxs[0].content, "CHOOSE YOUR CHALLENGE");
    
    //TextBoxs[0].content = new char [strlen("CHOOSE YOUR CHALLENGE") + 1];
    //strcpy (TextBoxs[0].content, "CHOOSE YOUR CHALLENGE");
    TextBoxs[0].FontColor = YELLOW;
    TextBoxs[0].FontSize = float(WinHeight) / 10;
    TextBoxs[0].ContentLength = float(MeasureText ("CHOOSE YOUR CHALLENGE", TextBoxs[0].FontSize));
    TextBoxs[0].pos = {(float(WinWdith) - TextBoxs[0].ContentLength) / 2, float(WinHeight) / 4};

    //Choose Level Textboxs
    addText (TextBoxs[1].content, "EASY GAME");
    addText (TextBoxs[2].content, "MEDIUM RARE");
    addText (TextBoxs[3].content, "HARDCORE");
    addText (TextBoxs[4].content, "GO BACK");

    float   startY = float(WinHeight) / 2,
            height = TextBoxs[0].FontSize,
            FontSize = float(WinWdith) / 25,
            spacing = FontSize / 5;

    short i;
    for (i = 1; i < 5; i ++) {
        TextBoxs[i].FontColor = WHITE;
        TextBoxs[i].BorderColor = SlightGrayTrans;
        TextBoxs[i].FontSize = FontSize;
        TextBoxs[i].ContentLength = float(MeasureText (TextBoxs[i].content, TextBoxs[i].FontSize));
        TextBoxs[i].border = {float(WinWdith)  / 4, startY, float(WinWdith) / 2, height};
        TextBoxs[i].pos = {(float(WinWdith) - TextBoxs[i].ContentLength) / 2, TextBoxs[i].border.y + (height - TextBoxs[i].FontSize) / 2};
        
        startY = startY + height + spacing;
    }

    selector = 1;
    time = GetTime();
}

bool GameModeScene::draw(GameAction& action, gameMusic& musicAndSound) {
    ClearBackground(background);

    if (GetTime() - time > 0.5) {
        if (isSameColor(TextBoxs[0].FontColor, YELLOW))
            TextBoxs[0].FontColor = RED;
        else
            TextBoxs[0].FontColor = YELLOW;
        time = GetTime();
    }

    moveSelector1D (selector, 1, 3, musicAndSound);

    short i;
    for (i = 0; i < 4; i ++) {
        if (i != 0) {
            if (selector == i) {
                TextBoxs[i].BorderColor = WHITE;
                TextBoxs[i].FontColor = DarkCyanTrans;
            }

            else {
                TextBoxs[i].BorderColor = SlightGray;
                TextBoxs[i].FontColor = WHITE;
            }

            DrawRectangleRec (TextBoxs[i].border, TextBoxs[i].BorderColor);
        }
        DrawText (TextBoxs[i].content, TextBoxs[i].pos.x, TextBoxs[i].pos.y, TextBoxs[i].FontSize, TextBoxs[i].FontColor);
    }

    if (IsKeyPressed(KEY_ENTER)) {
        PlaySound(musicAndSound.pressButton);
        if (selector == 1) {
            action = ChooseLevel;
            selector = 1;
            return 0;
        }
        if (selector == 2) {
            action = ChooseLevel;
            selector = 1;
            return 1;
        }
        if (selector == 3) {
            action = End;
            selector = 1;
            return 0;
        }
    }

    return 0;
}


Level LevelScene::draw(GameAction& action, gameMusic& musicAndSound) {
    ClearBackground(background);

    if (GetTime() - time > 0.5) {
        if (isSameColor(TextBoxs[0].FontColor, YELLOW))
            TextBoxs[0].FontColor = RED;
        else
            TextBoxs[0].FontColor = YELLOW;
        time = GetTime();
    }

    moveSelector1D (selector, 1, 4, musicAndSound);

    short i;
    for (i = 0; i < 5; i ++) {
        if (i != 0) {
            if (selector == i) {
                TextBoxs[i].BorderColor = WHITE;
                TextBoxs[i].FontColor = DarkCyanTrans;
            }

            else {
                TextBoxs[i].BorderColor = SlightGray;
                TextBoxs[i].FontColor = WHITE;
            }

            DrawRectangleRec (TextBoxs[i].border, TextBoxs[i].BorderColor);
        }
        DrawText (TextBoxs[i].content, TextBoxs[i].pos.x, TextBoxs[i].pos.y, TextBoxs[i].FontSize, TextBoxs[i].FontColor);
    }

    if (IsKeyPressed(KEY_ENTER)) {
        PlaySound(musicAndSound.pressButton);
        if (selector == 1) {
            action = LoadGame;
            selector = 1;
            return EASY;
        }
        if (selector == 2) {
            action = LoadGame;
            selector = 1;
            return MEDIUM;
        }
        if (selector == 3) {
            action = LoadGame;
            selector = 1;
            return HARD;
        }
        if (selector == 4) {
            selector = 1;
            action = ChooseGameMode; 
        }
    }
    return NOT_CHOSE_LEVEL;
}