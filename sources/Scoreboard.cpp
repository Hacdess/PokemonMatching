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
        border.y + HealthUnit / 2
    };

    //At first, it's not login yet so the player name is "Guest"
    Player.content = new char[strlen("Guest") + 1];
    strcpy (Player.content, "Guest");
    Player.FontSize = HealthUnit * 0.75f;
    Player.FontColor = YELLOW;
    Player.ContentLength = MeasureText (Player.content, Player.FontSize);
    Player.pos = {
        border.x + (border.width - Player.ContentLength) / 2,
        Title.pos.y + Title.FontSize + HealthUnit / 3
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

    //HP Bar
    HP_Bar.y = Player.pos.y + Player.FontSize + HealthUnit / 4;
    HP.y = HP_Bar.y;

    //PlayTime strating
    PlayTime.hour = 0, PlayTime.min = 0, PlayTime.sec = 0;
    TimeText.content = new char[strlen("00:00:00") + 1];
    strcpy (TimeText.content, "00:00:00");
    TimeText.FontSize = HealthUnit * 0.5;
    TimeText.FontColor = RED;
    TimeText.ContentLength = MeasureText (TimeText.content, TimeText.FontSize);
    TimeText.pos = {
        border.x + (border.width - TimeText.ContentLength) / 2,
        HP.y + HP.height + HealthUnit / 4
    };

    //At first, the score = 0
    ScoreNum = 0;
    itoa (ScoreNum, ScoreText.content, 10);
    ScoreText.FontSize = HealthUnit * 1.25f;
    ScoreText.FontColor = WHITE;
    ScoreText.ContentLength = MeasureText (ScoreText.content, ScoreText.FontSize);
    ScoreText.pos = {
        border.x + (border.width - ScoreText.ContentLength) / 2,
        TimeText.pos.y + HealthUnit
    };
}

void ScoreBoard::updatePlayer(char* name) {
    delete[] Player.content;
    Player.content = new char[strlen(name) + 1];

    strcpy (Player.content, name);
}

void ScoreBoard::updateHint(const Selector2D& pokemon1, const Selector2D& pokemon2, const MatchingType& MatchType) {
    string temp = "";
    if (MatchType == I)
        temp += "I Matching: ";
    if (MatchType == L)
        temp += "L Matching: ";
    if (MatchType == U)
        temp += "U Matching: ";
    if (MatchType == Z)
        temp += "Z Matching: ";

    temp = '(' + to_string(pokemon1.x) + ',' + to_string(pokemon1.y) + ") - (" + to_string(pokemon2.x) + ',' + to_string(pokemon2.y) + ')';

}

void ScoreBoard::draw(bool& isSigned, char* name) {
    //Draw the border of ScoreBoard
    DrawRectangleRec (border, background);

    //Update player name if player signed in
    if (isSigned && !isUpdatedPlayerName) {
        updatePlayer (name);
        isUpdatedPlayerName = 1;
    }

    //----Draw all the rest things----

    //Title
    DrawText (Title.content, Title.pos.x, Title.pos.y, Title.FontSize, Title.FontColor);
    //Player name
    DrawText (Player.content, Player.pos.x, Player.pos.y, Player.FontSize, Player.FontColor);
    //HP bar
    DrawRectangleRec (HP_Bar, HP_Bar_Color);
    DrawRectangleRec (HP, HP_Color);
    //Score
    DrawText (ScoreText.content, ScoreText.pos.x, ScoreText.pos.y, ScoreText.FontSize, ScoreText.FontColor);
    //Play time
    DrawText (TimeText.content, TimeText.pos.x, TimeText.pos.y, TimeText.FontSize, TimeText.FontColor);
    //Message
    DrawText (Message.content, Message.pos.x, Message.pos.y, Message.FontSize, Message.FontColor);
}