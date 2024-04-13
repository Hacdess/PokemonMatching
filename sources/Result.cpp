#include "../headers/GamePlay/Result.h"

void ResultScene::setup() {
    isSet = 1;
    markTime = GetTime();

    if (isVictory) {
        result.content = new char[strlen("YOU WON!") + 1];
        strcpy (result.content, "YOU WON!");
        result.FontSize = float(WinHeight) / 4;
        result.ContentLength = MeasureText (result.content, result.FontSize);
        result.pos = {(float(WinWdith) - result.ContentLength) / 2, float(WinHeight) / 5};

        player.FontSize = float(WinHeight) / 10;
        player.FontColor = CYAN;
        player.ContentLength = MeasureText (player.content, player.FontSize);
        player.pos = {(float(WinWdith) - player.ContentLength) / 2, result.pos.y + result.FontSize * 1.1f};
        
        time.FontSize = float(WinHeight) / 10;
        time.FontColor = SlightGray;
        time.ContentLength = MeasureText (time.content, time.FontSize);
        time.pos = {(float(WinWdith) - time.ContentLength) / 2, player.pos.y + player.FontSize * 1.1f};

        score.FontSize = float(WinHeight) / 6;
        score.FontColor = GREEN;
        score.ContentLength = MeasureText (score.content, score.FontSize);
        score.pos = {(float(WinWdith) - score.ContentLength) / 2, time.pos.y + time.FontSize * 1.1f};
    }

    else {
        result.content = new char[strlen("YOU LOST!") + 1];
        strcpy (result.content, "YOU LOST!");
        result.FontSize = float(WinHeight) / 4;
        result.ContentLength = MeasureText (result.content, result.FontSize);
        result.pos = {(float(WinWdith) - result.ContentLength) / 2, (float(WinHeight) - result.FontSize) / 2};
    }

    result.FontColor = RED;
    
    message.content = new char[strlen("Press Enter to get back to Choose Level") + 1];
    strcpy (message.content, "Press Enter to get back to Choose Level");
    message.FontSize = float(WinHeight) / 20;
    message.FontColor = LIGHTGRAY;
    message.ContentLength = MeasureText (message.content, message.FontSize);
    message.pos = {(float(WinWdith) - message.ContentLength) / 2, float(WinHeight) - message.FontSize * 1.25f};
}

Scene ResultScene::draw(GameAction& action) {
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

        if (isSameColor(score.FontColor, RED))
            score.FontColor = ORANGE;
        else if (isSameColor(score.FontColor, ORANGE))
            score.FontColor = YELLOW;
        else if (isSameColor(score.FontColor, YELLOW))
            score.FontColor = GREEN;
        else if (isSameColor(score.FontColor, GREEN))
            score.FontColor = BLUE;
        else if (isSameColor(score.FontColor, BLUE))
            score.FontColor = VIOLET;
        else if (isSameColor(score.FontColor, VIOLET))
            score.FontColor = PINK;
        else if (isSameColor(score.FontColor, PINK))
            score.FontColor = RED;
        markTime = GetTime();
    }
    DrawText (result.content, result.pos.x, result.pos.y, result.FontSize, result.FontColor);
    DrawText (message.content, message.pos.x, message.pos.y, message.FontSize, message.FontColor);

    if (isVictory) {
        DrawText (player.content, player.pos.x, player.pos.y, player.FontSize, player.FontColor);
        DrawText (time.content, time.pos.x, time.pos.y, time.FontSize, time.FontColor);
        DrawText (score.content, score.pos.x, score.pos.y, score.FontSize, score.FontColor);
    }

    if (IsKeyPressed(KEY_ENTER)) {
        isSet = 0;
        delete[] result.content;

        if (isVictory) {
            delete[] player.content;
            delete[] time.content;
            delete[] score.content;
        }
        action = ChooseLevel;
        return PLAY;
    }

    return PLAY;
}