#include "../headers/GamePlay/Scoreboard.h"

void ScoreBoard::getScore() {
    delete[] ScoreNum;

    ScoreText = new char* [strlen(atoi(ScoreNum)) + 1];
    strcpy (ScoreText, atoi(ScoreNum));
}

void ScoreBoard::setup() {
    showHint = 0;

    Title.content = new char*[strlen("Scoreboard") + 1];
    strcpy (Title.content, "Scoreboard");

    Player.content = new char*[strlen("Guest") + 1];
    strcpy (Title.content, "Guest");

    getScore();

    Hint.content = new char*[strlen("Press H to get Hint") + 1];
    strcpy (Hint.content, "Press H to get Hint");
}

void ScoreBoard::updatePlayer(char* name) {
    delete[] Player;
    Player = new char*[strlen(name) + 1];

    strcpy (Player, name);

}

void ScoreBoard::updateHint() {
    
}