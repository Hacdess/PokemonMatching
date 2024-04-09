#include "../headers/MenuScreen/Account.h"


void SignUpScene::setup() {
    set = 1;
    account.nameCount = 0;
    account.name[account.nameCount] = '\0';
    account.passCount = 0;
    account.pass[account.passCount] = '\0';

    // Get Background
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

    float startY = float(WinHeight) / 4,
          startX = float(WinWdith) / 5,
          FontSize = float(WinHeight) / 8,
          spacing = FontSize / 5;

    short i;
    for (i = 0; i < 2; i++) {
        title[i].FontSize = FontSize;
        title[i].BorderColor = BlackTrans;

        title[i].ContentLength = float(MeasureText(title[i].content, title[i].FontSize));
        title[i].pos = {(float(WinWdith) - title[i].ContentLength) / 2, startY};
        title[i].border = {startX, startY - spacing, startX * 3, title[i].FontSize + spacing * 1.5f};

        startY = startY + title[i].FontSize + spacing * 1.5f;
    }

    //----Setup drawing things----
    //Constant Usernam and Password boxes
    constant[0].content = new char[strlen("Username") + 1];
    strcpy(constant[0].content, "Username");

    constant[1].content = new char[strlen("Password") + 1];
    strcpy(constant[1].content, "Password");

    //Input boxes
    input[0].content = new char[strlen("Input username here") + 1];
    strcpy(input[0].content, "Input username here");

    input[1].content = new char[strlen("Input password here") + 1];
    strcpy(input[1].content, "Input password here");

    //Sign Up and Exit buttons
    confirm[0].content = new char[strlen("Sign Up") + 1];
    strcpy(confirm[0].content, "Sign Up");

    confirm[1].content = new char[strlen("BACK") + 1];
    strcpy(confirm[1].content, "BACK");

    //Warning
    command.content = new char[strlen("Please input username and password") + 1];
    strcpy(command.content, "Please input username and password");
    
    FontSize = FontSize * 8 / 40;
    startY = startY + FontSize,

    FontSize = float(WinHeight) / 20,
    spacing = FontSize / 8;
    float SignUpSpace = float(WinWdith) / 5,
          SignUpWidth = SignUpSpace - 4.0f * spacing,
          SignUpHeight = float(WinHeight) / 15;
    startX = SignUpSpace;

    //Get the parameters of the constant boxes which contain the word "Username" and "Password"
    for (i = 0; i < 2; i++) {
        constant[i].FontSize = FontSize;
        constant[i].BorderColor = DarkCyanTrans;
        constant[i].FontColor = WHITE;

        constant[i].ContentLength = float(MeasureText(constant[i].content, constant[i].FontSize));
        constant[i].border = {startX + spacing * 2.0f, startY + (spacing + SignUpHeight) * i, SignUpWidth, SignUpHeight};
        constant[i].pos = {startX + (SignUpSpace - constant[i].ContentLength) / 2, startY + (SignUpHeight - constant[i].FontSize) / 2 + (spacing + SignUpHeight) * i};
    }

    //Get the parameters of the input boxes
    startX += spacing + SignUpWidth;
    for (i = 0; i < 2; i++) {
        input[i].FontSize = FontSize;
        input[i].BorderColor = DarkCyanTrans;
        input[i].FontColor = DARKGRAY;

        input[i].ContentLength = float(MeasureText(input[i].content, input[i].FontSize));
        input[i].border = {startX + spacing * 2.0f, startY + (spacing + SignUpHeight) * i, SignUpWidth * 2, SignUpHeight};
        input[i].pos = {startX - (SignUpSpace - input[i].ContentLength) / 2, startY + (SignUpHeight - input[i].FontSize) / 2 + (spacing + SignUpHeight) * i};
    }

    startX = SignUpSpace;
    startY += 2.5f * (spacing + SignUpHeight);
    command.FontSize = FontSize;
    command.BorderColor = DarkCyanTrans;
    command.FontColor = RED;
    command.ContentLength = float(MeasureText(command.content, command.FontSize));
    command.pos = {(float(WinWdith) - command.ContentLength) / 2, startY + (SignUpHeight - command.FontSize) / 2};

    startY += spacing + SignUpHeight;
    startX = 1.5f * SignUpSpace;
    for (i = 0; i < 2; i++) {
        confirm[i].FontSize = FontSize;
        confirm[i].BorderColor = DarkCyanTrans;
        confirm[i].FontColor = WHITE;

        confirm[i].ContentLength = float(MeasureText(confirm[i].content, confirm[i].FontSize));
        confirm[i].border = {startX + spacing * 2.0f, startY, SignUpWidth, SignUpHeight};
        confirm[i].pos = {startX + (SignUpSpace - confirm[i].ContentLength) / 2, startY + (SignUpHeight - confirm[i].FontSize) / 2};
        startX += spacing + SignUpWidth;
    }
}

