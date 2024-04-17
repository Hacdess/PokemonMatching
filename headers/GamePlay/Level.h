#pragma once
#include "../Moving.h"
#include "../GamePlay/Music.h"

struct GameModeScene {
    float time;           //A automatic clock to count the play time of the player
    Color background;     //The color for background theme
    TextBox TextBoxs[4];  //Four textboxes include: one titile, two buttons for selecting modes and one for going back the menu
    short selector;       //A tool to control and move cursor
    
    void setup();         //Get all the neccessay contents and the locations of the textboxes
    bool draw(GameAction& action, gameMusic& MusicAndSound); //Draw the shape of the textbox, draw the words and fill colors to all of them
};

struct LevelScene {
    float time;           //A automatic clock to count the play time of the player
    Color background;     //The color for background theme
    TextBox TextBoxs[5];  //Five textboxes include: one titile, three buttons for selecting levels and one for going back the menu
    short selector;       //A tool to control and move the cursor

    void setup();         //Get all the neccessay contents and the locations of the textboxes
    Level draw(GameAction& action, gameMusic& musicAndSound);//Draw the shape of the textbox, draw the words and fill colors to all of them
};