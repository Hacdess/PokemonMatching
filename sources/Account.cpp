#include "../headers/Account/Account.h"

void AccountScene::setupSignUp()
{
    // Get Back
    Image img = LoadImage("resources/img/background/background.png");
    background = LoadTextureFromImage(img);
    UnloadImage(img);

    // Store Title
    title[0].content = new char[strlen("POKEMON") + 1];
    title[0].FontColor = RED;
    strcpy(title[0].content, "POKEMON");
    title[1].content = new char[strlen("MATCHING") + 1];
    title[1].FontColor = YELLOW;
    strcpy(title[1].content, "MATCHING");

    short i;
    float startY = float(WinHeight) / 4,
          startX = float(WinWdith) / 5,
          FontSize = float(WinHeight) / 8,
          spacing = FontSize / 5;

    for (i = 0; i < 2; i++)
    {
        title[i].FontSize = FontSize;
        title[i].BorderColor = BlackTrans;

        title[i].ContentLength = float(MeasureText(title[i].content, title[i].FontSize));
        title[i].pos = {(float(WinWdith) - title[i].ContentLength) / 2, startY};
        title[i].border = {startX, startY - spacing, startX * 3, title[i].FontSize + spacing * 1.5f};

        startY = startY + title[i].FontSize + spacing * 1.5f;
    }

    // draw things
    //  Login box
    loginbox[0].content = new char[strlen("Username") + 1];
    strcpy(loginbox[0].content, "Username");

    loginbox[1].content = new char[strlen("Password") + 1];
    strcpy(loginbox[1].content, "Password");

    // Login input

    loginInput[0].content = new char[strlen("Input username here") + 1];
    strcpy(loginInput[0].content, "Input username here");

    loginInput[1].content = new char[strlen("Input password here") + 1];
    strcpy(loginInput[1].content, "Input password here");

    // Warning

    loginCommand[0].content = new char[strlen("Please input username and password") + 1];
    strcpy(loginCommand[0].content, "Please input username and password");

    // Login and exit

    loginConfirm[0].content = new char[strlen("Sign Up") + 1];
    strcpy(loginConfirm[0].content, "Sign Up");

    loginConfirm[1].content = new char[strlen("Exit") + 1];
    strcpy(loginConfirm[1].content, "Exit");

    FontSize = FontSize * 8 / 40;
    startY = startY + FontSize,

    FontSize = float(WinHeight) / 20,
    spacing = FontSize / 8;
    float loginSpace = float(WinWdith) / 5,
          loginWidth = loginSpace - 4.0f * spacing,
          loginHeight = float(WinHeight) / 15;

    startX = loginSpace;
    // Get loginbox' parameter
    for (i = 0; i < 2; i++)
    {
        loginbox[i].FontSize = FontSize;
        loginbox[i].BorderColor = DarkCyanTrans;
        loginbox[i].FontColor = WHITE;

        loginbox[i].ContentLength = float(MeasureText(loginbox[i].content, loginbox[i].FontSize));
        loginbox[i].border = {startX + spacing * 2.0f, startY + (spacing + loginHeight) * i, loginWidth, loginHeight};
        loginbox[i].pos = {startX + (loginSpace - loginbox[i].ContentLength) / 2, startY + (loginHeight - loginbox[i].FontSize) / 2 + (spacing + loginHeight) * i};
    }

    // Get loginInput' parameter

    startX += spacing + loginWidth;
    for (i = 0; i < 2; i++)
    {
        loginInput[i].FontSize = FontSize;
        loginInput[i].BorderColor = DarkCyanTrans;
        loginInput[i].FontColor = BLACK;

        loginInput[i].ContentLength = float(MeasureText(loginInput[i].content, loginInput[i].FontSize));
        loginInput[i].border = {startX + spacing * 2.0f, startY + (spacing + loginHeight) * i, loginWidth * 2, loginHeight};
        loginInput[i].pos = {startX - (loginSpace - loginInput[i].ContentLength) / 2, startY + (loginHeight - loginInput[i].FontSize) / 2 + (spacing + loginHeight) * i};
    }

    startX = loginSpace;
    startY += 2.5f * (spacing + loginHeight);
    loginCommand[0].FontSize = FontSize;
    loginCommand[0].BorderColor = DarkCyanTrans;
    loginCommand[0].FontColor = RED;

    loginCommand[0].ContentLength = float(MeasureText(loginCommand[0].content, loginCommand[0].FontSize));

    loginCommand[0].pos = {startX - (loginSpace - loginCommand[0].ContentLength) / 2 - loginSpace / 1.5f, startY + (loginHeight - loginCommand[0].FontSize) / 2};

    startY += spacing + loginHeight;
    startX = 1.5f * loginSpace;
    for (i = 0; i < 2; i++)
    {
        loginConfirm[i].FontSize = FontSize;
        loginConfirm[i].BorderColor = DarkCyanTrans;
        loginConfirm[i].FontColor = WHITE;

        loginConfirm[i].ContentLength = float(MeasureText(loginConfirm[i].content, loginConfirm[i].FontSize));
        loginConfirm[i].border = {startX + spacing * 2.0f, startY, loginWidth, loginHeight};
        loginConfirm[i].pos = {startX + (loginSpace - loginConfirm[i].ContentLength) / 2, startY + (loginHeight - loginConfirm[i].FontSize) / 2};
        startX += spacing + loginWidth;
    }
}