void SignInScene::setup() {
    set = 1;

    // Get Background
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

    float startY = float(WinHeight) / 4,
          startX = float(WinWdith) / 5,
          FontSize = float(WinHeight) / 8,
          spacing = FontSize / 5;

    short i;
    for (i = 0; i < 2; i++) {
        title[i].FontSize = FontSize;
        title[i].BorderColor = BlackTrans;

        title[i].ContentLength = float(MeasureText(title[i].content, title[i].FontSize));
        title[i].pos = {(float(WinWdith) - title[i].ContentLength) / 2, startY};
        title[i].border = {startX, startY - spacing, startX * 3, title[i].FontSize + spacing * 1.5f};

        startY = startY + title[i].FontSize + spacing * 1.5f;
    }

    //----Setup drawing things----
    //Constant Usernam and Password boxes
    constant[0].content = new char[strlen("Username") + 1];
    strcpy(constant[0].content, "Username");

    constant[1].content = new char[strlen("Password") + 1];
    strcpy(constant[1].content, "Password");

    //Input boxes
    input[0].content = new char[strlen("Input username here") + 1];
    strcpy(input[0].content, "Input username here");

    input[1].content = new char[strlen("Input password here") + 1];
    strcpy(input[1].content, "Input password here");

    //Sign Up and Exit buttons
    confirm[0].content = new char[strlen("Sign In") + 1];
    strcpy(confirm[0].content, "Sign In");

    confirm[1].content = new char[strlen("BACK") + 1];
    strcpy(confirm[1].content, "BACK");

    //Warning
    command.content = new char[strlen("Please input username and password") + 1];
    strcpy(command.content, "Please input username and password");
    
    FontSize = FontSize * 8 / 40;
    startY = startY + FontSize,

    FontSize = float(WinHeight) / 20,
    spacing = FontSize / 8;
    float SignInSpace = float(WinWdith) / 5,
          SignInWidth = SignInSpace - 4.0f * spacing,
          SignInHeight = float(WinHeight) / 15;
    startX = SignInSpace;

    //Get the parameters of the constant boxes which contain the word "Username" and "Password"
    for (i = 0; i < 2; i++) {
        constant[i].FontSize = FontSize;
        constant[i].BorderColor = DarkCyanTrans;
        constant[i].FontColor = WHITE;

        constant[i].ContentLength = float(MeasureText(constant[i].content, constant[i].FontSize));
        constant[i].border = {startX + spacing * 2.0f, startY + (spacing + SignInHeight) * i, SignInWidth, SignInHeight};
        constant[i].pos = {startX + (SignInSpace - constant[i].ContentLength) / 2, startY + (SignInHeight - constant[i].FontSize) / 2 + (spacing + SignInHeight) * i};
    }

    //Get the parameters of the input boxes
    startX += spacing + SignInWidth;
    for (i = 0; i < 2; i++) {
        input[i].FontSize = FontSize;
        input[i].BorderColor = DarkCyanTrans;
        input[i].FontColor = DARKGRAY;

        input[i].ContentLength = float(MeasureText(input[i].content, input[i].FontSize));
        input[i].border = {startX + spacing * 2.0f, startY + (spacing + SignInHeight) * i, SignInWidth * 2, SignInHeight};
        input[i].pos = {startX - (SignInSpace - input[i].ContentLength) / 2, startY + (SignInHeight - input[i].FontSize) / 2 + (spacing + SignInHeight) * i};
    }

    startX = SignInSpace;
    startY += 2.5f * (spacing + SignInHeight);
    command.FontSize = FontSize;
    command.BorderColor = DarkCyanTrans;
    command.FontColor = RED;
    command.ContentLength = float(MeasureText(command.content, command.FontSize));
    command.pos = {(float(WinWdith) - command.ContentLength) / 2, startY + (SignInHeight - command.FontSize) / 2};

    startY += spacing + SignInHeight;
    startX = 1.5f * SignInSpace;
    for (i = 0; i < 2; i++) {
        confirm[i].FontSize = FontSize;
        confirm[i].BorderColor = DarkCyanTrans;
        confirm[i].FontColor = WHITE;

        confirm[i].ContentLength = float(MeasureText(confirm[i].content, confirm[i].FontSize));
        confirm[i].border = {startX + spacing * 2.0f, startY, SignInWidth, SignInHeight};
        confirm[i].pos = {startX + (SignInSpace - confirm[i].ContentLength) / 2, startY + (SignInHeight - confirm[i].FontSize) / 2};
        startX += spacing + SignInWidth;
    }
}

    
void inputAccount(Account& account) {
    short key = GetCharPressed();
    while (key > 0) {
        if (32 <= key && key <= 126) {
            account.name[account.nameCount] = (char)key;
            account.nameCount ++;
            if (account.nameCount > 20)
                account.nameCount = 20;
            account.name[account.nameCount] = '\0';
        }
        key = GetCharPressed();
    }

    if (IsKeyPressed(KEY_BACKSPACE)) {
        account.nameCount --;
        if (account.nameCount < 0)
            account.nameCount = 0;
        account.name[account.nameCount] = '\0';
    }
}

