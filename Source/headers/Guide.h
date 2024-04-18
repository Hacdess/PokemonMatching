#include "Moving.h"
#include "Music.h"
struct Page {
    TextBox title;     //A textbox show the subject being introduced
    TextBox text;      //A textbox show the detailed information of the subject
    TextBox message;   //A textbox show the suggested movement : Press Enter to go back to Menu
};

struct GuideScene {
    bool set = 0;
    float FontSize = float (WinHeight) / 20, TitleFontSize = float (WinHeight) / 15;
    
    Texture2D background;                 //A image for background theme

    Page page[3];                         //Three pages to illustrate information of the game
    short selector;                       //A tool to move the cursor and control it
    void setup();                         //Get all the neccessay contents and the locations of the textboxes
    Scene draw(gameMusic& musicAndSound); //Draw the shape of the textbox, draw the words and fill colors to all of them 
};