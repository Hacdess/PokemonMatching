#include "../headers/GamePlay/Result.h"

void ResultScene::setup() {
    isSet = 1;

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
        result.FontSize = float(WinHeight) / 4;
        result.FontColor = RED;
        result.ContentLength = MeasureText (result.content, result.FontSize);
        result.pos = {(float(WinWdith) - result.ContentLength) / 2, (float(WinHeight) - result.FontSize) / 2};
    }

    message.content = new char[strlen("Press Enter to get back to Choose Level")];
    strcpy (message.content, "Press Enter to get back to Choose Level");
    message.FontSize = float(WinHeight) / 20;
    message.FontColor = LIGHTGRAY;
    message.ContentLength = MeasureText (message.content, message.FontSize);
    message.pos = {(float(WinWdith) - message.ContentLength) / 2, float(WinHeight) - message.FontSize * 1.25f};
}

Scene ResultScene::draw(GameAction& action) {
    DrawRectangleRec (background, BackgrounColor);
    DrawText (result.content, result.pos.x, result.pos.y, result.FontSize, result.FontColor);
    DrawText (message.content, message.pos.x, message.pos.y, message.FontSize, message.FontColor);

    if (isVictory) {
        DrawText (player.content, player.pos.x, player.pos.y, player.FontSize, player.FontColor);
        DrawText (time.content, time.pos.x, time.pos.y, time.FontSize, time.FontColor);
        DrawText (score.content, score.pos.x, score.pos.y, score.FontSize, score.FontColor);
    }

    if (IsKeyPressed(KEY_ENTER)) {
        isSet = 0;
        action = ChooseLevel;
        return PLAY;
    }

    return PLAY;
}