void AccountScene::setupSignIn()
{
    // Get Back
    Image img = LoadImage("resources/img/background/background.png");
    background = LoadTextureFromImage(img);
    UnloadImage(img);

    // Store Title
    title[0].content = new char[strlen("POKEMON") + 1];
    title[0].FontColor = RED;
    strcpy(title[0].content, "POKEMON");
    title[1].content = new char[strlen("MATCHING") + 1];
    title[1].FontColor = YELLOW;
    strcpy(title[1].content, "MATCHING");

    short i;
    float startY = float(WinHeight) / 4,
          startX = float(WinWdith) / 5,
          FontSize = float(WinHeight) / 8,
          spacing = FontSize / 5;

    for (i = 0; i < 2; i++)
    {
        title[i].FontSize = FontSize;
        title[i].BorderColor = BlackTrans;

        title[i].ContentLength = float(MeasureText(title[i].content, title[i].FontSize));
        title[i].pos = {(float(WinWdith) - title[i].ContentLength) / 2, startY};
        title[i].border = {startX, startY - spacing, startX * 3, title[i].FontSize + spacing * 1.5f};

        startY = startY + title[i].FontSize + spacing * 1.5f;
    }

    // draw things
    //  Login box
    loginbox[0].content = new char[strlen("Username") + 1];
    strcpy(loginbox[0].content, "Username");

    loginbox[1].content = new char[strlen("Password") + 1];
    strcpy(loginbox[1].content, "Password");

    // Login input

    loginInput[0].content = new char[strlen("Input username here") + 1];
    strcpy(loginInput[0].content, "Input username here");

    loginInput[1].content = new char[strlen("Input password here") + 1];
    strcpy(loginInput[1].content, "Input password here");

    // Warning

    loginCommand[0].content = new char[strlen("Please input username and password") + 1];
    strcpy(loginCommand[0].content, "Please input username and password");

    // Login and exit

    loginConfirm[0].content = new char[strlen("Sign In") + 1];
    strcpy(loginConfirm[0].content, "Sign In");

    loginConfirm[1].content = new char[strlen("Exit") + 1];
    strcpy(loginConfirm[1].content, "Exit");

    FontSize = FontSize * 8 / 40;
    startY = startY + FontSize,

    FontSize = float(WinHeight) / 20,
    spacing = FontSize / 8;
    float loginSpace = float(WinWdith) / 5,
          loginWidth = loginSpace - 4.0f * spacing,
          loginHeight = float(WinHeight) / 15;

    startX = loginSpace;
    // Get loginbox' parameter
    for (i = 0; i < 2; i++)
    {
        loginbox[i].FontSize = FontSize;
        loginbox[i].BorderColor = DarkCyanTrans;
        loginbox[i].FontColor = WHITE;

        loginbox[i].ContentLength = float(MeasureText(loginbox[i].content, loginbox[i].FontSize));
        loginbox[i].border = {startX + spacing * 2.0f, startY + (spacing + loginHeight) * i, loginWidth, loginHeight};
        loginbox[i].pos = {startX + (loginSpace - loginbox[i].ContentLength) / 2, startY + (loginHeight - loginbox[i].FontSize) / 2 + (spacing + loginHeight) * i};
    }

    // Get loginInput' parameter

    startX += spacing + loginWidth;
    for (i = 0; i < 2; i++)
    {
        loginInput[i].FontSize = FontSize;
        loginInput[i].BorderColor = DarkCyanTrans;
        loginInput[i].FontColor = BLACK;

        loginInput[i].ContentLength = float(MeasureText(loginInput[i].content, loginInput[i].FontSize));
        loginInput[i].border = {startX + spacing * 2.0f, startY + (spacing + loginHeight) * i, loginWidth * 2, loginHeight};
        loginInput[i].pos = {startX - (loginSpace - loginInput[i].ContentLength) / 2, startY + (loginHeight - loginInput[i].FontSize) / 2 + (spacing + loginHeight) * i};
    }

    startX = loginSpace;
    startY += 2.5f * (spacing + loginHeight);
    loginCommand[0].FontSize = FontSize;
    loginCommand[0].BorderColor = DarkCyanTrans;
    loginCommand[0].FontColor = RED;

    loginCommand[0].ContentLength = float(MeasureText(loginCommand[0].content, loginCommand[0].FontSize));

    loginCommand[0].pos = {startX - (loginSpace - loginCommand[0].ContentLength) / 2 - loginSpace / 1.5f, startY + (loginHeight - loginCommand[0].FontSize) / 2};

    startY += spacing + loginHeight;
    startX = 1.5f * loginSpace;
    for (i = 0; i < 2; i++)
    {
        loginConfirm[i].FontSize = FontSize;
        loginConfirm[i].BorderColor = DarkCyanTrans;
        loginConfirm[i].FontColor = WHITE;

        loginConfirm[i].ContentLength = float(MeasureText(loginConfirm[i].content, loginConfirm[i].FontSize));
        loginConfirm[i].border = {startX + spacing * 2.0f, startY, loginWidth, loginHeight};
        loginConfirm[i].pos = {startX + (loginSpace - loginConfirm[i].ContentLength) / 2, startY + (loginHeight - loginConfirm[i].FontSize) / 2};
        startX += spacing + loginWidth;
    }
}