void inputPass(Account &account) {
    short key = GetCharPressed();
    while (key > 0) {
        if (32 <= key && key <= 126) {
            account.pass[account.passCount] = (char)key;
            account.passCount ++;
            if (account.passCount > 20)
                account.passCount = 20;
            account.pass[account.passCount] = '\0';
        }
        key = GetCharPressed();
    }

    if (IsKeyPressed(KEY_BACKSPACE)) {
        account.passCount --;
        if (account.passCount < 0)
            account.passCount = 0;
        account.pass[account.passCount] = '\0';
    }
}

void storeAccount (Account &account) {
    fstream f;
    f.open("resources/file/Account.txt", ios::out | ios::app);
    f << account.name << " " << '|' << " " << account.pass << '\n';
    f.close();
}

bool isExistedUsername (Account account) {
    fstream f;
    f.open("resources/file/Account.txt", ios::in);

    char s, name[20], pass[20], tmp[2];
    string t;

    //Get the first line that's not neccessary
    getline(f, t, '\n');
    stringstream ss(t);
    ss >> name;
    ss >> s;
    ss >> pass;

    while (!f.eof()) {
        getline(f, t, '\n');
        stringstream ss(t);

        ss >> name;
        ss >> s;
        ss >> pass;

        if (name[0] != '\0' && pass[0] != '\0')
            if (strcmp(name, account.name) == 0) {
                f.close();
                return 1;
            }
    }

    f.close();
    return 0;
}

