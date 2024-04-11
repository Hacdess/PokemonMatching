#include "../headers/MenuScreen/Leaderboard.h"

void addHead (PlayerList& list, Player input) {
    PlayerNode* player = new PlayerNode(input);
    player -> next = list.head;
    list.head = player;
    if (!player -> next)
        list.tail = player;
}

void addTail (PlayerList& list, Player input) {
    PlayerNode* player = new PlayerNode(input);
    player -> prev = list.tail;
    list.tail = player;
    if (!player -> prev)
        list.tail = player;
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

    //Ignore the first line
    string temp;
    getline(fin, temp);

    Player input;

    while (!fin.eof()) {
        //Get the stage and compare
        getline (fin, temp, ',');

        if (temp == checkLevel) {
            //Get username
            getline (fin, temp, ',');
            input.name.content = StoA (temp);
            //Get score
            fin >> input.score;
            fin.ignore();
            temp = to_string (input.score);
            input.ScoreText.content = StoA (temp);
            //Get time
            fin >> input.time.hour;
            fin.ignore();
            fin >> input.time.min;
            fin.ignore();
            fin >> input.time.sec;
            fin.ignore();
            temp = TimeToString (input.time);
            input.TimeText.content = StoA (temp);

            addHead (list, input);
        }

        else {
            fin >> temp;
            fin.ignore();
        }
    }

    fin.close();
}

void copyPlayer (Player& dest, Player source) {
    dest.score = source.score;
    dest.time.hour = source.time.hour;
    dest.time.min = source.time.min;
    dest.time.sec = source.time.sec;
    strcpy (dest.name.content, source.name.content);
    strcpy (dest.ScoreText.content, source.ScoreText.content);
    strcpy (dest.TimeText.content, source.TimeText.content);
}

void sortList (PlayerList& list) {
    if (!list.head || !list.head -> next)
        return;

    PlayerNode *i = list.head -> next, *j;
    Player key;

    while (i) {
        j = i -> prev;
        copyPlayer (key, i -> data);
        
        while (j) {
            if (j -> data.score < key.score)
                copyPlayer (j -> next -> data, j -> data);
            else if (j -> data.score == key.score)
                if (compareTime(j -> data.time, key.time) > 0)
                    copyPlayer (j -> next -> data, j -> data);
            else
                copyPlayer (j -> next -> data, key);
            
            j = j -> prev;
        }

        i = i -> next;
    }
} 

