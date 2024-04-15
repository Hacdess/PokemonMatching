#pragma once
#include "MenuScreen/Menu.h"
#include "GamePlay/Game.h"
#include "MenuScreen/Account.h"
#include "MenuScreen/Leaderboard.h"

struct SceneManager {
    MenuScene MenuScreen;
    GameModeScene GameModeScreen;
    LevelScene LevelScreen;
    GameScene GameScreen;
    SignUpScene SignUpScreen;
    SignInScene SignInScreen;
    LeaderboardSceen LeaderboardScreen;
    GuideScene GuideScreen; 
};