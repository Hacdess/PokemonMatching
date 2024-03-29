#include "../headers/MenuScreen/MenuScreen.h"

#include <iostream>

using namespace std;

bool isSigned = 0;


void changeStatus (bool& isSigned, char*& content1, char*& content2) {
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

void DrawMenuScreen(const int& WindowWidth, const int& WindowHeight, Color ColorBackground) {
    InitWindow (WindowWidth, WindowHeight, GameName);
    SetTargetFPS (GameFPS);

    //Create icon
    Image icon = LoadImage("resources/img/logo.png");
    SetWindowIcon (icon);
    
    //Get Background image
    Image BackgroundImg = LoadImage ("resources/img/Background/Fantasy Forests/Castle 2.png");
    //ImageBlurGaussian (&BackgroundImg, 1); //Blur Image to set Background;
    Texture2D BackgroundTexture = LoadTextureFromImage(BackgroundImg);

    //font
    Font font = LoadFont ("resources/font/alpha_beta.png");

    //Game title
    float TitleSize = float (WindowHeight / 8);
    float TitleSpacing = TitleSize / 5;

    //Determine the position of "POKEMON" word by its length
    Vector2 LengthWord = MeasureTextEx (font, "POKEMON", TitleSize, TitleSpacing);
    Vector2 posTitle_POKEMON = {float ((WindowWidth - LengthWord.x) / 2 ), float (WindowHeight / 4)};

    //Determine the position of "MATCHING" word by its length
    LengthWord = MeasureTextEx (font, "MATCHING", TitleSize, TitleSpacing);
    Vector2 posTitle_MATCHING = {float ((WindowWidth - LengthWord.x) / 2 ), posTitle_POKEMON.y + LengthWord.y};

    //The border contains the title "POKEMON MATCHING"
    Rectangle title = {float(WindowWidth / 5), posTitle_POKEMON.y - TitleSpacing, float(WindowWidth / 5 * 3), TitleSize * 2.0f + TitleSpacing};


    //Buttons
    float ButFontSize = float (WindowHeight / 25);
    float ButtonTextSpacing = float (WindowHeight / 80);
    Button** buttons = new Button*[2];
    buttons[0] = new Button[3];
    buttons[1] = new Button[3];

    //Add content to buttons
    unsigned int i, j;
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

    //Define some important positions, spacings and sizes
    float paddingX = float (WindowWidth / 60);
    float ButtonSpaceX = float (WindowWidth) / 3;

    float buttonsX =  0;
    float buttonsY = title.y + title.height * 1.5f;
    float ButtonsWidth =  ButtonSpaceX - 2 * paddingX;
    float ButtonsHeight = WindowHeight / 10;

    //Get Middle and set position
    for (j = 0; j < 3; j ++)
        for (i = 0; i < 2; i ++) {
            buttons[i][j].SizeContent = MeasureTextEx(font, buttons[i][j].content, ButFontSize, ButtonTextSpacing);
            buttons[i][j].BorderColor = ButtonsColor;
            buttons[i][j].FontColor = WHITE;
            buttons[i][j].border = {buttonsX + paddingX, buttonsY, ButtonsWidth, ButtonsHeight};
            buttons[i][j].pos = {buttonsX + (ButtonSpaceX - buttons[i][j].SizeContent.x) / 2, buttonsY + (ButtonsHeight - buttons[i][j].SizeContent.y) / 2};
            if (i == 1) {
                buttons[i][j].border.y = buttons[i][j].border.y + ButtonsHeight + paddingX;
                buttons[i][j].pos.y = buttons[i][j].pos.y + ButtonsHeight + paddingX;
                buttonsX += ButtonSpaceX;
            }
        }

    //define selector to point as the first button;
    Selector2D selector;
    selector.x = 0;
    selector.y = 0;

    //Draw Window
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground (ColorBackground);

        //DrawBackground image
        DrawTexturePro (BackgroundTexture, {0, 0, 1792.0f, 1024.0f}, {0, 0, float(WindowWidth), float(WindowHeight)}, {0, 0}, 0.0f, WHITE);
        
        //Write Game Title
        DrawRectangleRec (title, {0, 0, 0, 100});
        DrawTextEx (font, "POKEMON", posTitle_POKEMON, TitleSize, TitleSpacing, RED);
        DrawTextEx (font, "MATCHING", posTitle_MATCHING, TitleSize, TitleSpacing, YELLOW);

        //Handlde Selector
        moveSelector2D (selector);
        if (selector.x < 0) selector.x = 2;
        if (selector.x > 2) selector.x = 0;
        if (selector.y < 0) selector.y = 1;
        if (selector.y > 1) selector.y = 0;

        if (IsKeyPressed (KEY_ENTER)) {
            // Sign up / Sign in / Sign out / Account
            if (selector.x == 0) {
                if (!(selector.y == 0 && isSigned)) {
                    changeStatus (isSigned, buttons[0][0].content, buttons[1][0].content);
                    buttonsX = 0;

                    for (i = 0; i < 2; i ++) {
                        buttons[i][0].SizeContent = MeasureTextEx(font, buttons[i][0].content, ButFontSize, ButtonTextSpacing);
                        buttons[i][0].border = {buttonsX + paddingX, buttonsY, ButtonsWidth, ButtonsHeight};
                        buttons[i][0].pos = {buttonsX + (ButtonSpaceX - buttons[i][0].SizeContent.x) / 2, buttonsY + (ButtonsHeight - buttons[i][0].SizeContent.y) / 2};
                        if (i == 1) {
                            buttons[i][0].border.y = buttons[i][0].border.y + ButtonsHeight + paddingX;
                            buttons[i][0].pos.y = buttons[i][0].pos.y + ButtonsHeight + paddingX;
                        }
                    }
                }

                if (!isSigned ) {
                    
                }

                else {
                    
                }

            }

            //PlayGame
            if (selector.x == 1 && selector.y == 0)
                DrawGameScreen(WindowWidth, WindowHeight, ColorBackground);

            //Exit
            if (selector.x == 2 && selector.y == 1) {
                CloseWindow();
                return;
            }
        }

        //Draw Buttons
        for (i = 0; i < 2; i ++)
            for (j = 0; j < 3; j ++) {
            //check which button does selector choose
            //it's okay to compare as below
            if (selector.x == j && selector.y == i) {
                buttons[i][j].BorderColor = WHITE;
                buttons[i][j].FontColor = ButtonsColor;
            }

            else if (!(selector.x == j && selector.y == i)){
                buttons[i][j].BorderColor = ButtonsColor;
                buttons[i][j].FontColor = WHITE;
            }

            DrawRectangleRec (buttons[i][j].border, buttons[i][j].BorderColor);
            DrawTextEx (font, buttons[i][j].content, buttons[i][j].pos, ButFontSize, ButtonTextSpacing, buttons[i][j].FontColor);
            }

        //

        EndDrawing();
    }

    cout << buttons[0][0].content << ' ' << buttons[1][0].content;

    //Deallocate
    for (i = 0; i < 2; i ++) {
        for (j = 0; j < 3; j ++)
            delete[] buttons[i][j].content;
        delete[] buttons[i];
    }
    delete[] buttons;

    //Unload items
    UnloadImage(icon);
    UnloadImage(BackgroundImg);
    UnloadTexture (BackgroundTexture);
}