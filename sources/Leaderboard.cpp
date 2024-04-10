#include "../headers/MenuScreen/Leaderboard.h"

void addHead () {
    
}

void StageScene::getList(const Level& level) {
    string checkLevel;
    if (level == EASY)
        checkLevel = "Easy";
    if (level == MEDIUM)
        checkLevel = "Medium";
    if (level == HARD)
        checkLevel = "Hard";

    ifstream fin;
    fin.open("resources/file/Result.txt");
    if (!fin.is_open()) {
        cout << "Can't open file\n";
        return;
    }

    string temp;
    getline(fin, temp);

    while (!fin.eof()) {
        getline (fin, temp, ',');
        if (temp == checkLevel) {
            getline
        }

        else
            fin >> temp;
    }

    fin.close();
}

void sortListPlayer (Player*& list) {

}

void StageScene::setup() {
    short i;
    //Constant[0] is the level
    constant[0].FontSize = float(WinHeight) / 10;
    constant[0].FontColor = RED;
    constant[0].border = {0, 0, float(WinWdith), constant[0].FontSize * 1.1f};
    constant[0].pos.y = (constant[0].border.height - constant[0].FontSize) / 2;
    constant[0].BorderColor = DarkCyan;

    float unit = float(WinWdith) / 9, start = 0;

    addText (constant[1].content, "Rank");
    addText (constant[2].content, "Player");
    addText (constant[3].content, "Score");
    addText (constant[4].content, "Play Time");
    for (i = 1; i < 5; i ++) {
        constant[i].FontSize = float(WinHeight) / 15;
        constant[i].FontColor = BLUE;
        constant[i].BorderColor = DarkCyan;
        constant[i].border.y = constant[0].border.y + constant[0].border.height;
        constant[i].border.height = constant[i].FontSize * 1.1f;
        constant[i].pos.y = constant[i].border.y + (constant[i].border.height - constant[i].FontSize) / 2;
        constant[i].ContentLength = MeasureText (constant[i].content, constant[i].FontSize);
    }

    constant[1].border.x = start;
    constant[1].border.width = unit;
    constant[1].pos.x = start + (unit - constant[1].ContentLength) / 2;
    start += unit;

    constant[2].border.x = start;
    constant[2].border.width = unit * 3;
    constant[2].pos.x = start + (constant[2].border.width - constant[2].ContentLength) / 2;
    start = start + unit * 3;
    
    constant[3].border.x = start;
    constant[3].border.width = unit * 2;
    constant[3].pos.x = start + (constant[3].border.width - constant[3].ContentLength) / 2;
    start = start + unit * 2;

    constant[4].border.x = start;
    constant[4].border.width = unit * 3;
    constant[4].pos.x = start + (constant[4].border.width - constant[4].ContentLength) / 2;
}

void StageScene::draw() {
    short i;
    for (i = 0; i < 5; i ++) {
        if (i == 0)
            DrawRectangleRec (constant[i].border, constant[i].BorderColor);
        else
            DrawRectangleLinesEx (constant[i].border, constant[i].FontSize / 10, constant[i].BorderColor);
        DrawText (constant[i].content, constant[i].pos.x, constant[i].pos.y, constant[i].FontSize, constant[i].FontColor);
    }
}

void LeaderboardSceen::setup() {
    isSet = 1;
    selector = 0;
    short i;
    
    addText (stages[0].constant[0].content, "EASY GAME");
    addText (stages[1].constant[0].content, "MEDIUM RARE");
    addText (stages[2].constant[0].content, "HARDCORE");

    for (i = 0; i < 3; i ++) {
        stages[i].setup();
        stages[i].constant[0].ContentLength = MeasureText (stages[i].constant[0].content, stages[i].constant[0].FontSize);
        stages[i].constant[0].pos.x = (float(WinWdith) - stages[i].constant[0].ContentLength) / 2;
    }
}

Scene LeaderboardSceen::draw() {
    ClearBackground(WHITE);

    moveSelector1D (selector, 0, 2);
    stages[selector].draw();

    if (IsKeyPressed(KEY_ENTER)) {
        isSet = 0;
        return MENU;
    }

    return RANK;
}