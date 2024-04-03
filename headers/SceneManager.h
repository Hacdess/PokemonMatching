#pragma once
#include "MenuScreen/Menu.h"
#include "GamePlay/Game.h"

struct SceneManager {
    MenuScene MenuScreen;
    LevelScene LevelScreen;
    GameScene GameScreen;
};