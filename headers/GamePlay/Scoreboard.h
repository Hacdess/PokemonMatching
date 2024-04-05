#pragma once
#include "../Moving.h"

struct ScoreBoard {
    //Border is constant
    const Rectangle border = {
        float (WinWdith) / 3 * 2,
        float (WinHeight) / 4,
        float (WinHeight) / 2,
        float (WinHeight) / 2
    };
    const Color background = BlackTrans;

    //Read in setup function for more information
    TextBox Title, Player, ScoreText, Message;

    short ScoreNum;

    //Health Point illustrated as health bar
    float HealthFull = float (WinHeight) / 3; //Size of full Health
    //Player has 5 health points meaning that player has 5 chances for wrong answer
    float HealthUnit = HealthFull / 5; 
    //At first, player has 5 health points
    short health = 5;

    //The red one at the back
    Rectangle HP_Bar = {
        border.x + (border.width - HealthFull) / 2,
        0, // It will be changed after setting up
        HealthFull,
        HealthUnit
    };
    Color HP_Bar_Color = RED;

    //The green one showing your current health
    Rectangle HP = {HP_Bar.x, HP_Bar.y, HealthUnit * health, HP_Bar.height};
    Color HP_Color = GREEN;

    //Check if the player need help
    bool showHint;

    void setup();
    void updatePlayer(char* name);
    void updateHint();
    void draw();
};