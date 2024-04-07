#pragma once
#include "MenuScreen/Menu.h"
#include "GamePlay/Game.h"
#include "MenuScreen/Account.h"

struct SceneManager {
    MenuScene MenuScreen;
    LevelScene LevelScreen;
    GameScene GameScreen;
    SignUpScene SignUpScreen;
    SignInScene SignInScreen;
};