bool isCorrectSigIn (Account account) {
    fstream f;
    f.open("resources/file/Account.txt", ios::in);

    char s, name[20], pass[20], tmp[2];
    string t;

    // Get the first line that's not neccessary
    getline(f, t, '\n');
    stringstream ss(t);
    ss >> name;
    ss >> s;
    ss >> pass;

    while (!f.eof()) {
        getline(f, t, '\n');

        stringstream ss(t);

        ss >> name;
        ss >> s;     
        ss >> pass;

        if (name[0] != '\0' && pass[0] != '\0')
            if (strcmp(name, account.name) == 0 && strcmp(pass, account.pass) == 0) {
                f.close();
                return 1;
            }
    }

    f.close();
    return 0;
}

char *modifyName (Account& account) {
    char *tmp;
    tmp = NULL;

    if (account.nameCount != 0) {
        if (account.nameCount > 15) {
            short i;
            for (i = 11; i < 14; i ++)
                account.name[i] = '.';
            account.name[14] = '\0';
        }

        tmp = new char[strlen(account.name) + 1];
        strcpy(tmp, account.name);
    }

    else {
        tmp = new char[strlen("Input username here") + 1];
        strcpy(tmp, "Input username here");
    }

    return tmp;
}

char *modifyPass(Account& account) {
    char *tmp;
    tmp = NULL;

    if (account.passCount != 0) {
        if (account.passCount > 15) {
            short i;
            for (i = 11; i < 14; i ++)
                account.pass[i] = '.';
            account.pass[14] = '\0';
        }

        tmp = new char[strlen(account.pass) + 1];
        strcpy(tmp, account.pass);
    }

    else {
        tmp = new char[strlen("Input password here") + 1];
        strcpy(tmp, "Input password here");
    }

    return tmp;
}

short checkValidUsername(Account account) {
    short i;

    // Check if there is nothing
    if (account.nameCount == 0)
        return 1;

    // Check if more than 16 letters
    if (account.nameCount > 16)
        return 2;

    // Check if there is any space
    for (i = 0; i < account.nameCount; i ++)
        if (account.name[i] == ' ')
            return 3;

    if (isExistedUsername(account))
        return 4;
    
    return 5;
}

short checkValidPassWord (Account account) {
    short i;

    // Check if there is nothing
    if (account.passCount == 0)
        return 1;

    // Check if more than 16 letters
    if (account.passCount > 16)
        return 2;

    // Check if there is only space
    for (i = 0; i < account.passCount; i ++)
        if (account.pass[i] == ' ')
            return 3;

    return 4;
}

char *modifyCommandUsername(Account& account) {
    char *tmp;
    tmp = NULL;
    short check = checkValidUsername(account);

    switch (check) {
        //No input
        case 1:
            tmp = new char[strlen("Username should have at least one letter alphabet") + 1];
            strcpy(tmp, "Username should have at least one letter alphabet");
            break;

        case 2:
            tmp = new char[strlen("Username should have no more than 15 letters") + 1];
            strcpy(tmp, "Username should have no more than 15 letters");
            break;

        case 3:
            tmp = new char[strlen("Username mustn't have space") + 1];
            strcpy(tmp, "Username mustn't have space");
            break;

        case 4:
            tmp = new char[strlen("Existed Username") + 1];
            strcpy(tmp, "Existed Username");
            break;

        case 5:
            tmp = new char[strlen("Valid Username") + 1];
            strcpy(tmp, "Valid Username");
            break;
    }

    return tmp;
}

char *modifyCommandPassword (Account& account) {
    char *tmp;
    tmp = NULL;
    short check = checkValidPassWord(account);

    switch (check) {
        case 1:
            tmp = new char[strlen("Password should have at least one letter alphabet") + 1];
            strcpy(tmp, "Passowrd should have at least one letter alphabet");
            break;
            
        case 2:
            tmp = new char[strlen("Password should have no more than 15 letters") + 1];
            strcpy(tmp, "Password should have no more than 15 letters");
            break;

        case 3:
            tmp = new char[strlen("Password mustn't have space") + 1];
            strcpy(tmp, "Password mustn't have space");
            break;

        case 4:
            tmp = new char[strlen("Valid Password") + 1];
            strcpy(tmp, "Valid Password");
            break;
    }

    return tmp;
}

