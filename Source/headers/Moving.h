#pragma once
//#include "raylib.h"
#include "items.h"
#include "Music.h"

//Control, move the cursor and add sound whenever it's moved in 1D (For selecting buttons)
void moveSelector1D (short& selector, const short& start, const short& end, gameMusic &musicAndSound);

//Control, move the cursor and add sound whenever it's moved in 2D (For selecting buttons or selecting Pokemon)
void moveSelector2D (Selector2D& selector, const short& startX, const short& startY, const short& endX, const short& endY, gameMusic &musicAndSound);
void moveSelector2DPlayer2 (Selector2D& selector, const short& startX, const short& startY, const short& endX, const short& endY, gameMusic &musicAndSound);