void AccountScene::inputAccount(Account &a)
{
    int key = GetCharPressed();
    while (key > 0)
    {
        if (32 <= key && key <= 126)
        {
            a.name[a.nameCount] = (char)key;
            a.nameCount++;
            if (a.nameCount > 20)
                a.nameCount = 20;
            a.name[a.nameCount] = '\0';
        }
        key = GetCharPressed();
    }

    if (IsKeyPressed(KEY_BACKSPACE))
    {
        a.nameCount--;
        if (a.nameCount < 0)
            a.nameCount = 0;
        a.name[a.nameCount] = '\0';
    }
}

void AccountScene::inputPass(Account &a)
{
    int key = GetCharPressed();
    while (key > 0)
    {
        if (32 <= key && key <= 126)
        {
            a.pass[a.passCount] = (char)key;
            a.passCount++;
            if (a.passCount > 20)
                a.passCount = 20;
            a.pass[a.passCount] = '\0';
        }
        key = GetCharPressed();
    }

    if (IsKeyPressed(KEY_BACKSPACE))
    {
        a.passCount--;
        if (a.passCount < 0)
            a.passCount = 0;
        a.pass[a.passCount] = '\0';
    }
}

char *AccountScene::modifyName(Account a)
{
    char *tmp;
    tmp = NULL;

    if (a.nameCount != 0)
    {
        if (a.nameCount > 15)
        {
            int i;
            for (i = 11; i < 14; i++)
                a.name[i] = '.';
            a.name[14] = '\0';
        }

        tmp = new char[strlen(a.name) + 1];
        strcpy(tmp, a.name);
    }
    else
    {
        tmp = new char[strlen("Input username here") + 1];
        strcpy(tmp, "Input username here");
    }
    return tmp;
}

