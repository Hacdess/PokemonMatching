#pragma once
#include "../Moving.h"

struct ScoreBoard {
    //Border is constant
    Rectangle border;
    const Color background = BlackTrans;

    //Read in setup function for more information
    TextBox Title, TimeText, Player, ScoreText, Guide[3], Message;
    short ScoreNum;

    //Health Point illustrated as health bar
    float HealthFull = float (WinHeight) / 3; //Size of full Health
    //Player has 5 health points meaning that player has 5 chances for wrong answer
    float HealthUnit = HealthFull / 5; 
    //At first, player has 5 health points
    short health;

    //The red one at the back
    Rectangle HP_Bar;
    Color HP_Bar_Color = RED;

    //The green one showing your current health
    Rectangle HP;
    Color HP_Color = GREEN;

    Time PlayTime;
    float markTime = 0;
    void updateTimeText();

    void setup(const char* username);

    bool isUpdatedPlayerName = 0;
    void updatePlayer(char* name);

    void updateHP();
    void updateScoreText();

    bool StillMatchable = 1;
    void updateMessage(const Selector2D& pokemon1, const Selector2D& pokemon2, const MatchingType& MatchType);
    void draw();
};