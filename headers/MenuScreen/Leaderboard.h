#pragma once
#include "../Moving.h"
#include "Account.h"
#include "../GamePlay/Music.h"
struct Player {
    short score;                              //Score the player have got
    Time time;                                //Time the player have played
    TextBox rank, name, ScoreText, TimeText;  //The textboxes to show information of the player: rank, name, score and time
};

struct PlayerNode {
    Player data;       //Information of the player
    PlayerNode *next;  //The pointer points to next node of the Linked List

    //Get information of a player into a node 
    PlayerNode (Player input) {
        data.score = input.score;
        data.time.hour = input.time.hour;
        data.time.min = input.time.min;
        data.time.sec = input.time.sec;
        addText (data.name.content, input.name.content);
        addText (data.ScoreText.content, input.ScoreText.content);
        addText (data.TimeText.content, input.TimeText.content); 
        next = NULL;
    }
};

//Make a Singly Linked List as a list of the players
struct PlayerList {
    PlayerNode *head, *tail;
};


struct StageScene {
    const Color background = WHITE;
    TextBox constant[5];               //Textboxes to illustrate of the players
    PlayerList list;                   //A list of the players
    short lengthList;                  //Number of players in the list
    void getList(const Level& level);  //Get the correct list of a specific challenge (EASY< MEDIUM RARE or HARDCORE)
    void setup(const Level& level);    //Get all the neccessay contents and the locations of the textboxes

    //Draw the shape of the textboxes, draw the words, fill colors to all of them and add music and sounds
    void draw();
};

struct LeaderboardSceen {
    bool isSet = 0;
    StageScene stages[3];                 //Three leaderboards for three challenges
    short selector;                       //A tool to move and control the cursor
    void setup();                         //Get all the neccessay contents and the locations of the textboxes

    //Draw the shape of the textboxes, draw the words, fill colors to all of them and add music and sounds
    Scene draw(gameMusic& musicAndSound);
};