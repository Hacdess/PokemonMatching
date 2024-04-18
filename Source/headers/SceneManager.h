#pragma once
#include "Menu.h"
#include "Game.h"
#include "Account.h"
#include "Leaderboard.h"

struct SceneManager {
    MenuScene MenuScreen;               //The first screen when starting the game: Menu screen.
    GameModeScene GameModeScreen;       //The screen for selecting Single or Dual mode
    LevelScene LevelScreen;             //The screen for selecting the levels
    GameScene GameScreen;               //The main screen for playing
    SignUpScene SignUpScreen;           //The screen for registering an account
    SignInScene SignInScreen;           //The screen for sign in by inputing an existed account
    LeaderboardSceen LeaderboardScreen; //The screen to show top 10 players
    GuideScene GuideScreen;             //The screen to show information about the game
};