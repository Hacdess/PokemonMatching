#pragma once
#include "Moving.h"
#include "Music.h"

struct ResultScene {
    bool isSet = 0;                                                         //A variable to determine when to show up the game verifying message
    bool isVictory = 0;                                                     //A variable to know whether the player win or lose the game
    float markTime;                                                         //A variable to store the time
    const Rectangle background = {0, 0, float(WinWdith), float(WinHeight)}; //Set locations to four corners of the game verifying message
    const Color BackgrounColor = DARKGRAY;                                  //The game verifying message 's background color
    TextBox result, player[2], time, score[2], message;                     //The elements on the game verifying message

    void setup(const bool& isDual);                                         //Get all the neccessay contents and the locations of the textboxes

    //Draw the shape of the textboxes, draw the words, fill colors to all of them and add music and sounds
    Scene draw(GameAction& action, const bool& isDual, gameMusic& musicAndSound); 
};