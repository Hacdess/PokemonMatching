#pragma once
#include "../Moving.h"

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

    void updateTimeText();

    void setup (const bool& isDual, const char* username);

    bool isUpdatedPlayerName = 0;
    void updatePlayer(char* name);

    void updateHP(const bool& isDual);
    void updateScoreText(const bool& isDual);

    void updateMessage1(const Selector2D& pokemon1, const Selector2D& pokemon2, const MatchingType& MatchType);
    void updateMessage2(const Selector2D& pokemon1, const Selector2D& pokemon2, const MatchingType& MatchType);
    
    void draw(const bool& isDual);
};