#include "Moving.h"

//Control and move the cursor in 1D array
void moveSelector1D (short& selector, const short& start, const short& end, gameMusic &musicAndSound) {
    if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_UP)){
        PlaySound(musicAndSound.moving);
        selector --;
    }
    else if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_DOWN)){
        PlaySound(musicAndSound.moving);
        selector ++;
    }
    if (selector < start) selector = end;
    if (selector > end) selector = start;
}

//Control and move the cursor in 2D array
void moveSelector2D (Selector2D& selector, const short& startX, const short& startY, const short& endX, const short& endY, gameMusic &musicAndSound) {
    if (IsKeyPressed(KEY_LEFT)){
        PlaySound(musicAndSound.moving);
        selector.x --;
    }
    else if (IsKeyPressed(KEY_RIGHT)){
        PlaySound(musicAndSound.moving);
        selector.x ++;
    }
    else if (IsKeyPressed(KEY_UP)){
        PlaySound(musicAndSound.moving);
        selector.y --;
    }
    else if (IsKeyPressed(KEY_DOWN)){
        PlaySound(musicAndSound.moving);
        selector.y ++;
    }

    if (selector.x < startX) selector.x = endX;
    if (selector.x > endX) selector.x = startX;
    if (selector.y < startY) selector.y = endY;
    if (selector.y > endY) selector.y = startY;
}

//Control and move cursor in 2D array, but this function allows player control the cursor with more keys
void moveSelector2DPlayer2(Selector2D &selector, const short &startX, const short &startY, const short &endX, const short &endY, gameMusic &musicAndSound) {
    if (IsKeyPressed(KEY_Z)){
        PlaySound(musicAndSound.moving);
        selector.x --;
    }
    else if (IsKeyPressed(KEY_C)){
        PlaySound(musicAndSound.moving);
        selector.x ++;
    }
    else if (IsKeyPressed(KEY_S)){
        PlaySound(musicAndSound.moving);
        selector.y --;
    }
    else if (IsKeyPressed(KEY_X)){
        PlaySound(musicAndSound.moving);
        selector.y ++;
    }

    if (selector.x < startX) selector.x = endX;
    if (selector.x > endX) selector.x = startX;
    if (selector.y < startY) selector.y = endY;
    if (selector.y > endY) selector.y = startY;
}