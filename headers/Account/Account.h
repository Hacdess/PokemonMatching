#pragma once
#include "../items.h"
#include "../Moving.h"
#include "../GamePlay/Level.h"
#include<cstring>
#include<fstream>
#include<sstream>

#define MAX_INPUT_CHARS 21

struct Account
{
    char name[MAX_INPUT_CHARS] = "0";
    char pass[MAX_INPUT_CHARS] = "\0";
    int nameCount = 0;
    int passCount = 0;

    Account * next;  //Create singly linked list
};

struct AccountScene {
    Texture2D background;
    TextBox title[2];
    TextBox loginbox[2]; // The word Username and PassWord
    TextBox loginInput[2]; // The box for input
    TextBox loginConfirm[2]; // Login and Exit
    TextBox loginCommand[1]; // the warning that input wrong or already have the account
    Selector2D selector {0, 0};

    //Sign Up
    void setupSignUp();
    Status drawSignUp(bool& isSigned, Account &a);

    //Sign In
    void setupSignIn();
    Status drawSignIn(bool& isSigned, Account &a);

    void inputAccount(Account &a);
    void inputPass(Account &a);


    //Hàm xử lý File
    void writeFileAccount(Account &a);
    bool readFileAccountAndCheck(Account a);

    //Hàm xử lí Username && Password: Tối đa 15 kí tự
    char* modifyName(Account a);
    char* modifyPass(Account a);
    int checkVaildUsername(Account a); //Có nhiều trường hợp IsnValid khác nhau
    int checkValidPassWord(Account a);
   
    //Hàm chỉnh dòng Commnad
    char* modifyCommandUsername(Account a);
    char* modifyCommandPassword(Account a);
    char* modifyCommandForSignUp(Account a);

    //Some fuctions to work on Linked List
    void addHead(Account* &pHead, Account a);
    void deleteList(Account* &pHead);

};