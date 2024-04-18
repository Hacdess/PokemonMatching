#pragma once
#include "Moving.h"

struct ScoreBoard {
    //Border is constant
    Rectangle border;
    const Color background = BlackTrans;

    //Read in setup function for more information
    TextBox Title, TimeText, Player[2], ScoreText[2], Guide[6], Message[2];
    short ScoreNum, ScoreNum2;

    Time PlayTime;
    float markTime = 0;

    //Health Point illustrated as health bar
    float HealthFull = float (WinHeight) / 3; //Size of full Health
    //Player has 5 health points meaning that player has 5 chances for wrong answer
    float HealthUnit = HealthFull / 5; 
    //Both of them can be reused

    //At first, players have 5 health points
    short health, health2;

    //The red one at the back
    Rectangle HP_Bar[2];
    Color HP_Bar_Color = RED;

    //The green one showing your current health
    Rectangle HP[2];
    Color HP_Color = GREEN;

    void updateTimeText();  //Update the time to make it run correctly like a real clock

    void setup (const bool& isDual, const char* username); //Get all the neccessay contents and the locations of the textboxes

    bool isUpdatedPlayerName = 0;   //Update the players' username if they use accounts to play
    void updatePlayer(char* name);  //Update the players' username after chosing challenges (Only in Single mode)

    void updateHP(const bool& isDual); //Update the players' HP whenever they do wrong matching
    void updateScoreText(const bool& isDual); //Update the players' score whenever they match or use hints

    //Adjust the verifying message for the four types of matching 
    void updateMessage1(const Selector2D& pokemon1, const Selector2D& pokemon2, const MatchingType& MatchType);   
    void updateMessage2(const Selector2D& pokemon1, const Selector2D& pokemon2, const MatchingType& MatchType);
    
    void draw(const bool& isDual); //Draw the shape of the textbox, draw the words and fill colors to all of them
};