char *AccountScene::modifyPass(Account a)
{
    char *tmp;
    tmp = NULL;

    if (a.passCount != 0)
    {
        if (a.passCount > 15)
        {
            int i;
            for (i = 11; i < 14; i++)
                a.pass[i] = '.';
            a.pass[14] = '\0';
        }

        tmp = new char[strlen(a.pass) + 1];
        strcpy(tmp, a.pass);
    }
    else
    {
        tmp = new char[strlen("Input password here") + 1];
        strcpy(tmp, "Input password here");
    }
    return tmp;
}

int AccountScene::checkVaildUsername(Account a)
{
    int i, sig = 0;
    // Check if there is nothing
    if (a.nameCount == 0)
        return 1;

    // Check if more than 16 letters
    if (a.nameCount > 16)
        return 2;

    // Check if there are only space
    for (i = 0; i < a.nameCount; i++)
        if (a.name[i] != ' ')
            sig++;
    if (sig == 0)
        return 3;

    return 4;
}

int AccountScene::checkValidPassWord(Account a)
{
    int i, sig = 0;
    // Check if there is nothing
    if (a.passCount == 0)
        return 1;

    // Check if more than 16 letters
    if (a.passCount > 16)
        return 2;

    // Check if there are only space
    for (i = 0; i < a.passCount; i++)
        if (a.pass[i] != ' ')
            sig++;
    if (sig == 0)
        return 3;

    return 4;
}

char *AccountScene::modifyCommandUsername(Account a)
{
    char *tmp;
    tmp = NULL;
    int check = checkVaildUsername(a);
    switch (check)
    {
    case 1:
    case 3:
        tmp = new char[strlen("Username should have at least one letter alphabet") + 1];
        strcpy(tmp, "Username should have at least one letter alphabet");
        break;

    case 2:
        tmp = new char[strlen("Username should have no more than 15 letters") + 1];
        strcpy(tmp, "Username should have no more than 15 letters");
        break;
    case 4:
        tmp = new char[strlen("Valid Username") + 1];
        strcpy(tmp, "Valid Username");
        break;
    }
    return tmp;
}

char *AccountScene::modifyCommandPassword(Account a)
{
    char *tmp;
    tmp = NULL;
    int check = checkValidPassWord(a);
    switch (check)
    {
    case 1:
    case 3:
        tmp = new char[strlen("Password should have at least one letter alphabet") + 1];
        strcpy(tmp, "Passowrd should have at least one letter alphabet");
        break;

    case 2:
        tmp = new char[strlen("Password should have no more than 15 letters") + 1];
        strcpy(tmp, "Password should have no more than 15 letters");
        break;
    case 4:
        tmp = new char[strlen("Valid Password") + 1];
        strcpy(tmp, "Valid Password");
        break;
    }
    return tmp;
}

char *AccountScene::modifyCommandForSignUp(Account a)
{
    char *tmp;
    tmp = NULL;

    int checkName = checkVaildUsername(a);
    int checkPass = checkValidPassWord(a);

    if (checkName == 1 && checkPass == 1)
    {
        tmp = new char[strlen("Please input username and password") + 1];
        strcpy(tmp, "Please input username and password");
    }
    else if (checkName == 1)
    {
        tmp = new char[strlen("Remember to input username") + 1];
        strcpy(tmp, "Remember to input username");
    }
    else if (checkPass == 1)
    {
        tmp = new char[strlen("Remember to input password") + 1];
        strcpy(tmp, "Remember to input password");
    }
    else if (checkName == 4 && checkPass == 4)
    {
        if (readFileAccountAndCheck(a) == 1)
        {
            tmp = new char[strlen("Account existed") + 1];
            strcpy(tmp, "Account existed");
        }
        else
        {
            tmp = new char[strlen("Valid username and password") + 1];
            strcpy(tmp, "Valid username and password");
        }
    }
    else if (checkName == 4)
    {
        tmp = new char[strlen("Invalid password") + 1];
        strcpy(tmp, "Invalid password");
    }
    else if (checkPass == 4)
    {
        tmp = new char[strlen("Invalid username") + 1];
        strcpy(tmp, "Invalid username");
    }
    else
    {
        tmp = new char[strlen("Invalid account") + 1];
        strcpy(tmp, "Invalid account");
    }
    return tmp;
}

