#include "../headers/Moving.h"

void moveSelector1D (short& selector, const short& start, const short& end) {
    if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_UP))
        selector --;
    else if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_DOWN))
        selector ++;
    if (selector < start) selector = end;
    if (selector > end) selector = start;
}

void moveSelector2D (Selector2D& selector, const short& startX, const short& startY, const short& endX, const short& endY) {
    if (IsKeyPressed(KEY_LEFT))
        selector.x --;
    else if (IsKeyPressed(KEY_RIGHT))
        selector.x ++;
    else if (IsKeyPressed(KEY_UP))
        selector.y --;
    else if (IsKeyPressed(KEY_DOWN))
        selector.y ++;

    if (selector.x < startX) selector.x = endX;
    if (selector.x > endX) selector.x = startX;
    if (selector.y < startY) selector.y = endY;
    if (selector.y > endY) selector.y = startY;
}
void moveSelector2DPlayer2(Selector2D &selector, const short &startX, const short &startY, const short &endX, const short &endY) {
    if (IsKeyPressed(KEY_A))
        selector.x --;
    else if (IsKeyPressed(KEY_D))
        selector.x ++;
    else if (IsKeyPressed(KEY_W))
        selector.y --;
    else if (IsKeyPressed(KEY_S))
        selector.y ++;

    if (selector.x < startX) selector.x = endX;
    if (selector.x > endX) selector.x = startX;
    if (selector.y < startY) selector.y = endY;
    if (selector.y > endY) selector.y = startY;
}