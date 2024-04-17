#include "../headers/MenuScreen/Account.h"


void SignUpScene::setup() {
    set = 1;

    //Set the username and password
    account.nameCount = 0;
    account.name[account.nameCount] = '\0';
    account.passCount = 0;
    account.pass[account.passCount] = '\0';

    // Get Background
    Image img = LoadImage("resources/img/background/background.png");
    background = LoadTextureFromImage(img);
    UnloadImage(img);

    // Store Title
    addText (title[0].content, "POKEMON");
    addText (title[1].content, "MATCHING");
    title[0].FontColor = RED;
    title[1].FontColor = YELLOW;

    float startY = float(WinHeight) / 4,
          startX = float(WinWdith) / 5,
          FontSize = float(WinHeight) / 8,
          spacing = FontSize / 5;

    short i;
    for (i = 0; i < 2; i++)
    {
        title[i].FontSize = FontSize;
        title[i].BorderColor = BlackTrans;

        title[i].ContentLength = float(MeasureText(title[i].content, title[i].FontSize));
        title[i].pos = {(float(WinWdith) - title[i].ContentLength) / 2, startY};
        title[i].border = {startX, startY - spacing, startX * 3, title[i].FontSize + spacing * 1.5f};

        startY = startY + title[i].FontSize + spacing * 1.5f;
    }

    //----Setup drawing things----
    // Constant Usernam and Password boxes
    addText (constant[0].content, "Username");
    addText (constant[1].content, "Password");

    // Input boxes
    addText (input[0].content, "Input username here");
    addText (input[1].content, "Input password here");\

    // Sign Up and Exit buttons
    addText (confirm[0].content, "Sign Up");
    addText (confirm[1].content, "Back");

    // Warning
    addText (command.content, "Please input username and password");

    FontSize = FontSize * 8 / 40;
    startY = startY + FontSize,

    FontSize = float(WinHeight) / 20,
    spacing = FontSize / 8;
    float SignUpSpace = float(WinWdith) / 5,
          SignUpWidth = SignUpSpace - 4.0f * spacing,
          SignUpHeight = float(WinHeight) / 15;
    startX = SignUpSpace;

    // Get the parameters of the constant boxes which contain the word "Username" and "Password"
    for (i = 0; i < 2; i++) {
        constant[i].FontSize = FontSize;
        constant[i].BorderColor = DarkCyanTrans;
        constant[i].FontColor = WHITE;

        constant[i].ContentLength = float(MeasureText(constant[i].content, constant[i].FontSize));
        constant[i].border = {startX + spacing * 2.0f, startY + (spacing + SignUpHeight) * i, SignUpWidth, SignUpHeight};
        constant[i].pos = {startX + (SignUpSpace - constant[i].ContentLength) / 2, startY + (SignUpHeight - constant[i].FontSize) / 2 + (spacing + SignUpHeight) * i};
    }

    // Get the parameters of the input boxes
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
    for (i = 0; i < 2; i++)
    {
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

    //Set the username and password
    account.nameCount = 0;
    account.name[account.nameCount] = '\0';
    account.passCount = 0;
    account.pass[account.passCount] = '\0';
    
    // Get Background
    Image img = LoadImage("resources/img/background/background.png");
    background = LoadTextureFromImage(img);
    UnloadImage(img);

    // Store Title
    addText (title[0].content, "POKEMON");
    addText (title[1].content, "MATCHING");
    title[0].FontColor = RED;
    title[1].FontColor = YELLOW;

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
    // Constant Usernam and Password boxes
    addText (constant[0].content, "Username");
    addText (constant[1].content, "Password");

    // Input boxes
    addText (input[0].content, "Input username here");
    addText (input[1].content, "Input password here");\

    // Sign Up and Exit buttons
    addText (confirm[0].content, "Sign In");
    addText (confirm[1].content, "Back");

    // Warning
    addText (command.content, "Please input username and password");

    FontSize = FontSize * 8 / 40;
    startY = startY + FontSize,

    FontSize = float(WinHeight) / 20,
    spacing = FontSize / 8;
    float SignInSpace = float(WinWdith) / 5,
          SignInWidth = SignInSpace - 4.0f * spacing,
          SignInHeight = float(WinHeight) / 15;
    startX = SignInSpace;

    // Get the parameters of the constant boxes which contain the word "Username" and "Password"
    for (i = 0; i < 2; i++)
    {
        constant[i].FontSize = FontSize;
        constant[i].BorderColor = DarkCyanTrans;
        constant[i].FontColor = WHITE;

        constant[i].ContentLength = float(MeasureText(constant[i].content, constant[i].FontSize));
        constant[i].border = {startX + spacing * 2.0f, startY + (spacing + SignInHeight) * i, SignInWidth, SignInHeight};
        constant[i].pos = {startX + (SignInSpace - constant[i].ContentLength) / 2, startY + (SignInHeight - constant[i].FontSize) / 2 + (spacing + SignInHeight) * i};
    }

    // Get the parameters of the input boxes
    startX += spacing + SignInWidth;
    for (i = 0; i < 2; i++)
    {
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
    for (i = 0; i < 2; i++)
    {
        confirm[i].FontSize = FontSize;
        confirm[i].BorderColor = DarkCyanTrans;
        confirm[i].FontColor = WHITE;

        confirm[i].ContentLength = float(MeasureText(confirm[i].content, confirm[i].FontSize));
        confirm[i].border = {startX + spacing * 2.0f, startY, SignInWidth, SignInHeight};
        confirm[i].pos = {startX + (SignInSpace - confirm[i].ContentLength) / 2, startY + (SignInHeight - confirm[i].FontSize) / 2};
        startX += spacing + SignInWidth;
    }
}

//A function that allows player to input username
void inputAccount(Account &account) {
    
    //Allow player to input from the keyboard
    short key = GetCharPressed();

    //Get the key until the player don't press anymore or press the keys that are not allowed
    while (key > 0)
    {
        if (32 <= key && key <= 126)
        {
            account.name[account.nameCount] = (char)key;
            account.nameCount++;
            if (account.nameCount > 20)
                account.nameCount = 20;
            account.name[account.nameCount] = '\0';
        }
        key = GetCharPressed();
    }

    //Check if player press KEY_BACKSPACE to delete one key that is nereast to the input cursor
    if (IsKeyPressed(KEY_BACKSPACE))
    {
        account.nameCount--;
        if (account.nameCount < 0)
            account.nameCount = 0;
        account.name[account.nameCount] = '\0';
    }
}

//A function that allows player to input password
void inputPass(Account &account) {
    //Allow player to input from the keyboard
    short key = GetCharPressed();

    //Get the key until the player don't press anymore or press the keys that are not allowed
    while (key > 0)
    {
        if (32 <= key && key <= 126)
        {
            account.pass[account.passCount] = (char)key;
            account.passCount++;
            if (account.passCount > 20)
                account.passCount = 20;
            account.pass[account.passCount] = '\0';
        }
        key = GetCharPressed();
    }

    //Check if player press KEY_BACKSPACE to delete one key that is nereast to the input cursor
    if (IsKeyPressed(KEY_BACKSPACE))
    {
        account.passCount--;
        if (account.passCount < 0)
            account.passCount = 0;
        account.pass[account.passCount] = '\0';
    }
}

//A function that stores account to the Account.txt
void storeAccount(Account &account) {
    fstream f;

    //Open file Account.txt
    f.open("resources/file/Account.txt", ios::out | ios::app);

    //Get the account 
    f << account.name << " " << '|' << " " << account.pass << '\n';

    //Close the file
    f.close();
}

//A function that checks whether the username is existed in the Account.txt
bool isExistedUsername(Account account) {
    fstream f;

    //Open file Account.txt
    f.open("resources/file/Account.txt", ios::in);

    char s, name[20], pass[20];
    string t;

    // Get the first line that's not neccessary
    getline(f, t, '\n');
    stringstream ss(t);
    ss >> name;
    ss >> s;
    ss >> pass;

    while (!f.eof())
    {
        //Get each line that contain one existed account
        getline(f, t, '\n');
        stringstream ss(t);

        ss >> name;
        ss >> s;
        ss >> pass;

        //Compare the usernames in the file Account.txt with the input username
        if (name[0] != '\0' && pass[0] != '\0')
            if (strcmp(name, account.name) == 0)
            {
                f.close();
                return 1;
            }
    }

    //Close the file
    f.close();
    return 0;
}
 
//A function that checks whether the password is correct with an existed account
bool checkCorrectPassword(Account account) {
    fstream f;

    //Opne the file Account.txt
    f.open("resources/file/Account.txt", ios::in);

    char s, name[20], pass[20];
    string t;

    // Get the first line that's not neccessary
    getline(f, t, '\n');
    stringstream ss(t);
    ss >> name;
    ss >> s;
    ss >> pass;

    while (!f.eof()) {

        //Get each line that contain one existed account
        getline(f, t, '\n');
        stringstream ss(t);

        ss >> name;
        ss >> s;
        ss >> pass;

        //Compare the input username and the input password with these in the Account.txt
        if (name[0] != '\0' && pass[0] != '\0')
            if (strcmp(name, account.name) == 0 && strcmp(pass, account.pass) != 0) {
                f.close();
                return 0;
            }
    }

    //Close the file
    f.close();
    return 1;
}

//A function that check whether the input account is existed in file Account.txt
bool isCorrectSigIn(Account account) {
    fstream f;

    //Open the file Account.txt
    f.open("resources/file/Account.txt", ios::in);

    char s, name[20], pass[20];
    string t;

    // Get the first line that's not neccessary
    getline(f, t, '\n');
    stringstream ss(t);
    ss >> name;
    ss >> s;
    ss >> pass;

    while (!f.eof()) {

        //Get each line that contain one existed account
        getline(f, t, '\n');

        stringstream ss(t);

        ss >> name;
        ss >> s;
        ss >> pass;

        //Compare the input account with the existed account in file Account.txt
        if (name[0] != '\0' && pass[0] != '\0')
            if (strcmp(name, account.name) == 0 && strcmp(pass, account.pass) == 0) {
                f.close();
                return 1;
            }
    }

    f.close();
    return 0;
}

//A function that adjust the username if it has no character or has more than 15 characters
char *modifyName(Account &account) {
    char *tmp;
    tmp = NULL;

    //Check if the username have nothing
    if (account.nameCount != 0) {

        //Check if the username has more than 15 letters
        if (account.nameCount > 15) {
            short i;
            for (i = 11; i < 14; i++)
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

//A function that adjust the password if it has no character or more than 15 characters
char *modifyPass(Account &account) {
    char *tmp;
    tmp = NULL;

    //Check if password has nothing
    if (account.passCount != 0) {

        //Check if the username has more than 15 letters
        if (account.passCount > 15) {
            short i;
            for (i = 11; i < 14; i++)
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

//A function that check whether the username is right or wrong
short checkValidUsername(Account account) {
    short i;

    // Check if there is nothing
    if (account.nameCount == 0)
        return 1;

    // Check if more than 16 letters
    if (account.nameCount > 15)
        return 2;

    // Check if there is any space
    for (i = 0; i < account.nameCount; i++)
        if (account.name[i] == ' ')
            return 3;

    //Check if the username is existed in file Account.txt
    if (isExistedUsername(account))
        return 4;

    return 5;
}

//A function to check whether the password is right or wrong
short checkValidPassWord(Account account) {
    short i;

    // Check if there is nothing
    if (account.passCount == 0)
        return 1;

    // Check if more than 16 letters
    if (account.passCount > 16)
        return 2;

    // Check if there is only space
    for (i = 0; i < account.passCount; i++)
        if (account.pass[i] == ' ')
            return 3;

    if (checkCorrectPassword(account) == 0)
        return 4;

    return 5;
}

//A function that adjust the message whenever the username is right or wrong and how to correct it in Sign up screen
char *modifyCommandUsernameForSignUp(Account &account) {
    char *tmp;
    tmp = NULL;
    short check = checkValidUsername(account);

    switch (check) {
        // No input
        case 1:
            tmp = new char[strlen("Username should have at least one letter alphabet") + 1];
            strcpy(tmp, "Username should have at least one letter alphabet");
            break;

        //Username have more than 15 characters
        case 2:
            tmp = new char[strlen("Username should have no more than 15 letters") + 1];
            strcpy(tmp, "Username should have no more than 15 letters");
            break;

        //Username have at least one space
        case 3:
            tmp = new char[strlen("Username mustn't have space") + 1];
            strcpy(tmp, "Username mustn't have space");
            break;

        //Username has been used
        case 4:
            tmp = new char[strlen("Existed Username") + 1];
            strcpy(tmp, "Existed Username");
            break;

        //Username is right
        case 5:
            tmp = new char[strlen("Valid Username") + 1];
            strcpy(tmp, "Valid Username");
            break;
    }

    return tmp;
}

//A function that adjust the message whenever the username is right or wrong and how to correct it in Sign in screen
char *modifyCommandUsernameForSignIn(Account &account) {
    char *tmp;
    tmp = NULL;
    short check = checkValidUsername(account);

    switch (check) {
        // No input
        case 1:
            tmp = new char[strlen("Username should have at least one letter alphabet") + 1];
            strcpy(tmp, "Username should have at least one letter alphabet");
            break;

        //Username have more than 15 characters
        case 2:
            tmp = new char[strlen("Username should have no more than 15 letters") + 1];
            strcpy(tmp, "Username should have no more than 15 letters");
            break;

        //Username have at least one spaces
        case 3:
            tmp = new char[strlen("Username mustn't have space") + 1];
            strcpy(tmp, "Username mustn't have space");
            break;

        //Username has been used but it is valid in Sign in screen
        case 4:
        tmp = new char[strlen("Valid Username") + 1];
            strcpy(tmp, "Valid Username");
            break;
        
        //Username has right format but it doesn't exist in the Account.txt
        case 5:
            tmp = new char[strlen("Username didn't exist") + 1];
            strcpy(tmp, "Username didn't exist");
            break;
    }

    return tmp;
}

//A function that adjust the message whenever the password is right or wrong and how to correct it in Sign up screen
char *modifyCommandPasswordForSignUp(Account &account) {
    char *tmp;
    tmp = NULL;
    short check = checkValidPassWord(account);

    switch (check) {

        //No input
        case 1:
            tmp = new char[strlen("Password should have at least one letter alphabet") + 1];
            strcpy(tmp, "Passowrd should have at least one letter alphabet");
            break;

        //Password have more than 15 characters
        case 2:
            tmp = new char[strlen("Password should have no more than 15 letters") + 1];
            strcpy(tmp, "Password should have no more than 15 letters");
            break;

        //Password has at least one space
        case 3:
            tmp = new char[strlen("Password mustn't have space") + 1];
            strcpy(tmp, "Password mustn't have space");
            break;

        //Password is correct in Sign up screen
        case 4: case 5:
            tmp = new char[strlen("Valid Password") + 1];
            strcpy(tmp, "Valid Password");
            break;
    }

    return tmp;
}

//A function that adjust the message whenever the password is right or wrong and how to correct it in Sign in screen
char *modifyCommandPasswordForSignIn(Account &account) {
    char *tmp;
    tmp = NULL;
    short check = checkValidPassWord(account);

    switch (check) {

        //No input
        case 1:
            tmp = new char[strlen("Password should have at least one letter alphabet") + 1];
            strcpy(tmp, "Passowrd should have at least one letter alphabet");
            break;

        //Password have more than 15 characters
        case 2:
            tmp = new char[strlen("Password should have no more than 15 letters") + 1];
            strcpy(tmp, "Password should have no more than 15 letters");
            break;

        //Password have at least one space
        case 3:
            tmp = new char[strlen("Password mustn't have space") + 1];
            strcpy(tmp, "Password mustn't have space");
            break;

        //Correct input username but wrong password
        case 4:
            tmp = new char[strlen("Wrong password") + 1];
            strcpy(tmp, "Wrong password");
            break;

        //The password is correct
        case 5:
            tmp = new char[strlen("Valid Password") + 1];
            strcpy(tmp, "Valid Password");
            break;
    }

    return tmp;
}

//A function that adjust the message whether the account is right or wrong in the Sign up screen
char *modifyCommandForSignUp(Account &account) {
    char *tmp;
    tmp = NULL;

    //Check whether the username and password are right or wrong
    short checkName = checkValidUsername(account);
    short checkPass = checkValidPassWord(account);

    //Check if the username is existed in the file Account.txt
    if (checkName == 4) {
        tmp = new char[strlen("Existed Account") + 1];
        strcpy(tmp, "Existed Account");
    }

    //Check if there is no username and password input
    else if (checkName == 1 && checkPass == 1) {
        tmp = new char[strlen("Please input username and password") + 1];
        strcpy(tmp, "Please input username and password");
    }

    //Check if there is no username input
    else if (checkName == 1) {
        tmp = new char[strlen("Remember to input username") + 1];
        strcpy(tmp, "Remember to input username");
    }

    //Check if there is no password input
    else if (checkPass == 1) {
        tmp = new char[strlen("Remember to input password") + 1];
        strcpy(tmp, "Remember to input password");
    }

    //Check if the password has wrong format
    else if (checkName == 5 && checkPass <= 3) {
        tmp = new char[strlen("Invalid password") + 1];
        strcpy(tmp, "Invalid password");
    }

    //Check if the password has wrong format
    else if (checkPass > 3 && checkName != 5) {
        tmp = new char[strlen("Invalid username") + 1];
        strcpy(tmp, "Invalid username");
    }

    //Check if both username and password have wrong formats
    else if (checkName <= 4 && checkPass <= 3) {
        tmp = new char[strlen("Invalid account") + 1];
        strcpy(tmp, "Invalid account");
    }

    return tmp;
}

//A function that adjust the message whether the account is right or wrong in the Sign in screen
char *modifyCommandForSignIn(Account &account) {
    char *tmp;
    tmp = NULL;

    //Check if the username and password are right or wrong
    int checkName = checkValidUsername(account);
    int checkPass = checkValidPassWord(account);

    //Check if there is no input username and no input password
    if (checkName == 1 && checkPass == 1) {
        tmp = new char[strlen("Please input username and password") + 1];
        strcpy(tmp, "Please input username and password");
    }

    //Check if there is no input username
    else if (checkName == 1) {
        tmp = new char[strlen("Remember to input username") + 1];
        strcpy(tmp, "Remember to input username");
    }

    //Check if there is no input password
    else if (checkPass == 1) {
        tmp = new char[strlen("Remember to input password") + 1];
        strcpy(tmp, "Remember to input password");
    }

    //Check if the username or password is incorrect
    else if ((checkName > 3) && checkPass > 3) {
        if (!isCorrectSigIn(account)) {
            tmp = new char[strlen("Wrong password or username") + 1];
            strcpy(tmp, "Wrong password or username");
        }
    }

    //Check if the password has wrong format 
    else if (checkName > 3) {
        tmp = new char[strlen("Invalid password") + 1];
        strcpy(tmp, "Invalid password");
    }

    //Check if the username has wrong format
    else if (checkPass > 3) {
        tmp = new char[strlen("Invalid username") + 1];
        strcpy(tmp, "Invalid username");
    }

    //Check if both username and password have wrong formats
    else {
        tmp = new char[strlen("Invalid account") + 1];
        strcpy(tmp, "Invalid account");
    }

    return tmp;
}

//Draw the Sign up screen
Scene SignUpScene::draw(bool &isSigned, char *&username, gameMusic& musicAndSound) {
    // Draw Background image
    ClearBackground(BLACK);
    DrawTexturePro(background, {0, 0, float(background.width), float(background.height)}, {0, 0, float(WinWdith), float(WinHeight)}, {0, 0}, 0.0f, WHITE);

    short i;
    // Draw Game Title
    for (i = 0; i < 2; i++) {
        DrawRectangleRec(title[i].border, title[i].BorderColor);
        DrawText(title[i].content, title[i].pos.x, title[i].pos.y, title[i].FontSize, title[i].FontColor);
    }

    //---Selector at this is different in movements---
    if (IsKeyPressed(KEY_LEFT)){
        PlaySound(musicAndSound.moving);
        selector.x--;
    }
    else if (IsKeyPressed(KEY_RIGHT)){
        PlaySound(musicAndSound.moving);
        selector.x++;
    }
    else if (IsKeyPressed(KEY_UP)){
        PlaySound(musicAndSound.moving);
        selector.y--;
    }
    else if (IsKeyPressed(KEY_DOWN)){
        PlaySound(musicAndSound.moving);
        selector.y++;
    }

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

    //When the cursor at the username column
    if (selector.x == 1 && selector.y == 0) {
        input[0].BorderColor = WHITE;

        //Input username from keyboard
        inputAccount(account);
        if (IsKeyPressed(KEY_ENTER)){

            //Play press-button sound
            PlaySound(musicAndSound.pressButton);
            delete[] command.content;
            command.content = NULL;

            //Adjust the message
            command.content = modifyCommandUsernameForSignUp(account);
        }
    }
    else
        input[0].BorderColor = DarkCyanTrans;

    //When the cursor at the password column
    if (selector.x == 1 && selector.y == 1) {
        input[1].BorderColor = WHITE;

        //Input password from keyboard
        inputPass(account);

        if (IsKeyPressed(KEY_ENTER)) {

            //Play press-button sound
            PlaySound(musicAndSound.pressButton);
            delete[] command.content;
            command.content = NULL;

            //Adjust the message
            command.content = modifyCommandPasswordForSignUp(account);
        }
    }
    else
        input[1].BorderColor = DarkCyanTrans;

    //When the cursor at the Sign up button
    if (selector.y == 2 && selector.x == 0) {
        confirm[0].FontColor = DarkCyanTrans;
        confirm[0].BorderColor = WHITE;

        if (IsKeyPressed(KEY_ENTER)){
            delete[] command.content;
            command.content = NULL;

            //Adjust the message
            command.content = modifyCommandForSignUp(account);
        }

        if (IsKeyPressed(KEY_ENTER)) {

            //Check if the account is right
            if (checkValidUsername(account) == 5 && checkValidPassWord(account) > 3 && !isExistedUsername(account)){
            
            //Play correct-matching sound
            PlaySound(musicAndSound.correctMatching);

            username = new char[strlen(account.name) + 1];
            strcpy(username, account.name);

            //Save account in the file Account.txt
            storeAccount(account);
            isSigned = 1;
            set = 0;
            selector.x = 0, selector.y = 0;
            return SIGNUP;
            }
            else PlaySound(musicAndSound.wrongSign); //Play wrong-sign sound
        }
    }

    else {
        confirm[0].FontColor = WHITE;
        confirm[0].BorderColor = DarkCyanTrans;
    }

    // Back to Menu button
    if (selector.y == 2 && selector.x == 1) {
        delete[] command.content;
        command.content = NULL;

        confirm[1].FontColor = DarkCyanTrans;
        confirm[1].BorderColor = WHITE;
        if (IsKeyPressed(KEY_ENTER)) {

            //Play press-button sound
            PlaySound(musicAndSound.pressButton);
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

    // Draw constant "Username" and "PassWord"
    for (i = 0; i < 2; i++) {
        DrawRectangleRec(constant[i].border, constant[i].BorderColor);
        DrawText(constant[i].content, constant[i].pos.x, constant[i].pos.y, constant[i].FontSize, constant[i].FontColor);
    }
    // Draw constant input boxes
    for (i = 0; i < 2; i++) {
        delete[] input[i].content;
        input[i].content = NULL;
    }

    input[0].content = modifyName(account);  //Adjust the username
    input[1].content = modifyPass(account);  //Adjust the password

    //Draw the textbox for input
    for (i = 0; i < 2; i++) {
        DrawRectangleRec(input[i].border, input[i].BorderColor);
        DrawText(input[i].content, input[i].pos.x, input[i].pos.y, input[i].FontSize, input[i].FontColor);
    }

    //Draw the textbox contains messages
    command.ContentLength = float(MeasureText(command.content, command.FontSize));
    command.pos.x = (float(WinWdith) - command.ContentLength) / 2;
    DrawText(command.content, command.pos.x, command.pos.y, command.FontSize, command.FontColor);

    //Draw the Sign up button and Back button
    for (i = 0; i < 2; i++) {
        DrawRectangleRec(confirm[i].border, confirm[i].BorderColor);
        DrawText(confirm[i].content, confirm[i].pos.x, confirm[i].pos.y, confirm[i].FontSize, confirm[i].FontColor);
    }

    return SIGNUP;
}

//Draw the Sign in screen
Scene SignInScene::draw(bool &isSigned, char *&username, gameMusic& musicAndSound) {
    // Draw Background image
    ClearBackground(BLACK);
    DrawTexturePro(background, {0, 0, float(background.width), float(background.height)}, {0, 0, float(WinWdith), float(WinHeight)}, {0, 0}, 0.0f, WHITE);

    short i;
    // Draw Game Title
    for (i = 0; i < 2; i++) {
        DrawRectangleRec(title[i].border, title[i].BorderColor);
        DrawText(title[i].content, title[i].pos.x, title[i].pos.y, title[i].FontSize, title[i].FontColor);
    }

    //---Selector at this is different in movements---
    if (IsKeyPressed(KEY_LEFT)){
        PlaySound(musicAndSound.moving);
        selector.x--;
    }
    else if (IsKeyPressed(KEY_RIGHT)){
        PlaySound(musicAndSound.moving);
        selector.x++;
    }
    else if (IsKeyPressed(KEY_UP)){
        PlaySound(musicAndSound.moving);
        selector.y--;
    }
    else if (IsKeyPressed(KEY_DOWN)){
        PlaySound(musicAndSound.moving);
        selector.y++;
    }

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

    //When the cursor at the username column
    if (selector.x == 1 && selector.y == 0) {
        input[0].BorderColor = WHITE;

        //Input username from keyboard
        inputAccount(account);

        if (IsKeyPressed(KEY_ENTER)) {

            //Play press-button sound
            PlaySound(musicAndSound.pressButton);
            delete[] command.content;
            command.content = NULL;

            //Adjust message
            command.content = modifyCommandUsernameForSignIn(account);
        }
    }
    else
        input[0].BorderColor = DarkCyanTrans;

    //When the cursor at the password column
    if (selector.x == 1 && selector.y == 1) {
        input[1].BorderColor = WHITE;

        //Input password from keyboard
        inputPass(account);

        if (IsKeyPressed(KEY_ENTER)){

            //Play press-button sound
            PlaySound(musicAndSound.pressButton);
            delete[] command.content;
            command.content = NULL;

            //Adjust message
            command.content = modifyCommandPasswordForSignIn(account);
        }
    }
    else
        input[1].BorderColor = DarkCyanTrans;

    // Sign Up button
    if (selector.y == 2 && selector.x == 0) {
        confirm[0].FontColor = DarkCyanTrans;
        confirm[0].BorderColor = WHITE;

        if (IsKeyPressed(KEY_ENTER)){
            delete[] command.content;
            command.content = NULL;

            //Adjust message
            command.content = modifyCommandForSignIn(account);
        }

        if (IsKeyPressed(KEY_ENTER)) {

            //Check if the account is correct
            if ((checkValidUsername(account) == 5 || checkValidUsername(account) == 4) && checkValidPassWord(account) == 5 && isCorrectSigIn(account) == 1){
            
            //Play the correct-matching sound
            PlaySound(musicAndSound.correctMatching);
            username = new char[strlen(account.name) + 1];
            strcpy(username, account.name);
            account.name[0] = '\0';
            account.nameCount = 0;
            account.pass[0] = '\0';
            account.passCount = 0;
            isSigned = 1;
            set = 0;
            selector.x = 0, selector.y = 0;
            return SIGNIN;
            }
            else PlaySound(musicAndSound.wrongSign); //play the wrong-sign sound
        }
    }

    else {
        confirm[0].FontColor = WHITE;
        confirm[0].BorderColor = DarkCyanTrans;
    }

    // Back to Menu button
    if (selector.y == 2 && selector.x == 1) {
        delete[] command.content;
        command.content = NULL;

        confirm[1].FontColor = DarkCyanTrans;
        confirm[1].BorderColor = WHITE;
        if (IsKeyPressed(KEY_ENTER)) {

            //Play the press-button sound
            PlaySound(musicAndSound.pressButton);
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

    // Draw constant "Username" and "PassWord"
    for (i = 0; i < 2; i++) {
        DrawRectangleRec(constant[i].border, constant[i].BorderColor);
        DrawText(constant[i].content, constant[i].pos.x, constant[i].pos.y, constant[i].FontSize, constant[i].FontColor);
    }
    // Draw constant input boxes
    for (i = 0; i < 2; i++) {
        delete[] input[i].content;
        input[i].content = NULL;
    }

    input[0].content = modifyName(account); //Adjust the username
    input[1].content = modifyPass(account); //Adjust the password
    
    //Draw the input username and input password columns
    for (i = 0; i < 2; i++) {
        DrawRectangleRec(input[i].border, input[i].BorderColor);
        DrawText(input[i].content, input[i].pos.x, input[i].pos.y, input[i].FontSize, input[i].FontColor);
    }

    //Draw the textboxes for messages
    command.ContentLength = float(MeasureText(command.content, command.FontSize));
    command.pos.x = (float(WinWdith) - command.ContentLength) / 2;
    DrawText(command.content, command.pos.x, command.pos.y, command.FontSize, command.FontColor);

    //Draw the Sign in button and the Back button
    for (i = 0; i < 2; i++) {
        DrawRectangleRec(confirm[i].border, confirm[i].BorderColor);
        DrawText(confirm[i].content, confirm[i].pos.x, confirm[i].pos.y, confirm[i].FontSize, confirm[i].FontColor);
    }

    return SIGNIN;
}