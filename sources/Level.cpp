#include "../headers/GamePlay/Level.h"

void LevelScene::setup() {
    //Background color
    count = 0;
    background = MoreDarkCyan;

    //Title Textbox
    TextBoxs[0].content = new char [strlen("CHOOSE YOUR CHALLENGE") + 1];
    strcpy (TextBoxs[0].content, "CHOOSE YOUR CHALLENGE");
    TextBoxs[0].FontColor = YELLOW;
    TextBoxs[0].FontSize = float(WinHeight) / 10;
    TextBoxs[0].ContentLength = float(MeasureText ("CHOOSE YOUR CHALLENGE", TextBoxs[0].FontSize));
    TextBoxs[0].pos = {(float(WinWdith) - TextBoxs[0].ContentLength) / 2, float(WinHeight) / 4};

    //Choose Level Textboxs
    TextBoxs[1].content = new char [strlen("EASY GAME") + 1];
    strcpy (TextBoxs[1].content, "EASY GAME");

    TextBoxs[2].content = new char [strlen("MEDIUM RARE") + 1];
    strcpy (TextBoxs[2].content, "MEDIUM RARE");

    TextBoxs[3].content = new char [strlen("HARDCORE") + 1];
    strcpy (TextBoxs[3].content, "HARDCORE");

    TextBoxs[4].content = new char [strlen("BACK TO MENU") + 1];
    strcpy (TextBoxs[4].content, "BACK TO MENU");

    float   startY = float(WinHeight) / 2,
            height = TextBoxs[0].FontSize,
            FontSize = float(WinWdith) / 25,
            spacing = FontSize / 5;

    unsigned int i;
    for (i = 1; i < 5; i ++) {
        TextBoxs[i].FontColor = BLACK;
        TextBoxs[i].BorderColor = SlightGray;
        TextBoxs[i].FontSize = FontSize;
        TextBoxs[i].ContentLength = float(MeasureText (TextBoxs[i].content, TextBoxs[i].FontSize));
        TextBoxs[i].border = {float(WinWdith)  / 4, startY, float(WinWdith) / 2, height};
        TextBoxs[i].pos = {(float(WinWdith) - TextBoxs[i].ContentLength) / 2, TextBoxs[i].border.y + (height - TextBoxs[i].FontSize) / 2};
        
        startY = startY + height + spacing;
    }

    selector = 1;
}

Level LevelScene::draw(GameAction& action) {
    ClearBackground(background);

    std::cout << count << endl;
    count ++;
    std::cout << count << endl;
    if (count == GameFPS / 2) {
        if (isSameColor(TextBoxs[0].FontColor, YELLOW))
            TextBoxs[0].FontColor = RED;
        else
            TextBoxs[0].FontColor = YELLOW;

        count = 0;
    }

    moveSelector1D (selector, 1, 4);

    unsigned short int i;
    for (i = 0; i < 5; i ++) {
        if (i != 0) {
            if (selector == i) {
                TextBoxs[i].BorderColor = WHITE;
                TextBoxs[i].FontColor = DarkCyanTrans;
            }

            else {
                TextBoxs[i].BorderColor = SlightGray;
                TextBoxs[i].FontColor = BLACK;
            }

            DrawRectangleRec (TextBoxs[i].border, TextBoxs[i].BorderColor);
        }
        DrawText (TextBoxs[i].content, TextBoxs[i].pos.x, TextBoxs[i].pos.y, TextBoxs[i].FontSize, TextBoxs[i].FontColor);
    }

    if (IsKeyPressed(KEY_ENTER)) {
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
            action = End; 
        }
    }
    return NOT_CHOSE;
}
