#pragma once
//#include "raylib.h"
#include "items.h"
#include "GamePlay/Music.h"

void moveSelector1D (short& selector, const short& start, const short& end, gameMusic &musicAndSound);
void moveSelector2D (Selector2D& selector, const short& startX, const short& startY, const short& endX, const short& endY, gameMusic &musicAndSound);
void moveSelector2DPlayer2 (Selector2D& selector, const short& startX, const short& startY, const short& endX, const short& endY, gameMusic &musicAndSound);