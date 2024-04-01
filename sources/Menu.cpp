#include "../headers/MenuScreen/Menu.h"

void MenuScene::setup() {
    //Get Back
    Image img = LoadImage("resources/img/background/background.png");
    background = LoadTextureFromImage(img);
    UnloadImage(img);

    //Store Title
    title[0].content = new char [strlen("POKEMON") + 1];
    title[0].FontColor = RED;
    strcpy(title[0].content, "POKEMON");
    title[1].content = new char [strlen("MATCHING") + 1];
    title[1].FontColor = YELLOW;
    strcpy(title[1].content, "MATCHING");

    unsigned int i, j;
    float   startY = float(WinHeight) / 4,
            startX = float(WinWdith) / 5,
            FontSize = float(WinHeight) / 8,
            spacing = FontSize / 5;
    
    for (int i = 0; i < 2; i ++) {
        title[i].FontSize = FontSize;
        title[i].spacing = spacing;
        title[i].BorderColor = BlackTrans;

        title[i].ContentSize = MeasureTextEx(GameFont, title[i].content, title[i].FontSize, title[i].spacing);
        title[i].pos = {(float(WinWdith) - title[i].ContentSize.x) / 2, startY};
        title[i].border = {startX, startY - spacing, startX * 3, title[i].ContentSize.y + spacing * 1.5f};

        startY = startY + title[i].ContentSize.y + spacing * 1.5f;
    }

    //Buttons
    buttons[0][0].content = new char[strlen("Sign up") + 1];
    strcpy(buttons[0][0].content, "Sign up");

    buttons[0][1].content = new char[strlen("Play Game") + 1];
    strcpy(buttons[0][1].content, "Play Game");

    buttons[0][2].content = new char[strlen("Setting") + 1];
    strcpy(buttons[0][2].content, "Setting");

    buttons[1][0].content = new char[strlen("Sign in") + 1];
    strcpy(buttons[1][0].content, "Sign in");

    buttons[1][1].content = new char[strlen("Leader Board") + 1];
    strcpy(buttons[1][1].content, "Leader Board");

    buttons[1][2].content = new char[strlen("Exit") + 1];
    strcpy(buttons[1][2].content, "Exit");

    startY = startY + title[1].ContentSize.y,
    startX = 0,
    FontSize = float(WinHeight) / 20,
    spacing = FontSize / 5;
    float   ButtonSpace = float (WinWdith) / 3,
            ButtonWidth =  ButtonSpace - 4.0f * spacing,
            ButtonHeight = float(WinHeight) / 10;

    //Get buttons' parameter
    for (j = 0; j < 3; j ++)
        for (i = 0; i < 2; i ++) {
            buttons[i][j].FontSize = FontSize;
            buttons[i][j].spacing = spacing;
            buttons[i][j].BorderColor = ButtonsColor;
            buttons[i][j].FontColor = WHITE;

            buttons[i][j].ContentSize = MeasureTextEx(GameFont, buttons[i][j].content, buttons[i][j].FontSize, buttons[i][j].spacing);
            buttons[i][j].border = {startX + spacing * 2.0f, startY, ButtonWidth, ButtonHeight};
            buttons[i][j].pos = {startX + (ButtonSpace - buttons[i][j].ContentSize.x) / 2, startY + (ButtonHeight - buttons[i][j].ContentSize.y) / 2};
            
            if (i == 1) {
                buttons[i][j].border.y = buttons[i][j].border.y + ButtonHeight + spacing;
                buttons[i][j].pos.y = buttons[i][j].pos.y + ButtonHeight + spacing;
                startX += ButtonSpace;
            }
        }
}

void updateStatus(bool& isSigned, char*& content1, char*& content2) {
    //Not Signed to Signed
    if (!isSigned) {
        delete[] content1;
        content1 = NULL;
        content1 = new char [strlen("Account") + 1];
        strcpy(content1, "Account");

        delete[] content2;
        content2 = NULL;
        content2 = new char [strlen("Sign out") + 1];
        strcpy(content2, "Sign out");
    }

    //Signed to Signed out
    else {
        delete[] content1;
        content1 = NULL;
        content1 = new char [strlen("Sign up") + 1];
        strcpy (content1, "Sign up");

        delete[] content2;
        content2 = NULL;
        content2 = new char [strlen("Sign in") + 1];
        strcpy (content2, "Sign in");
    }

    isSigned = 1 - isSigned;
}

Status MenuScene::draw(bool& isSigned) {
    //Draw Background image
    DrawTexturePro (background, {0, 0, 1792.0f, 1024.0f}, {0, 0, float(WinWdith), float(WinHeight)}, {0, 0}, 0.0f, WHITE);

    unsigned int i, j;

    //Draw Game Title
    for (i = 0; i < 2; i ++) {
        DrawRectangleRec (title[i].border, title[i].BorderColor);
        DrawTextEx (GameFont, title[i].content, title[i].pos, title[i].FontSize, title[i].spacing, title[i].FontColor);
    }

        if (IsKeyPressed (KEY_ENTER)) {
            //Column: Sign up / Sign in / Sign out / Account
            if (selector.x == 0) {
                if (!(selector.y == 0 && isSigned)) {
                    updateStatus (isSigned, buttons[0][0].content, buttons[1][0].content);

                    for (i = 0; i < 2; i ++) {
                        buttons[i][0].ContentSize = MeasureTextEx (GameFont, buttons[i][0].content, buttons[i][0].FontSize, buttons[i][0].spacing);
                        buttons[i][0].pos.x = (float(WinWdith) / 3 - buttons[i][0].ContentSize.x) / 2;
                    }
                }

                if (!isSigned ) {
                    
                }

                else {
                    
                }

            }

            //Column: PlayGame and LeaderBoard
            if (selector.x == 1) {

            }

            //Column: Setting and Exit
            if (selector.x == 2) {
                if (selector.y == 0) {

                }
                if (selector.y == 1) {
                    UnloadTexture (background);
                    return EXIT;
                }
            }
        }

    //Handlde Selector
    moveSelector2D (selector);
    if (selector.x < 0) selector.x = 2;
    if (selector.x > 2) selector.x = 0;
    if (selector.y < 0) selector.y = 1;
    if (selector.y > 1) selector.y = 0;

    //Draw Buttons
    for (i = 0; i < 2; i ++)
        for (j = 0; j < 3; j ++) {
        //check which button does selector choose, it's okay to compare as below
        if (selector.x == j && selector.y == i) {
            buttons[i][j].BorderColor = WHITE;
            buttons[i][j].FontColor = ButtonsColor;
        }

        else if (!(selector.x == j && selector.y == i)){
            buttons[i][j].BorderColor = ButtonsColor;
            buttons[i][j].FontColor = WHITE;
        }

        DrawRectangleRec (buttons[i][j].border, buttons[i][j].BorderColor);
        DrawTextEx (GameFont, buttons[i][j].content, buttons[i][j].pos, buttons[i][j].FontSize, buttons[i][j].spacing, buttons[i][j].FontColor);
        }

    return MENU;
}