char *AccountScene::modifyCommandForSignIn(Account a)
{
        char *tmp;
    tmp = NULL;

    int checkName = checkVaildUsername(a);
    int checkPass = checkValidPassWord(a);

    if (checkName == 1 && checkPass == 1)
    {
        tmp = new char[strlen("Please input username and password") + 1];
        strcpy(tmp, "Please input username and password");
    }
    else if (checkName == 1)
    {
        tmp = new char[strlen("Remember to input username") + 1];
        strcpy(tmp, "Remember to input username");
    }
    else if (checkPass == 1)
    {
        tmp = new char[strlen("Remember to input password") + 1];
        strcpy(tmp, "Remember to input password");
    }
    else if (checkName == 4 && checkPass == 4)
    {
        if (readFileAccountAndCheck(a) == 0)
        {
            tmp = new char[strlen("Account didn't exist") + 1];
            strcpy(tmp, "Account didn't exist");
        }
        else
        {
            tmp = new char[strlen("Valid username and password") + 1];
            strcpy(tmp, "Valid username and password");
        }
    }
    else if (checkName == 4)
    {
        tmp = new char[strlen("Invalid password") + 1];
        strcpy(tmp, "Invalid password");
    }
    else if (checkPass == 4)
    {
        tmp = new char[strlen("Invalid username") + 1];
        strcpy(tmp, "Invalid username");
    }
    else
    {
        tmp = new char[strlen("Invalid account") + 1];
        strcpy(tmp, "Invalid account");
    }
    return tmp;
}

void AccountScene::writeFileAccount(Account &a)
{
    std::fstream f;
    f.open("D:/game/Pikachu/resources/file/Account.txt", std::ios::out | std::ios::app);

    f << a.name << " " << '|' << " " << a.pass << '\n';

    a.nameCount = 0;
    a.name[a.nameCount] = '\0';

    a.passCount = 0;
    a.pass[a.passCount] = '\0';

    f.close();
}

bool AccountScene::readFileAccountAndCheck(Account a)
{
    std::fstream f;
    f.open("D:/game/Pikachu/resources/file/Account.txt", std::ios ::in);

    char s, name[21], pass[21];

    std::string t;

    // Get the first line that's not neccessary
    getline(f, t, '\n');
    std::stringstream ss(t);
    ss >> name;
    ss >> s;
    ss >> pass;

    while (!f.eof())
    {

        getline(f, t, '\n');

        std::stringstream ss(t);

        ss >> name;
        ss >> s;
        ss >> pass;

        if (name[0] != '\0' && pass[0] != '\0')
            if (strcmp(name, a.name) == 0 && strcmp(pass, a.pass) == 0)
                return true;
    }
    f.close();
    return false;
}