char *modifyCommandForSignUp(Account& account) {
    char *tmp;
    tmp = NULL;

    short checkName = checkValidUsername(account);
    short checkPass = checkValidPassWord(account);

    if (checkName == 4) {
        tmp = new char[strlen("Existed Account") + 1];
        strcpy(tmp, "Existed Account");
    }

    else if (checkName == 1 && checkPass == 1) {
        tmp = new char[strlen("Please input username and password") + 1];
        strcpy(tmp, "Please input username and password");
    }

    else if (checkName == 1) {
        tmp = new char[strlen("Remember to input username") + 1];
        strcpy(tmp, "Remember to input username");
    }

    else if (checkPass == 1) {
        tmp = new char[strlen("Remember to input password") + 1];
        strcpy(tmp, "Remember to input password");
    }

    else if (checkName == 5 && checkPass == 4) {
        tmp = new char[strlen("Valid username and password") + 1];
        strcpy(tmp, "Valid username and password");
    }

    else if (checkName == 5) {
        tmp = new char[strlen("Invalid password") + 1];
        strcpy(tmp, "Invalid password");
    }

    else if (checkPass == 4) {
        tmp = new char[strlen("Invalid username") + 1];
        strcpy(tmp, "Invalid username");
    }

    else {
        tmp = new char[strlen("Invalid account") + 1];
        strcpy(tmp, "Invalid account");
    }

    return tmp;
}

