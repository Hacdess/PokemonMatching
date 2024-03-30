#pragma once
#include "ScoreBoard.h"
#include <cstring>
#include "../items.h"
#include "../Moving.h"

enum Level {easy, medium, hard, custom, menu};

Level ChooseLevel ();

void DrawGameScreen (const int& WindowWidth, const int& WindowHeight, bool& exit, const Texture2D& BackgroundPic, bool& isSigned);