Status AccountScene::drawSignUp(bool &isSigned, Account &a)
{

    // Draw Background image
    ClearBackground(BLACK);
    DrawTexturePro(background, {0, 0, 1792.0f, 1024.0f}, {0, 0, float(WinWdith), float(WinHeight)}, {0, 0}, 0.0f, WHITE);

    int i; // Có thể đổi qua short

    // Draw Game Title
    for (i = 0; i < 2; i++)
    {
        DrawRectangleRec(title[i].border, title[i].BorderColor);
        DrawText(title[i].content, title[i].pos.x, title[i].pos.y, title[i].FontSize, title[i].FontColor);
    }

    moveSelector2D(selector);
    if (selector.y == 2)
    {
        if (selector.x < 0)
            selector.x = 1;
        if (selector.x > 1)
            selector.x = 0;
    }

    if (selector.y == 1)
        if (selector.x != 1)
            selector.x = 1;

    if (selector.y == 0)
        if (selector.x != 1)
            selector.x = 1;

    if (selector.y < 0)
        selector.y = 2;

    if (selector.y > 2)
    {
        if (selector.x == 0)
            selector.y = 2;
        if (selector.x == 1)
            selector.y = 0;
    }

    if (selector.x == 1 && selector.y == 0)
    {
        loginInput[0].BorderColor = WHITE;
        inputAccount(a);
        delete[] loginCommand[0].content;
        loginCommand[0].content = NULL;
        loginCommand[0].content = modifyCommandUsername(a);
    }
    else
        loginInput[0].BorderColor = DarkCyanTrans;

    if (selector.x == 1 && selector.y == 1)
    {
        loginInput[1].BorderColor = WHITE;
        inputPass(a);
        delete[] loginCommand[0].content;
        loginCommand[0].content = NULL;
        loginCommand[0].content = modifyCommandPassword(a);
    }
    else
        loginInput[1].BorderColor = DarkCyanTrans;

    if (selector.y == 2 && selector.x == 0)
    {
        loginConfirm[0].FontColor = DarkCyanTrans;
        loginConfirm[0].BorderColor = WHITE;
        delete[] loginCommand[0].content;
        loginCommand[0].content = NULL;
        loginCommand[0].content = modifyCommandForSignUp(a);
        if (IsKeyPressed(KEY_ENTER) && checkVaildUsername(a) == 4 && checkValidPassWord(a) == 4 && readFileAccountAndCheck(a) == 0)
        {
            writeFileAccount(a);
        }
    }
    else
    {
        loginConfirm[0].FontColor = WHITE;
        loginConfirm[0].BorderColor = DarkCyanTrans;
    }

    if (selector.y == 2 && selector.x == 1)
    {
        loginConfirm[1].FontColor = DarkCyanTrans;
        loginConfirm[1].BorderColor = WHITE;
    }
    else
    {
        loginConfirm[1].FontColor = WHITE;
        loginConfirm[1].BorderColor = DarkCyanTrans;
    }

    // Draw login
    for (i = 0; i < 2; i++)
    {
        DrawRectangleRec(loginbox[i].border, loginbox[i].BorderColor);
        DrawText(loginbox[i].content, loginbox[i].pos.x, loginbox[i].pos.y, loginbox[i].FontSize, loginbox[i].FontColor);
    }

    for (i = 0; i < 2; i++)
    {
        delete[] loginInput[i].content;
        loginInput[i].content = NULL;
    }

    loginInput[0].content = modifyName(a);
    loginInput[1].content = modifyPass(a);
    for (i = 0; i < 2; i++)
    {
        DrawRectangleRec(loginInput[i].border, loginInput[i].BorderColor);
        DrawText(loginInput[i].content, loginInput[i].pos.x, loginInput[i].pos.y, loginInput[i].FontSize, loginInput[i].FontColor);
    }

    //  DrawRectangleRec(loginCommand[0].border, loginCommand[0].BorderColor);
    DrawText(loginCommand[0].content, loginCommand[0].pos.x, loginCommand[0].pos.y, loginCommand[0].FontSize, loginCommand[0].FontColor);

    for (i = 0; i < 2; i++)
    {
        DrawRectangleRec(loginConfirm[i].border, loginConfirm[i].BorderColor);
        DrawText(loginConfirm[i].content, loginConfirm[i].pos.x, loginConfirm[i].pos.y, loginConfirm[i].FontSize, loginConfirm[i].FontColor);
    }

    return SIGNUP;
}

