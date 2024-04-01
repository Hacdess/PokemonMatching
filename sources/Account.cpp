#include "../headers/Account/Account.h"

void AccountScene::setup()
{
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

    unsigned short i, j;
    float   startY = float(WinHeight) / 4,
            startX = float(WinWdith) / 5,
            FontSize = float(WinHeight) / 8,
            spacing = FontSize / 5;
    
    for (int i = 0; i < 2; i ++) {
        title[i].FontSize = FontSize;
        title[i].BorderColor = BlackTrans;

        title[i].ContentLength = float(MeasureText(title[i].content, title[i].FontSize));
        title[i].pos = {(float(WinWdith) - title[i].ContentLength) / 2, startY};
        title[i].border = {startX, startY - spacing, startX * 3, title[i].FontSize + spacing * 1.5f};

        startY = startY + title[i].FontSize + spacing * 1.5f;
    }

    //Input information for login
    login[0][0].content = new char[strlen("Username") + 1];
    strcpy(login[0][0].content, "Username");

    login[1][0].content = new char[strlen("Password") + 1];
    strcpy(login[1][0].content, "Password");

    login[0][1].content = new char[strlen("Input username here") + 1];
    strcpy(login[1][0].content, "Input username here");

    login[1][1].content = new char[strlen("Input password here") + 1];
    strcpy(login[1][0].content, "Input password here");

    startY = startY + title[1].FontSize,
    startX = 0,
    FontSize = float(WinHeight) / 20,
    spacing = FontSize / 5;
    float   loginpace = float (WinWdith) / 3,
            LoginWidth =  loginpace - 4.0f * spacing,
            LoginHeight = float(WinHeight) / 10;

    //Get login' parameter
    for (j = 0; j < 2; j ++)
        for (i = 0; i < 2; i ++) {
            login[i][j].FontSize = FontSize;
            login[i][j].BorderColor = DarkCyanTrans;
            login[i][j].FontColor = WHITE;

            login[i][j].ContentLength = float(MeasureText(login[i][j].content, login[i][j].FontSize));
            login[i][j].border = {startX + spacing * 2.0f, startY, LoginWidth, LoginHeight};
            login[i][j].pos = {startX + (loginpace - login[i][j].ContentLength) / 2, startY + (LoginHeight - login[i][j].FontSize) / 2};
            
            if (i == 1) {
                login[i][j].border.y = login[i][j].border.y + LoginHeight + spacing;
                login[i][j].pos.y = login[i][j].pos.y + LoginHeight + spacing;
                startX += loginpace;
            }
        }
}

Status AccountScene::draw(bool &isSigned)
{

    //Draw Background image
    ClearBackground (BLACK);
    DrawTexturePro (background, {0, 0, 1792.0f, 1024.0f}, {0, 0, float(WinWdith), float(WinHeight)}, {0, 0}, 0.0f, WHITE);

    unsigned int i, j; // Có thể đổi qua short

    //Draw Game Title
    for (i = 0; i < 2; i ++) {
        DrawRectangleRec (title[i].border, title[i].BorderColor);
        DrawText (title[i].content, title[i].pos.x, title[i].pos.y, title[i].FontSize, title[i].FontColor);
    }

        if (IsKeyPressed (KEY_ENTER)) {
            //Column: Sign up / Sign in / Sign out / Account
            if (selector.x == 0) {
                

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

    //Draw login
    for (i = 0; i < 2; i ++)
        for (j = 0; j < 3; j ++) {
        //check which button does selector choose, it's okay to compare as below
        if (selector.x == j && selector.y == i) {
            login[i][j].BorderColor = WHITE;
            login[i][j].FontColor = DarkCyanTrans;
        }

        else if (!(selector.x == j && selector.y == i)){
            login[i][j].BorderColor = DarkCyanTrans;
            login[i][j].FontColor = WHITE;
        }

        DrawRectangleRec (login[i][j].border, login[i][j].BorderColor);
        DrawText (login[i][j].content, login[i][j].pos.x, login[i][j].pos.y, login[i][j].FontSize, login[i][j].FontColor);
        }
    return SIGNIN;
}
