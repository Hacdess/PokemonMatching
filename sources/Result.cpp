#include "../headers/GamePlay/Result.h"

void ResultScene::setup() {
    if (isVictory) {
        result.content = new char[strlen("YOU WON!") + 1];
        strcpy (result.content, "YOU WON!");
        result.FontSize = float(WinHeight) / 4;
        result.FontColor = RED;
        result.ContentLength = MeasureText (result.content, result.FontSize);
        result.pos = {(float(WinWdith) - result.ContentLength) / 2, float(WinHeight) / 5};

        player.FontSize = float(WinHeight) / 5;
        player.FontColor = PURPLE;
        player.ContentLength = MeasureText (player.content, player.FontSize);
        player.pos = {(float(WinWdith) - player.ContentLength) / 2, result.pos.y + result.FontSize * 1.5f};
        
        time.FontSize = float(WinHeight) / 6;
        time.FontColor = YELLOW;
        time.ContentLength = MeasureText (time.content, time.FontSize);
        time.pos = {(float(WinWdith) - time.ContentLength) / 2, player.pos.y + player.FontSize * 1.25f};

        score.FontSize = float(WinHeight) / 5;
        score.FontColor = RED;
        score.ContentLength = MeasureText (score.content, score.FontSize);
        score.pos = {(float(WinWdith) - score.ContentLength) / 2, time.pos.y + time.FontSize * 1.25f};
    }

    else {
        result.content = new char[strlen("YOU LOST!") + 1];
        strcpy (result.content, "YOU LOST!");
        result.FontSize = float(WinHeight) / 3;
        result.FontColor = RED;
        result.ContentLength = MeasureText (result.content, result.FontSize);
        result.pos = {(float(WinWdith) - result.ContentLength) / 2, (float(WinHeight) - result.FontSize) / 2};
    }
}

Scene ResultScene::draw() {
    DrawRectangleRec (background, BackgrounColor);

    if (isVictory) {

    }

    return PLAY;
}