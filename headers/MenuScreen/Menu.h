#pragma once
#include "../Moving.h"
#include "../GamePlay/Level.h"
#include "../GamePlay/Game.h"
#include "Account.h"
#include "Leaderboard.h"
#include "Guide.h"
#include "../GamePlay/Music.h"

struct MenuScene {
    bool isChanged = 0;             // Indicates when to update the texts of
                                    // the buttons Sign Up / Account, Sign In / Sign out
    Texture2D background;           // Background image of the menu screen
    TextBox title[2];               // Title text boxes containing the game name
    TextBox buttons[2][3];          // Buttons on the menu screen (6 buttons in total)
    Selector2D selector = {0, 0};   // Selector for choosing buttons
    char* username;                 // Stores the account name to display when signed in or signed up
    
    void setup();                                           // Method to set up the menu screen
    Scene draw(bool& isSigned, gameMusic& musicAndSound);   // Method to draw the menu screen
};