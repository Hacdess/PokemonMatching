#include "../headers/GamePlay/Scoreboard.h"

void ScoreBoard::setup(const char* username) {
    //The box of scoreboard
    border = {
        float (WinWdith) / 3 * 2,
        float (WinHeight) / 4,
        float (WinHeight) / 2,
        float (WinHeight) / 2
    };


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

    //PlayTime strating (right below the Title)
    PlayTime.hour = 0, PlayTime.min = 0, PlayTime.sec = 0;
    TimeText.content = new char[strlen("00:00:00") + 1];
    strcpy (TimeText.content, "00:00:00");
    TimeText.FontSize = HealthUnit / 2;
    TimeText.FontColor = CYAN;
    TimeText.ContentLength = MeasureText (TimeText.content, TimeText.FontSize);
    TimeText.pos = {
        border.x + (border.width - TimeText.ContentLength) / 2,
        Title.pos.y + Title.FontSize * 1.1f
    };

    //At first, it's not login yet so the player name is "Guest"
    if (username == NULL) {
        Player.content = new char[strlen("Guest") + 1];
        strcpy (Player.content, "Guest");
    }
    else {
        Player.content = new char[strlen(username) + 1];
        strcpy (Player.content, username);
    }
    Player.FontSize = HealthUnit * 0.75f;
    Player.FontColor = WHITE;
    Player.ContentLength = MeasureText (Player.content, Player.FontSize);
    Player.pos = {
        border.x + (border.width - Player.ContentLength) / 2,
        TimeText.pos.y + TimeText.FontSize * 1.25f
    };

    //HP Bar
    HP_Bar = {
        border.x + (border.width - HealthFull) / 2,
        HP_Bar.y = Player.pos.y + Player.FontSize * 1.1f,
        HealthFull,
        HealthUnit * 0.75f
    };
    health = 5;
    HP.x = HP_Bar.x;
    HP.y = HP_Bar.y;
    HP.width = HealthUnit * health;
    HP.height = HP_Bar.height;

    //At first, the score = 0
    ScoreNum = 0;
    ScoreText.content = new char[2];
    strcpy (ScoreText.content, "0");
    ScoreText.FontSize = HealthUnit * 0.75f;
    ScoreText.FontColor = WHITE;
    ScoreText.ContentLength = MeasureText (ScoreText.content, ScoreText.FontSize);
    ScoreText.pos = {
        border.x + (border.width - ScoreText.ContentLength) / 2,
        HP_Bar.y + HP_Bar.height * 1.2f
    };

    //There are 3 guides:
    //Press '1' for hint
    Guide[0].content = new char[strlen("Press '1' for hint") + 1];
    strcpy (Guide[0].content, "Press '1' for hint");
    //Press '0' for shuffle
    Guide[1].content = new char[strlen("Press '0' for shuffle") + 1];
    strcpy (Guide[1].content, "Press '0' for shuffle");
    //-4 / hint, -2 / shuffle
    Guide[2].content = new char[strlen("-4/hint, -2/shuffle") + 1];
    strcpy (Guide[2].content, "-4/hint, -2/shuffle");

    short i;
    float startY = ScoreText.pos.y + ScoreText.FontSize * 1.1f;

    for (i = 0; i < 3; i ++) {
        Guide[i].FontSize = HealthUnit * 0.45f;
        Guide[i].FontColor = YELLOW;
        Guide[i].ContentLength = MeasureText (Guide[i].content, Guide[i].FontSize);
        Guide[i].pos = {
            border.x + (border.width - Guide[i].ContentLength) / 2,
            startY
        };
        startY = startY + Guide[i].FontSize * 1.2f;
    }

    addText (Message.content, "Enjoy the game");
    Message.FontSize = HealthUnit * 0.5f;
    Message.FontColor = CYAN;
    Message.ContentLength = MeasureText (Message.content, Message.FontSize);
    Message.pos = {
        border.x + (border.width - Message.ContentLength) / 2,
        Guide[2].pos.y + Guide[2].FontSize * 1.2f
    };

    markTime = GetTime();
}