Status AccountScene::drawSignIn(bool &isSigned, Account &a)
{

    // Draw Background image
    ClearBackground(BLACK);
    DrawTexturePro(background, {0, 0, 1792.0f, 1024.0f}, {0, 0, float(WinWdith), float(WinHeight)}, {0, 0}, 0.0f, WHITE);

    int i; // Có thể đổi qua short

    // Draw Game Title
    for (i = 0; i < 2; i++)
    {
        DrawRectangleRec(title[i].border, title[i].BorderColor);
        DrawText(title[i].content, title[i].pos.x, title[i].pos.y, title[i].FontSize, title[i].FontColor);
    }

    moveSelector2D(selector);
    if (selector.y == 2)
    {
        if (selector.x < 0)
            selector.x = 1;
        if (selector.x > 1)
            selector.x = 0;
    }

    if (selector.y == 1)
        if (selector.x != 1)
            selector.x = 1;

    if (selector.y == 0)
        if (selector.x != 1)
            selector.x = 1;

    if (selector.y < 0)
        selector.y = 2;

    if (selector.y > 2)
    {
        if (selector.x == 0)
            selector.y = 2;
        if (selector.x == 1)
            selector.y = 0;
    }

    if (selector.x == 1 && selector.y == 0)
    {
        loginInput[0].BorderColor = WHITE;
        inputAccount(a);
        delete[] loginCommand[0].content;
        loginCommand[0].content = NULL;
        loginCommand[0].content = modifyCommandUsername(a);
    }
    else
        loginInput[0].BorderColor = DarkCyanTrans;

    if (selector.x == 1 && selector.y == 1)
    {
        loginInput[1].BorderColor = WHITE;
        inputPass(a);
        delete[] loginCommand[0].content;
        loginCommand[0].content = NULL;
        loginCommand[0].content = modifyCommandPassword(a);
    }
    else
        loginInput[1].BorderColor = DarkCyanTrans;

    if (selector.y == 2 && selector.x == 0)
    {
        loginConfirm[0].FontColor = DarkCyanTrans;
        loginConfirm[0].BorderColor = WHITE;
        delete[] loginCommand[0].content;
        loginCommand[0].content = NULL;
        loginCommand[0].content = modifyCommandForSignIn(a);
        if (IsKeyPressed(KEY_ENTER) && checkVaildUsername(a) == 4 && checkValidPassWord(a) == 4 && readFileAccountAndCheck(a) == 1)
        {
            // Chỗ này chuyển qua scence khác giúp tui
            // Đoạn dưới là reset lại
            a.nameCount = 0;
            a.name[a.nameCount] = '\0';

            a.passCount = 0;
            a.pass[a.passCount] = '\0';
        }
    }
    else
    {
        loginConfirm[0].FontColor = WHITE;
        loginConfirm[0].BorderColor = DarkCyanTrans;
    }

    if (selector.y == 2 && selector.x == 1)
    {
        loginConfirm[1].FontColor = DarkCyanTrans;
        loginConfirm[1].BorderColor = WHITE;
    }
    else
    {
        loginConfirm[1].FontColor = WHITE;
        loginConfirm[1].BorderColor = DarkCyanTrans;
    }

    // Draw login
    for (i = 0; i < 2; i++)
    {
        DrawRectangleRec(loginbox[i].border, loginbox[i].BorderColor);
        DrawText(loginbox[i].content, loginbox[i].pos.x, loginbox[i].pos.y, loginbox[i].FontSize, loginbox[i].FontColor);
    }

    for (i = 0; i < 2; i++)
    {
        delete[] loginInput[i].content;
        loginInput[i].content = NULL;
    }

    loginInput[0].content = modifyName(a);
    loginInput[1].content = modifyPass(a);
    for (i = 0; i < 2; i++)
    {
        DrawRectangleRec(loginInput[i].border, loginInput[i].BorderColor);
        DrawText(loginInput[i].content, loginInput[i].pos.x, loginInput[i].pos.y, loginInput[i].FontSize, loginInput[i].FontColor);
    }

    //  DrawRectangleRec(loginCommand[0].border, loginCommand[0].BorderColor);
    DrawText(loginCommand[0].content, loginCommand[0].pos.x, loginCommand[0].pos.y, loginCommand[0].FontSize, loginCommand[0].FontColor);

    for (i = 0; i < 2; i++)
    {
        DrawRectangleRec(loginConfirm[i].border, loginConfirm[i].BorderColor);
        DrawText(loginConfirm[i].content, loginConfirm[i].pos.x, loginConfirm[i].pos.y, loginConfirm[i].FontSize, loginConfirm[i].FontColor);
    }

    return SIGNIN;
}

void AccountScene::addHead(Account *&pHead, Account a)
{
    Account *tmp = new Account;

    // Save Username first
    strcpy(tmp->name, a.name);
    tmp->nameCount = a.nameCount;

    // Save PassWord
    strcpy(tmp->pass, a.pass);
    tmp->passCount = a.passCount;

    tmp->next = NULL;

    // Delete name and pass after delete
    a.nameCount = 0;
    a.passCount = 0;
    a.name[0] = '\0';
    a.pass[0] = '\0';

    if (pHead == NULL)
        pHead = tmp;
    else
    {
        tmp->next = pHead;
        pHead = tmp;
    }
}

void AccountScene::deleteList(Account *&pHead)
{
    Account *cur;
    while (pHead != NULL)
    {
        cur = pHead;
        pHead = pHead->next;

        cur->nameCount = 0;
        cur->passCount = 0;

        cur->name[0] = '\0';
        cur->pass[0] = '\0';

        delete cur;
        cur = NULL;
    }
}