char *modifyCommandForSignIn(Account &account)
{
    char *tmp;
    tmp = NULL;

    int checkName = checkValidUsername(account);
    int checkPass = checkValidPassWord(account);

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
    else if ((checkName == 5 || checkName == 4) && checkPass == 4)
    {
        if (isCorrectSigIn(account) == 0)
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
    else if (checkName == 5)
    {
        tmp = new char[strlen("Invalid password") + 1];
        strcpy(tmp, "Invalid password");
    }
    else if (checkPass == 4 && checkName != 4)
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

void addHead(Account *&pHead, Account account) {
    Account *tmp = new Account;

    // Save Username first
    strcpy(tmp -> name, account.name);
    tmp -> nameCount = account.nameCount;

    // Save PassWord
    strcpy(tmp -> pass, account.pass);
    tmp -> passCount = account.passCount;

    tmp -> next = NULL;

    // Delete name and pass after delete
    account.nameCount = 0;
    account.passCount = 0;
    account.name[0] = '\0';
    account.pass[0] = '\0';

    if (pHead == NULL)
        pHead = tmp;
    else
    {
        tmp -> next = pHead;
        pHead = tmp;
    }
}

void deleteList(Account *&pHead) {
    Account *cur;
    while (pHead != NULL)
    {
        cur = pHead;
        pHead = pHead->next;

        cur -> nameCount = 0;
        cur -> passCount = 0;

        cur -> name[0] = '\0';
        cur -> pass[0] = '\0';

        delete cur;
        cur = NULL;
    }
}

Scene SignUpScene::draw (bool& isSigned, char*& username) {
    // Draw Background image
    ClearBackground(BLACK);
    DrawTexturePro(background, {0, 0, 1792.0f, 1024.0f}, {0, 0, float(WinWdith), float(WinHeight)}, {0, 0}, 0.0f, WHITE);

    short i;
    // Draw Game Title
    for (i = 0; i < 2; i++) {
        DrawRectangleRec(title[i].border, title[i].BorderColor);
        DrawText(title[i].content, title[i].pos.x, title[i].pos.y, title[i].FontSize, title[i].FontColor);
    }

    //---Selector at this is different in movements---
    if (IsKeyPressed(KEY_LEFT))
        selector.x --;
    else if (IsKeyPressed(KEY_RIGHT))
        selector.x ++;
    else if (IsKeyPressed(KEY_UP))
        selector.y --;
    else if (IsKeyPressed(KEY_DOWN))
        selector.y ++;

    if (selector.y == 2) {
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

    if (selector.y > 2) {
        if (selector.x == 0)
            selector.y = 2;
        if (selector.x == 1)
            selector.y = 0;
    }

    if (selector.x == 1 && selector.y == 0) {
        input[0].BorderColor = WHITE;
        inputAccount(account);
        delete[] command.content;
        command.content = NULL;
        command.content = modifyCommandUsername(account);
    }
    else
        input[0].BorderColor = DarkCyanTrans;

    if (selector.x == 1 && selector.y == 1) {
        input[1].BorderColor = WHITE;
        inputPass(account);
        delete[] command.content;
        command.content = NULL;
        command.content = modifyCommandPassword(account);
    }
    else
        input[1].BorderColor = DarkCyanTrans;

    //Sign Up button
    if (selector.y == 2 && selector.x == 0) {
        confirm[0].FontColor = DarkCyanTrans;
        confirm[0].BorderColor = WHITE;
        delete[] command.content;
        command.content = NULL;
        command.content = modifyCommandForSignUp(account);
        if (IsKeyPressed(KEY_ENTER) && checkValidUsername(account) == 5 && checkValidPassWord(account) == 4 && !isExistedUsername(account)) {
            username = new char[strlen(account.name) + 1];
            strcpy (username, account.name);
            storeAccount (account);
            isSigned = 1;
            set = 0;
            selector.x = 0, selector.y = 0;
            return SIGNUP;
        }
    }
    else {
        confirm[0].FontColor = WHITE;
        confirm[0].BorderColor = DarkCyanTrans;
    }

    //Back to Menu button
    if (selector.y == 2 && selector.x == 1) {
        delete[] command.content;
        command.content = NULL;

        confirm[1].FontColor = DarkCyanTrans;
        confirm[1].BorderColor = WHITE;
        if (IsKeyPressed(KEY_ENTER)) {
            set = 0;
            isSigned = 0;
            selector.x = 0, selector.y = 0;
            return SIGNUP;
        }
    }
    else {
        confirm[1].FontColor = WHITE;
        confirm[1].BorderColor = DarkCyanTrans;
    }

    //Draw constant "Username" and "PassWord"
    for (i = 0; i < 2; i++) {
        DrawRectangleRec(constant[i].border, constant[i].BorderColor);
        DrawText(constant[i].content, constant[i].pos.x, constant[i].pos.y, constant[i].FontSize, constant[i].FontColor);
    }
    //Draw constant input boxes
    for (i = 0; i < 2; i++) {
        delete[] input[i].content;
        input[i].content = NULL;
    }

    input[0].content = modifyName(account);
    input[1].content = modifyPass(account);
    for (i = 0; i < 2; i++) {
        DrawRectangleRec(input[i].border, input[i].BorderColor);
        DrawText(input[i].content, input[i].pos.x, input[i].pos.y, input[i].FontSize, input[i].FontColor);
    }

    command.ContentLength = float(MeasureText(command.content, command.FontSize));
    command.pos.x = (float(WinWdith) - command.ContentLength) / 2;
    DrawText(command.content, command.pos.x, command.pos.y, command.FontSize, command.FontColor);

    for (i = 0; i < 2; i++) {
        DrawRectangleRec(confirm[i].border, confirm[i].BorderColor);
        DrawText(confirm[i].content, confirm[i].pos.x, confirm[i].pos.y, confirm[i].FontSize, confirm[i].FontColor);
    }

    return SIGNUP;
}


Scene SignInScene::draw(bool &isSigned, char* &username)
{
    // Draw Background image
    ClearBackground(BLACK);
    DrawTexturePro(background, {0, 0, 1792.0f, 1024.0f}, {0, 0, float(WinWdith), float(WinHeight)}, {0, 0}, 0.0f, WHITE);

    short i;
    // Draw Game Title
    for (i = 0; i < 2; i++) {
        DrawRectangleRec(title[i].border, title[i].BorderColor);
        DrawText(title[i].content, title[i].pos.x, title[i].pos.y, title[i].FontSize, title[i].FontColor);
    }

    //---Selector at this is different in movements---
    if (IsKeyPressed(KEY_LEFT))
        selector.x --;
    else if (IsKeyPressed(KEY_RIGHT))
        selector.x ++;
    else if (IsKeyPressed(KEY_UP))
        selector.y --;
    else if (IsKeyPressed(KEY_DOWN))
        selector.y ++;

    if (selector.y == 2) {
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

    if (selector.y > 2) {
        if (selector.x == 0)
            selector.y = 2;
        if (selector.x == 1)
            selector.y = 0;
    }

    if (selector.x == 1 && selector.y == 0) {
        input[0].BorderColor = WHITE;
        inputAccount(account);
        delete[] command.content;
        command.content = NULL;
        command.content = modifyCommandUsername(account);
    }
    else
        input[0].BorderColor = DarkCyanTrans;

    if (selector.x == 1 && selector.y == 1) {
        input[1].BorderColor = WHITE;
        inputPass(account);
        delete[] command.content;
        command.content = NULL;
        command.content = modifyCommandPassword(account);
    }
    else
        input[1].BorderColor = DarkCyanTrans;

    //Sign Up button
    if (selector.y == 2 && selector.x == 0) {
        confirm[0].FontColor = DarkCyanTrans;
        confirm[0].BorderColor = WHITE;
        delete[] command.content;
        command.content = NULL;
        command.content = modifyCommandForSignIn(account);
        if (IsKeyPressed(KEY_ENTER) && (checkValidUsername(account) == 5 || checkValidUsername(account) == 4) && checkValidPassWord(account) == 4 && isCorrectSigIn(account) == 1) {
            username = new char[strlen(account.name) + 1];
            strcpy (username, account.name);
            //storeAccount (account);
            isSigned = 1;
            set = 0;
            selector.x = 0, selector.y = 0;
            return SIGNIN;
        }
    }
    else {
        confirm[0].FontColor = WHITE;
        confirm[0].BorderColor = DarkCyanTrans;
    }

    //Back to Menu button
    if (selector.y == 2 && selector.x == 1) {
        delete[] command.content;
        command.content = NULL;

        confirm[1].FontColor = DarkCyanTrans;
        confirm[1].BorderColor = WHITE;
        if (IsKeyPressed(KEY_ENTER)) {
            set = 0;
            isSigned = 0;
            selector.x = 0, selector.y = 0;
            return SIGNIN;
        }
    }
    else {
        confirm[1].FontColor = WHITE;
        confirm[1].BorderColor = DarkCyanTrans;
    }

    //Draw constant "Username" and "PassWord"
    for (i = 0; i < 2; i++) {
        DrawRectangleRec(constant[i].border, constant[i].BorderColor);
        DrawText(constant[i].content, constant[i].pos.x, constant[i].pos.y, constant[i].FontSize, constant[i].FontColor);
    }
    //Draw constant input boxes
    for (i = 0; i < 2; i++) {
        delete[] input[i].content;
        input[i].content = NULL;
    }

    input[0].content = modifyName(account);
    input[1].content = modifyPass(account);
    for (i = 0; i < 2; i++) {
        DrawRectangleRec(input[i].border, input[i].BorderColor);
        DrawText(input[i].content, input[i].pos.x, input[i].pos.y, input[i].FontSize, input[i].FontColor);
    }

    command.ContentLength = float(MeasureText(command.content, command.FontSize));
    command.pos.x = (float(WinWdith) - command.ContentLength) / 2;
    DrawText(command.content, command.pos.x, command.pos.y, command.FontSize, command.FontColor);

    for (i = 0; i < 2; i++) {
        DrawRectangleRec(confirm[i].border, confirm[i].BorderColor);
        DrawText(confirm[i].content, confirm[i].pos.x, confirm[i].pos.y, confirm[i].FontSize, confirm[i].FontColor);
    }

    return SIGNIN;
}