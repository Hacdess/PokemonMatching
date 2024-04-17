#pragma once
#include "../Moving.h"
#include "../GamePlay/Level.h"
#include "../GamePlay/Music.h"

#define MAX_INPUT_CHARS 21 //Max Length of input characters is 20 (21st for '\0')

struct Account {
    char name[MAX_INPUT_CHARS] = "\0"; //A variable to contain username
    char pass[MAX_INPUT_CHARS] = "\0"; //A variable to contain password
    short nameCount = 0; //Name length
    short passCount = 0; //Pass length

    Account * next;  //Create singly linked list
};

struct SignUpScene {
    bool set = 0;
    Account account;
    Texture2D background;
    TextBox title[2]; //Game name
    TextBox constant[2]; // The word "Username" and "PassWord" - they're constant
    TextBox input[2]; // The box for input
    TextBox confirm[2]; // Login and Exit
    TextBox command; // the warning that input wrong or already have the account
    Selector2D selector = {0, 0}; //A tool to move and control cursor

    void setup(); //Get all the neccessay contents and the locations of the textboxes

    //Draw the shape of the textboxes, draw the words, fill colors to all of them and add music and sounds
    Scene draw (bool& isSigned, char*& username, gameMusic& musicAndSound); 
};

struct SignInScene {
    bool set = 0;
    Account account;
    Texture2D background;
    TextBox title[2]; //Game name
    TextBox constant[2]; // The word "Username" and "PassWord" - they're constant
    TextBox input[2]; // The box for input
    TextBox confirm[2]; // Login and Exit
    TextBox command; // the warning that input wrong or already have the account
    Selector2D selector = {0, 0};

    void setup(); //Get all the neccessay contents and the locations of the textboxes

    //Draw the shape of the textboxes, draw the words, fill colors to all of them and add music and sounds
    Scene draw(bool& isSigned, char* & username, gameMusic& musicAndSound); 
};

//Input function
void inputAccount(Account& account);
void inputPass(Account &account);

//Working with file Account.txt
void storeAccount (Account &account);
bool isExistedUsername (Account account);
bool checkCorrectPassword(Account account);
bool isCorrectSigIn (Account account);

//Fuctions dealing with Username && Password: Max 15 characters
char* modifyName(Account& account);
char* modifyPass(Account& account);
short checkValidUsername(Account account); //Many invalid cases
short checkValidPassWord(Account account);
   
//Functions adjust the messages 
char* modifyCommandUsernameForSignUp(Account& account);
char* modifyCommandUsernameForSignIn(Account& account);
char* modifyCommandPasswordForSignUp(Account& account);
char* modifyCommandPasswordForSignIn(Account& account);
char* modifyCommandForSignUp(Account& account);
char* modifyCommandForSignIn(Account& account);

