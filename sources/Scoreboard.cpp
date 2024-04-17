#include "../headers/GamePlay/Scoreboard.h"

void ScoreBoard::setup(const bool& isDual, const char* username) {
    //The box of scoreboard
    if (!isDual) {
        border = {
            float (WinWdith) / 3 * 2,
            float (WinHeight) / 4,
            float (WinHeight) / 2,
            float (WinHeight) / 2
        };
    }

    else {
        border = {
            float (WinWdith) / 3 * 2,
            float (WinHeight) / 12,
            float (WinHeight) / 2,
            float (WinHeight) * 5 / 6
        };
    }

    //"Scoreboard" word on the top
    addText (Title.content, "Scoreboard");
    Title.FontSize = HealthUnit;
    Title.FontColor = RED;
    Title.ContentLength = MeasureText (Title.content, Title.FontSize);
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
    if (isDual) {
        addText (Player[0].content, "Player 1");
    }
    else {
        if (username == NULL)
            addText (Player[0].content, "Guest");
        else 
            addText (Player[0].content, username);
    }


    Player[0].FontSize = HealthUnit * 0.75f;
    Player[0].FontColor = RED;
    Player[0].ContentLength = MeasureText (Player[0].content, Player[0].FontSize);
    Player[0].pos = {
        border.x + (border.width - Player[0].ContentLength) / 2,
        TimeText.pos.y + TimeText.FontSize * 1.5f
    };

    //HP Bar
    HP_Bar[0] = {
        border.x + (border.width - HealthFull) / 2,
        HP_Bar[0].y = Player[0].pos.y + Player[0].FontSize * 1.1f,
        HealthFull,
        HealthUnit * 0.75f
    };
    health = 5;
    HP[0].x = HP_Bar[0].x;
    HP[0].y = HP_Bar[0].y;
    HP[0].width = HealthUnit * health;
    HP[0].height = HP_Bar[0].height;

    //At first, the score = 0
    ScoreNum = 0;
    addText (ScoreText[0].content, "0");
    ScoreText[0].FontSize = HealthUnit * 0.75f;
    ScoreText[0].FontColor = RED;
    ScoreText[0].ContentLength = MeasureText (ScoreText[0].content, ScoreText[0].FontSize);
    ScoreText[0].pos = {
        border.x + (border.width - ScoreText[0].ContentLength) / 2,
        HP_Bar[0].y + HP_Bar[0].height * 1.2f
    };

    //There are 3 guides:
    //Press 'O' for shuffle
    addText (Guide[0].content, "Press 'o' for shuffle");
    //Press 'P' for hint
    addText (Guide[1].content, "Press 'p' for hint");
    //-4 / hint, -2 / shuffle
    addText (Guide[2].content, "-2 / shuffle, -4 / hint");

    short i;
    float startY = ScoreText[0].pos.y + ScoreText[0].FontSize * 1.1f;

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

    addText (Message[0].content, "Enjoy the game");
    Message[0].FontSize = HealthUnit * 0.5f;
    Message[0].FontColor = CYAN;
    Message[0].ContentLength = MeasureText (Message[0].content, Message[0].FontSize);
    Message[0].pos = {
        border.x + (border.width - Message[0].ContentLength) / 2,
        Guide[2].pos.y + Guide[2].FontSize * 1.2f
    };

    if (isDual) {
        startY = Message[0].pos.y + Message[0].FontSize * 1.9f;

        addText (Player[1].content, "Player 2");

        Player[1].FontSize = HealthUnit * 0.75f;
        Player[1].FontColor = PURPLE;
        Player[1].ContentLength = MeasureText (Player[1].content, Player[1].FontSize);
        Player[1].pos = {
            border.x + (border.width - Player[1].ContentLength) / 2,
            startY
        };

        //HP Bar
        HP_Bar[1] = {
            border.x + (border.width - HealthFull) / 2,
            HP_Bar[1].y = Player[1].pos.y + Player[1].FontSize * 1.1f,
            HealthFull,
            HealthUnit * 0.75f
        };
        health2 = 5;
        HP[1].x = HP_Bar[1].x;
        HP[1].y = HP_Bar[1].y;
        HP[1].width = HealthUnit * health;
        HP[1].height = HP_Bar[1].height;

        //At first, the score = 0
        ScoreNum2 = 0;
        addText (ScoreText[1].content, "0");
        ScoreText[1].FontSize = HealthUnit * 0.75f;
        ScoreText[1].FontColor = PURPLE;
        ScoreText[1].ContentLength = MeasureText (ScoreText[1].content, ScoreText[1].FontSize);
        ScoreText[1].pos = {
            border.x + (border.width - ScoreText[1].ContentLength) / 2,
            HP_Bar[1].y + HP_Bar[1].height * 1.2f
        };

        //There are 3 guides:
        //Press '0' for shuffle
        addText (Guide[3].content, "Press 'g' for shuffle");
        //Press '1' for hint
        addText (Guide[4].content, "Press 'h' for hint");
        //-4 / hint, -2 / shuffle
        addText (Guide[5].content, "-2 / shuffle, -4 / hint");

        short i;
        float startY = ScoreText[1].pos.y + ScoreText[1].FontSize * 1.1f;

        for (i = 3; i < 6; i ++) {
            Guide[i].FontSize = HealthUnit * 0.45f;
            Guide[i].FontColor = PINK;
            Guide[i].ContentLength = MeasureText (Guide[i].content, Guide[i].FontSize);
            Guide[i].pos = {
                border.x + (border.width - Guide[i].ContentLength) / 2,
                startY
            };
            startY = startY + Guide[i].FontSize * 1.2f;
        }

        addText (Message[1].content, "Enjoy the game");
        Message[1].FontSize = HealthUnit * 0.5f;
        Message[1].FontColor = CYAN;
        Message[1].ContentLength = MeasureText (Message[1].content, Message[1].FontSize);
        Message[1].pos = {
            border.x + (border.width - Message[1].ContentLength) / 2,
            Guide[5].pos.y + Guide[5].FontSize * 1.2f
        };

    }

    markTime = GetTime();
}

