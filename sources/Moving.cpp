#include "../headers/Moving.h"

void moveSelector1D (Selector1D& selector) {
    if (IsKeyPressed(KEY_LEFT)) selector.x --;
    if (IsKeyPressed(KEY_RIGHT)) selector.x ++;
}

void moveSelector2D (Selector2D& selector) {
    if (IsKeyPressed(KEY_LEFT)) {
        selector.x --;
        return;
    }
    if (IsKeyPressed(KEY_RIGHT)) {
        selector.x ++;
        return;
    }
    
    if (IsKeyPressed(KEY_UP)) {
        selector.y --;
        return;
    }
    
    if (IsKeyPressed(KEY_DOWN)) {
        selector.y ++;
        return;
    }
    
}