void StageScene::setup(const Level& level) {
    short i, count;
    //Constant[0] is the level
    constant[0].FontSize = float(WinHeight) / 10;
    constant[0].FontColor = RED;
    constant[0].border = {0, 0, float(WinWdith), constant[0].FontSize * 1.2f};
    constant[0].pos.y = (constant[0].border.height - constant[0].FontSize) / 2;
    constant[0].BorderColor = DarkCyan;

    list.head = NULL;
    list.tail = NULL;

    //Get list players' results
    getList (level);
    sortList (list);

    //Category bar
    addText (constant[1].content, "Rank");
    addText (constant[2].content, "Player");
    addText (constant[3].content, "Score");
    addText (constant[4].content, "Play Time");

    float unit = float(WinWdith) / 9, startX = 0, startY, width = unit;
                
    for (i = 1; i < 5; i ++) {
        constant[i].FontSize = float(WinHeight) / 15;
        constant[i].FontColor = BLUE;
        constant[i].BorderColor = DarkCyan;
        constant[i].border.y = constant[0].border.y + constant[0].border.height;
        constant[i].border.height = constant[i].FontSize * 1.1f;
        constant[i].pos.y = constant[i].border.y + (constant[i].border.height - constant[i].FontSize) / 2;
        constant[i].ContentLength = MeasureText (constant[i].content, constant[i].FontSize);
        constant[i].border.x = startX;
        constant[i].border.width = width;
        constant[i].pos.x = startX + (width - constant[i].ContentLength) / 2;

        //Set the position of the top 10 players
        startY = constant[i].border.y + constant[i].border.height;

        count = 0;
        PlayerNode* cur = list.head;
        
        while (cur && count < 10) {
            if (i == 1) {
                cur -> data.rank.border = {startX, startY, width, constant[i].border.height * 0.8f};
                cur -> data.rank.content = StoA (to_string (count + 1));
                cur -> data.rank.FontColor = RED;
                cur -> data.rank.FontSize = constant[i].FontSize * 0.8f;
                cur -> data.rank.ContentLength = MeasureText (cur -> data.rank.content, cur -> data.rank.FontSize);
                cur -> data.rank.pos = {startX + (width - cur -> data.rank.ContentLength) / 2, startY + (constant[i].border.height * 0.8f - cur -> data.rank.FontSize) / 2};
            }

            if (i == 2) {
                cur -> data.name.border = {startX, startY, width, constant[i].border.height * 0.8f};
                cur -> data.name.FontColor = BLACK;
                cur -> data.name.FontSize = constant[i].FontSize * 0.8f;
                cur -> data.name.ContentLength = MeasureText (cur -> data.name.content, cur -> data.name.FontSize);
                cur -> data.name.pos = {startX + (width - cur -> data.name.ContentLength) / 2, startY + (constant[i].border.height * 0.8f - cur -> data.name.FontSize) / 2};
            }

            if (i == 3) {
                cur -> data.ScoreText.border = {startX, startY, width, constant[i].border.height * 0.8f};
                cur -> data.ScoreText.FontColor = BLACK;
                cur -> data.ScoreText.FontSize = constant[i].FontSize * 0.8f;
                cur -> data.ScoreText.ContentLength = MeasureText (cur -> data.ScoreText.content, cur -> data.ScoreText.FontSize);
                cur -> data.ScoreText.pos = {startX + (width - cur -> data.ScoreText.ContentLength) /2, startY + (constant[i].border.height * 0.8f - cur -> data.ScoreText.FontSize) / 2};
            }

            if (i == 4) {
                cur -> data.TimeText.border = {startX, startY, width, constant[i].border.height * 0.8f};
                cur -> data.TimeText.FontColor = BLACK;
                cur -> data.TimeText.FontSize = constant[i].FontSize * 0.8f;
                cur -> data.TimeText.ContentLength = MeasureText (cur -> data.TimeText.content, cur -> data.TimeText.FontSize);
                cur -> data.TimeText.pos = {startX + (width - cur -> data.TimeText.ContentLength) / 2, startY + (constant[i].border.height * 0.8f - cur -> data.TimeText.FontSize) / 2};
            }

            startY += constant[i].border.height;
            cur = cur -> next;
            count ++;
        }


        startX += width;
        if (i == 1)
            width = unit * 3;
        if (i == 2)
            width = unit * 2;
        if (i == 3)
            width = unit * 3;
    }
}

void StageScene::draw() {
    short i, count = 0;
    for (i = 0; i < 5; i ++) {
        if (i == 0)
            DrawRectangleRec (constant[i].border, constant[i].BorderColor);
        else
            DrawRectangleLinesEx (constant[i].border, constant[i].FontSize / 10, constant[i].BorderColor);
        DrawText (constant[i].content, constant[i].pos.x, constant[i].pos.y, constant[i].FontSize, constant[i].FontColor);
    }

    PlayerNode* cur = list.head;

    //Draw top 10 players
    while (cur && count < 10) {
        DrawText (cur -> data.rank.content, cur -> data.rank.pos.x, cur -> data.rank.pos.y, cur -> data.rank.FontSize, cur -> data.rank.FontColor);
        DrawText (cur -> data.name.content, cur -> data.name.pos.x, cur -> data.name.pos.y, cur -> data.name.FontSize, cur -> data.name.FontColor);
        DrawText (cur -> data.ScoreText.content, cur -> data.ScoreText.pos.x, cur -> data.ScoreText.pos.y, cur -> data.ScoreText.FontSize, cur -> data.ScoreText.FontColor);
        DrawText (cur -> data.TimeText.content, cur -> data.TimeText.pos.x, cur -> data.TimeText.pos.y, cur -> data.TimeText.FontSize, cur -> data.TimeText.FontColor);
        cout << cur -> data.rank.content << " - ";
        cout << cur -> data.name.content << " - ";
        cout << cur -> data.ScoreText.content << " - ";
        cout << cur -> data.TimeText.content << "\n\n";

        cur = cur -> next;
        count ++;
    }
}

void LeaderboardSceen::setup() {
    isSet = 1;
    selector = 0;
    short i;
    
    addText (stages[0].constant[0].content, "EASY GAME");
    addText (stages[1].constant[0].content, "MEDIUM RARE");
    addText (stages[2].constant[0].content, "HARDCORE");

    Level level;
    for (i = 0; i < 3; i ++) {
        if (i == 0)
            level = EASY;
        if (i == 1)
            level = MEDIUM;
        if (i == 2)
            level = HARD;
        stages[i].setup(level);
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