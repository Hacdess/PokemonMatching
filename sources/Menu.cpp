#include "../headers/MenuScreen/Menu.h"

void MenuScene::setup() {
    //Get Background
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

    unsigned short int i, j;
    float   startY = float(WinHeight) / 4,
            startX = float(WinWdith) / 5,
            FontSize = float(WinHeight) / 8,
            spacing = FontSize / 5;
    
    for (i = 0; i < 2; i ++) {
        title[i].FontSize = FontSize;
        title[i].BorderColor = BlackTrans;

        title[i].ContentLength = float(MeasureText(title[i].content, title[i].FontSize));
        title[i].pos = {(float(WinWdith) - title[i].ContentLength) / 2, startY};
        title[i].border = {startX, startY - spacing, startX * 3, title[i].FontSize + spacing * 1.5f};

        startY = startY + title[i].FontSize + spacing * 1.5f;
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

    startY = startY + title[1].FontSize,
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
            buttons[i][j].BorderColor = DarkCyanTrans;
            buttons[i][j].FontColor = WHITE;

            buttons[i][j].ContentLength = float(MeasureText(buttons[i][j].content, buttons[i][j].FontSize));
            buttons[i][j].border = {startX + spacing * 2.0f, startY, ButtonWidth, ButtonHeight};
            buttons[i][j].pos = {startX + (ButtonSpace - buttons[i][j].ContentLength) / 2, startY + (ButtonHeight - buttons[i][j].FontSize) / 2};
            
            if (i == 1) {
                buttons[i][j].border.y = buttons[i][j].border.y + ButtonHeight + spacing;
                buttons[i][j].pos.y = buttons[i][j].pos.y + ButtonHeight + spacing;
                startX += ButtonSpace;
            }
        }
}

//Signed or not
void updateStatus(bool& isSigned, char*& content1, char*& content2, const char* newContent) {
    //Not Signed to Signed
    if (!isSigned) {
        delete[] content1;
        content1 = NULL;
        content1 = new char [strlen(newContent) + 1];
        strcpy(content1, newContent);

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

Scene MenuScene::draw(bool& isSigned) {
    //Draw Background image
    ClearBackground (BLACK);
    DrawTexturePro (background, {0, 0, float(background.width), float(background.height)}, {0, 0, float(WinWdith), float(WinHeight)}, {0, 0}, 0.0f, WHITE);

    short i, j;

    //Draw Game Title
    for (i = 0; i < 2; i ++) {
        DrawRectangleRec (title[i].border, title[i].BorderColor);
        DrawText (title[i].content, title[i].pos.x, title[i].pos.y, title[i].FontSize, title[i].FontColor);
    }

        if (IsKeyPressed (KEY_ENTER)) {
            //Column: Sign up / Sign in / Sign out / Account
            if (selector.x == 0) {
                //When it is not signed, turn to Sign up or Sign in
                if (!isSigned) {
                    //Sign Up button
                    if (selector.y == 0) {
                        isChanged = 1;
                        return SIGNUP;
                    }
                    //Sign In button
                    isChanged = 1;
                    return MENU;
                }

                //If already signed, Sign out
                else if (selector.y == 1) {
                    isChanged = 1;
                    return MENU;
                }
            }

            //Column: PlayGame and LeaderBoard
            if (selector.x == 1) {
                if (selector.y == 0)
                    return PLAY;
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

    if (isChanged) {
        updateStatus (isSigned, buttons[0][0].content, buttons[1][0].content, account.name);
        for (i = 0; i < 2; i ++) {
            buttons[i][0].ContentLength = float(MeasureText(buttons[i][0].content, buttons[i][0].FontSize));
            buttons[i][0].pos.x = (float(WinWdith) / 3 - buttons[i][0].ContentLength) / 2;
        }
        isChanged = 0;
    }
    
    //Handlde Selector
    moveSelector2D (selector, 0, 0, 2, 1);

    //Draw Buttons
    for (i = 0; i < 2; i ++)
        for (j = 0; j < 3; j ++) {
        //check which button does selector choose, it's okay to compare as below
        if (selector.x == j && selector.y == i) {
            buttons[i][j].BorderColor = WHITE;
            buttons[i][j].FontColor = DarkCyanTrans;
        }

        else if (!(selector.x == j && selector.y == i)){
            buttons[i][j].BorderColor = DarkCyanTrans;
            buttons[i][j].FontColor = WHITE;
        }

        DrawRectangleRec (buttons[i][j].border, buttons[i][j].BorderColor);
        DrawText (buttons[i][j].content, buttons[i][j].pos.x, buttons[i][j].pos.y, buttons[i][j].FontSize, buttons[i][j].FontColor);
        }

    return MENU;
}