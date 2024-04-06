#include "../headers/GamePlay/Scoreboard.h"

void ScoreBoard::setup() {
    showHint = 0;

    //"Scoreboard" word on the top
    Title.content = new char[strlen("Scoreboard") + 1];
    strcpy (Title.content, "Scoreboard");
    Title.FontSize = HealthUnit;
    Title.FontColor = RED;
    Title.ContentLength = MeasureText ("Scoreboard", Title.FontSize);
    Title.pos = {
        border.x + (border.width - Title.ContentLength) / 2,
        border.y + HealthUnit
    };

    //At first, it's not login yet so the player name is "Guest"
    Player.content = new char[strlen("Guest") + 1];
    strcpy (Player.content, "Guest");
    Player.FontSize = HealthUnit * 0.75f;
    Player.FontColor = YELLOW;
    Player.ContentLength = MeasureText (Player.content, Player.FontSize);
    Player.pos = {
        border.x + (border.width - Player.ContentLength) / 2,
        Title.pos.y + Title.FontSize + HealthUnit / 2
    };

    //At first, the message is "Press 'h' for hint"
    Message.content = new char[strlen("Press 'h' for hint") + 1];
    strcpy (Message.content, "Press 'h' for hint");
    Message.FontSize = HealthUnit / 2;
    Message.FontColor = DarkCyan;
    Message.ContentLength = MeasureText ("Press 'h' for hint", Message.FontSize);
    Message.pos = {
        border.x + (border.width - Message.ContentLength) / 2,
        border.y + border.height - HealthUnit
    };

    //At first, the score = 0
    ScoreNum = 0;
    itoa (ScoreNum, ScoreText.content, 10);
    ScoreText.FontSize = HealthUnit * 0.75f;
    ScoreText.FontColor = WHITE;
    ScoreText.ContentLength = MeasureText (ScoreText.content, ScoreText.FontSize);
    ScoreText.pos = {
        border.x + (border.width - ScoreText.ContentLength) / 2,
        Player.pos.y + Player.FontSize + HealthUnit
    };
}

void ScoreBoard::updatePlayer(char* name) {
    delete[] Player.content;
    Player.content = new char[strlen(name) + 1];

    strcpy (Player.content, name);
}

void ScoreBoard::updateHint() {
    
}

void ScoreBoard::draw() {
    //Draw the border of ScoreBoard
    DrawRectangleRec (border, background);

    //----Draw all the rest things----

    //Title
    DrawText (Title.content, Title.pos.x, Title.pos.y, Title.FontSize, Title.FontColor);
    //Player name
    DrawText (Player.content, Player.pos.x, Player.pos.y, Player.FontSize, Player.FontColor);
    //Score
    DrawText (ScoreText.content, ScoreText.pos.x, ScoreText.pos.y, ScoreText.FontSize, ScoreText.FontColor);
    //Message
    DrawText (Message.content, Message.pos.x, Message.pos.y, Message.FontSize, Message.FontColor);
}