void ScoreBoard::updatePlayer(char* name) {
    delete[] Player.content;
    Player.content = new char[strlen(name) + 1];

    strcpy (Player.content, name);
}

void ScoreBoard::updateHP() {
    HP.width = HealthUnit * health;
}

//The score changes so it must be updated
void ScoreBoard::updateScoreText() {
    delete [] ScoreText.content;
    ScoreText.content = NULL;

    string s = to_string (ScoreNum);
    ScoreText.content = StoA(s);
    ScoreText.ContentLength = MeasureText (ScoreText.content, ScoreText.FontSize);
    ScoreText.pos.x = border.x + (border.width - ScoreText.ContentLength) / 2;
}

void ScoreBoard::updateTimeText() {
    float newTime = GetTime();
    if (newTime - markTime >= 1) {
        markTime = newTime;
        PlayTime.sec ++;
        PlayTime.formatTime();
        delete[] TimeText.content;
        addText (TimeText.content, StoA (TimeToString (PlayTime)));
        TimeText.ContentLength = MeasureText (TimeText.content, TimeText.FontSize);
        TimeText.pos.x = border.x + (border.width - TimeText.ContentLength) / 2;
    }
}

void ScoreBoard::updateMessage(const Selector2D& pokemon1, const Selector2D& pokemon2, const MatchingType& MatchType) {
    string temp = "";
    if (MatchType == I)
        temp += "I Matching: ";
    if (MatchType == L)
        temp += "L Matching: ";
    if (MatchType == U)
        temp += "U Matching: ";
    if (MatchType == Z)
        temp += "Z Matching: ";

    temp = temp + '(' + to_string(pokemon1.x) + ',' + to_string(pokemon1.y) + ") - (" + to_string(pokemon2.x) + ',' + to_string(pokemon2.y) + ')';

    delete[] Message.content;
    addText (Message.content, StoA (temp));

    Message.ContentLength = MeasureText (Message.content, Message.FontSize);
    Message.pos.x = border.x + (border.width - Message.ContentLength) / 2;
}

void ScoreBoard::draw() {
    //Draw the border of ScoreBoard
    DrawRectangleRec (border, background);

    //----Draw all the rest things----

    //Title
    if (GetTime() - markTime >= 1) {
        if (isSameColor(Title.FontColor, RED))
            Title.FontColor = ORANGE;
        else if (isSameColor(Title.FontColor, ORANGE))
            Title.FontColor = YELLOW;
        else if (isSameColor(Title.FontColor, YELLOW))
            Title.FontColor = GREEN;
        else if (isSameColor(Title.FontColor, GREEN))
            Title.FontColor = BLUE;
        else if (isSameColor(Title.FontColor, BLUE))
            Title.FontColor = VIOLET;
        else if (isSameColor(Title.FontColor, VIOLET))
            Title.FontColor = PINK;
        else if (isSameColor(Title.FontColor, PINK))
            Title.FontColor = RED;
    }
    DrawText (Title.content, Title.pos.x, Title.pos.y, Title.FontSize, Title.FontColor);
    //Player name
    DrawText (Player.content, Player.pos.x, Player.pos.y, Player.FontSize, Player.FontColor);
    //HP bar
    updateHP();
    DrawRectangleRec (HP_Bar, HP_Bar_Color);
    DrawRectangleRec (HP, HP_Color);
    //Score
    updateScoreText();
    DrawText (ScoreText.content, ScoreText.pos.x, ScoreText.pos.y, ScoreText.FontSize, ScoreText.FontColor);
    //Play time
    updateTimeText();
    DrawText (TimeText.content, TimeText.pos.x, TimeText.pos.y, TimeText.FontSize, TimeText.FontColor);
    //Guides
    short i;
    for (i = 0; i < 3; i ++)
        DrawText (Guide[i].content, Guide[i].pos.x, Guide[i].pos.y, Guide[i].FontSize, Guide[i].FontColor);
    //Message
    DrawText (Message.content, Message.pos.x, Message.pos.y, Message.FontSize, Message.FontColor);
}