void ScoreBoard::updatePlayer(char* name) {
    delete[] Player[0].content;
    addText (Player[0].content, name);
}

void ScoreBoard::updateHP(const bool& isDual) {
    HP[0].width = HealthUnit * health;
    if (isDual)
        HP[1].width = HealthUnit * health2;
}

//The score changes so it must be updated
void ScoreBoard::updateScoreText(const bool& isDual) {
    delete [] ScoreText[0].content;
    ScoreText[0].content = NULL;
    string s = to_string (ScoreNum);
    addText (ScoreText[0].content, StoA(s));
    ScoreText[0].ContentLength = MeasureText (ScoreText[0].content, ScoreText[0].FontSize);
    ScoreText[0].pos.x = border.x + (border.width - ScoreText[0].ContentLength) / 2;

    if (isDual) {
        delete [] ScoreText[1].content;
        ScoreText[1].content = NULL;
        s = to_string (ScoreNum2);
        addText (ScoreText[1].content, StoA(s));
        ScoreText[1].ContentLength = MeasureText (ScoreText[1].content, ScoreText[0].FontSize);
        ScoreText[1].pos.x = border.x + (border.width - ScoreText[1].ContentLength) / 2;
    }
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

void ScoreBoard::updateMessage1(const Selector2D& pokemon1, const Selector2D& pokemon2, const MatchingType& MatchType) {
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

    delete[] Message[0].content;
    addText (Message[0].content, StoA (temp));

    Message[0].ContentLength = MeasureText (Message[0].content, Message[0].FontSize);
    Message[0].pos.x = border.x + (border.width - Message[0].ContentLength) / 2;
}

void ScoreBoard::updateMessage2(const Selector2D& pokemon1, const Selector2D& pokemon2, const MatchingType& MatchType) {
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

    delete[] Message[1].content;
    addText (Message[1].content, StoA (temp));

    Message[1].ContentLength = MeasureText (Message[1].content, Message[1].FontSize);
    Message[1].pos.x = border.x + (border.width - Message[1].ContentLength) / 2;
}

void ScoreBoard::draw(const bool& isDual) {
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
    DrawText (Player[0].content, Player[0].pos.x, Player[0].pos.y, Player[0].FontSize, Player[0].FontColor);
    //HP bar
    updateHP(isDual);
    DrawRectangleRec (HP_Bar[0], HP_Bar_Color);
    DrawRectangleRec (HP[0], HP_Color);
    //Play time
    updateTimeText();
    DrawText (TimeText.content, TimeText.pos.x, TimeText.pos.y, TimeText.FontSize, TimeText.FontColor);
    //Score
    updateScoreText(isDual);
    DrawText (ScoreText[0].content, ScoreText[0].pos.x, ScoreText[0].pos.y, ScoreText[0].FontSize, ScoreText[0].FontColor);
    //Guides
    short i;
    for (i = 0; i < 3; i ++)
        DrawText (Guide[i].content, Guide[i].pos.x, Guide[i].pos.y, Guide[i].FontSize, Guide[i].FontColor);
    //Message
    DrawText (Message[0].content, Message[0].pos.x, Message[0].pos.y, Message[0].FontSize, Message[0].FontColor);

    if (isDual) {
        //Player name
        DrawText (Player[1].content, Player[1].pos.x, Player[1].pos.y, Player[1].FontSize, Player[1].FontColor);
        //HP bar
        updateHP(isDual);
        DrawRectangleRec (HP_Bar[1], HP_Bar_Color);
        DrawRectangleRec (HP[1], HP_Color);
        //Play time
        updateTimeText();
        DrawText (TimeText.content, TimeText.pos.x, TimeText.pos.y, TimeText.FontSize, TimeText.FontColor);
        //Score
        updateScoreText(isDual);
        DrawText (ScoreText[1].content, ScoreText[1].pos.x, ScoreText[1].pos.y, ScoreText[1].FontSize, ScoreText[1].FontColor);
        //Guides
        short i;
        for (i = 3; i < 6; i ++)
            DrawText (Guide[i].content, Guide[i].pos.x, Guide[i].pos.y, Guide[i].FontSize, Guide[i].FontColor);
        //Message
        DrawText (Message[1].content, Message[1].pos.x, Message[1].pos.y, Message[1].FontSize, Message[1].FontColor);
    }
}