#include "Result.h"

//Set up the Result screen
void ResultScene::setup(const bool& isDual) {
    isSet = 1;
    markTime = GetTime();
    
    //Set up for Dual mode
    if (isDual) {
        result.FontSize = float(WinHeight) / 4;
        result.ContentLength = MeasureText (result.content, result.FontSize);
        result.pos = {(float(WinWdith) - result.ContentLength) / 2, float(WinHeight) / 5};

        time.FontSize = float(WinHeight) / 10;
        time.FontColor = SlightGray;
        time.ContentLength = MeasureText (time.content, time.FontSize);
        time.pos = {(float(WinWdith) - time.ContentLength) / 2, result.pos.y + result.FontSize * 1.1f};

        short i, startX = 0, spaceX = float(WinWdith) / 2;
        for (i = 0; i < 2; i ++) {
            player[i].FontSize = float(WinHeight) / 10;
            player[i].FontColor = CYAN;
            player[i].ContentLength = MeasureText (player[i].content, player[i].FontSize);
            player[i].pos = {startX + (spaceX - player[i].ContentLength) / 2, time.pos.y + time.FontSize * 1.2f};

            score[i].FontSize = float(WinHeight) / 6;
            if (i == 1)
                score[i].FontColor = GREEN;
            else 
                score[i].FontColor = VIOLET;
            score[i].ContentLength = MeasureText (score[i].content, score[i].FontSize);
            score[i].pos = {startX + (spaceX - score[i].ContentLength) / 2, player[i].pos.y + player[i].FontSize * 1.1f};
        
            startX += spaceX;
        }
    }

    //Set up for Single mode
    else {
        if (isVictory) {
            addText (result.content, "YOU WON!");
            result.FontSize = float(WinHeight) / 4;
            result.ContentLength = MeasureText (result.content, result.FontSize);
            result.pos = {(float(WinWdith) - result.ContentLength) / 2, float(WinHeight) / 5};

            player[0].FontSize = float(WinHeight) / 10;
            player[0].FontColor = CYAN;
            player[0].ContentLength = MeasureText (player[0].content, player[0].FontSize);
            player[0].pos = {(float(WinWdith) - player[0].ContentLength) / 2, result.pos.y + result.FontSize * 1.1f};
            
            time.FontSize = float(WinHeight) / 10;
            time.FontColor = SlightGray;
            time.ContentLength = MeasureText (time.content, time.FontSize);
            time.pos = {(float(WinWdith) - time.ContentLength) / 2, player[0].pos.y + player[0].FontSize * 1.1f};

            score[0].FontSize = float(WinHeight) / 6;
            score[0].FontColor = GREEN;
            score[0].ContentLength = MeasureText (score[0].content, score[0].FontSize);
            score[0].pos = {(float(WinWdith) - score[0].ContentLength) / 2, time.pos.y + time.FontSize * 1.1f};
        }

        else {
            addText (result.content, "YOU LOST!");
            result.FontSize = float(WinHeight) / 4;
            result.ContentLength = MeasureText (result.content, result.FontSize);
            result.pos = {(float(WinWdith) - result.ContentLength) / 2, (float(WinHeight) - result.FontSize) / 2};
        }
    }

    //Set up the mutual parts between two modes
    result.FontColor = RED;
    
    addText (message.content, "Press Enter to get back to Choose Level");
    message.FontSize = float(WinHeight) / 20;
    message.FontColor = LIGHTGRAY;
    message.ContentLength = MeasureText (message.content, message.FontSize);
    message.pos = {(float(WinWdith) - message.ContentLength) / 2, float(WinHeight) - message.FontSize * 1.25f};
}

//Draw the Result screen
Scene ResultScene::draw(GameAction& action, const bool& isDual, gameMusic& musicAndSound) {
    //Background
    DrawRectangleRec (background, BackgrounColor);

    //Change color
    if (GetTime() - markTime >= 0.5) {
        if (isSameColor(result.FontColor, RED))
            result.FontColor = ORANGE;
        else if (isSameColor(result.FontColor, ORANGE))
            result.FontColor = YELLOW;
        else if (isSameColor(result.FontColor, YELLOW))
            result.FontColor = GREEN;
        else if (isSameColor(result.FontColor, GREEN))
            result.FontColor = BLUE;
        else if (isSameColor(result.FontColor, BLUE))
            result.FontColor = VIOLET;
        else if (isSameColor(result.FontColor, VIOLET))
            result.FontColor = PINK;
        else if (isSameColor(result.FontColor, PINK))
            result.FontColor = RED;

        if (isSameColor(score[0].FontColor, RED))
            score[0].FontColor = ORANGE;
        else if (isSameColor(score[0].FontColor, ORANGE))
            score[0].FontColor = YELLOW;
        else if (isSameColor(score[0].FontColor, YELLOW))
            score[0].FontColor = GREEN;
        else if (isSameColor(score[0].FontColor, GREEN))
            score[0].FontColor = BLUE;
        else if (isSameColor(score[0].FontColor, BLUE))
            score[0].FontColor = VIOLET;
        else if (isSameColor(score[0].FontColor, VIOLET))
            score[0].FontColor = PINK;
        else if (isSameColor(score[0].FontColor, PINK))
            score[0].FontColor = RED;
        markTime = GetTime();

        //Draw Result screen for Dual mode
        if (isDual) {
            if (isSameColor(score[1].FontColor, RED))
                score[1].FontColor = ORANGE;
            else if (isSameColor(score[1].FontColor, ORANGE))
                score[1].FontColor = YELLOW;
            else if (isSameColor(score[1].FontColor, YELLOW))
                score[1].FontColor = GREEN;
            else if (isSameColor(score[1].FontColor, GREEN))
                score[1].FontColor = BLUE;
            else if (isSameColor(score[1].FontColor, BLUE))
                score[1].FontColor = VIOLET;
            else if (isSameColor(score[1].FontColor, VIOLET))
                score[1].FontColor = PINK;
            else if (isSameColor(score[1].FontColor, PINK))
                score[1].FontColor = RED;
            markTime = GetTime();
        }
    }
    DrawText (result.content, result.pos.x, result.pos.y, result.FontSize, result.FontColor);
    DrawText (message.content, message.pos.x, message.pos.y, message.FontSize, message.FontColor);

    if (isDual) {
        DrawText (time.content, time.pos.x, time.pos.y, time.FontSize, time.FontColor);

        short i;
        for (i = 0; i < 2; i ++) {
            DrawText (player[i].content, player[i].pos.x, player[i].pos.y, player[i].FontSize, player[i].FontColor);
            DrawText (score[i].content, score[i].pos.x, score[i].pos.y, score[i].FontSize, score[i].FontColor);
        }
    }

    //Draw Result screen for Single mode
    else if (isVictory) {
        DrawText (player[0].content, player[0].pos.x, player[0].pos.y, player[0].FontSize, player[0].FontColor);
        DrawText (time.content, time.pos.x, time.pos.y, time.FontSize, time.FontColor);
        DrawText (score[0].content, score[0].pos.x, score[0].pos.y, score[0].FontSize, score[0].FontColor);
    }

    if (IsKeyPressed(KEY_ENTER)) {
        PlaySound(musicAndSound.pressButton);
        isSet = 0;
        delete[] result.content;

        if (isDual) {
            short i;
            delete[] time.content;
            for (i = 0; i < 2; i ++) {
                delete[] player[i].content;
                delete[] score[i].content;
            }
        }

        else if (isVictory) {
            delete[] player[0].content;
            delete[] time.content;
            delete[] score[0].content;
        }
        action = ChooseGameMode;
        return PLAY;
    }

    return PLAY;
}