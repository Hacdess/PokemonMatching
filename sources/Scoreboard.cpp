#include "../headers/GamePlay/Scoreboard.h"

void ScoreBoard::setup() {
    showHint = 0;
    ScoreNum = 0;

    Title.content = new char[strlen("Scoreboard") + 1];
    strcpy (Title.content, "Scoreboard");
    Title.FontSize = HealthUnit;
    Title.FontColor = RED;
    Title.ContentLength = MeasureText ("Scoreboard", Title.FontSize);


    Player.content = new char[strlen("Guest") + 1];
    strcpy (Player.content, "Guest");

    itoa (ScoreNum, ScoreText, 10);

    Hint.content = new char[strlen("Press H to get Hint") + 1];
    strcpy (Hint.content, "Press H to get Hint");
}

void ScoreBoard::updatePlayer(char* name) {
    delete[] Player.content;
    Player.content = new char[strlen(name) + 1];

    strcpy (Player.content, name);
}

void ScoreBoard::updateHint() {
    
}

void ScoreBoard::draw() {
    
}