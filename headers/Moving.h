#pragma once
#include "raylib.h"
#include "items.h"

void moveSelector1D (short& selector, const short& start, const short& end);

void moveSelector2D (Selector2D& selector, const short& startX, const short& startY, const short& endX, const short& endY);