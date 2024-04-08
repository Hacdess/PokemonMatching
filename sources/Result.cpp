#include "../headers/GamePlay/Result.h"

void ResultScene::setup() {
    if (isVictory) {
        result.content = new char[strlen("YOU WON!") + 1];
        strcpy (result.content, "YOU WON!");
    }
    else {
        result.content = new char[strlen("YOU LOST!") + 1];
        strcpy (result.content, "YOU LOST!");
    }

    result.ContentLength = MeasureText (result.content, float(WinHeight) / 4);
    result.pos = {
        (float(WinWdith) - result.ContentLength) / 2,
        float(WinHeight) / 5
    }
}