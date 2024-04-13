#pragma once
#include "../Moving.h"
#include "../GamePlay/Level.h"

#define MAX_INPUT_CHARS 21 //Max Length of input characters is 20 (21st for '\0')

struct Account {
    char name[MAX_INPUT_CHARS] = "\0";
    char pass[MAX_INPUT_CHARS] = "\0";
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
    Selector2D selector = {0, 0};

    void setup();
    Scene draw (bool& isSigned, char*& username);
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

    void setup();
    Scene draw(bool& isSigned, char* & username);
};

//Input function
void inputAccount(Account& account);
void inputPass(Account &account);

//Hàm xử lý File
void storeAccount (Account &account);
bool isExistedUsername (Account account);
bool isCorrectSigIn (Account account);

//Fuctions dealing with Username && Password: Max 15 characters
char* modifyName(Account& account);
char* modifyPass(Account& account);
short checkValidUsername(Account account); //Many invalid cases
short checkValidPassWord(Account account);
   
//Hàm chỉnh dòng Commnad
char* modifyCommandUsernameForSignUp(Account& account);
char* modifyCommandUsernameForSignIn(Account& account);
char* modifyCommandPassword(Account& account);
char* modifyCommandForSignUp(Account& account);
char* modifyCommandForSignIn(Account& account);

//Some fuctions to work on Linked List
void addHead(Account* &pHead, Account account);
void deleteList(Account* &pHead);