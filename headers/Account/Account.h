#pragma once
#include "../items.h"
#include "../Moving.h"
#include "../GamePlay/Level.h"
struct Account
{
    char* name;
    char* pass;
    Account* aNext;
};

struct AccountScene {
    Texture2D background;
    TextBox title[2];
    TextBox login[2][2]; //User and PassWord 
    TextBox buttopn[1]; //The login button
    TextBox reply[1];  // Answer if the user/password is correct or not  
    Selector2D selector = {0, 0};

    void setup();
    Status draw(bool& isSigned);
    void saveAccount();
};