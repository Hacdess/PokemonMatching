#pragma once
#include "raylib.h"

struct gameMusic
{
    Music themeMusic;      //Music background for the game. It's played when players at Menu Screen and paused when playing game
    Sound correctMatching; //Sound when players match correctly a pair of Pokemon
    Sound wrongMatching ;  //Sound when players match incorrectly a pair of Pokemon
    Sound winning ;        //Sound when players win the game
    Sound losing;          //Sound when players lose the game
    Sound pressButton;     //Sound when players press Enter at a button
    Sound wrongSign;       //Sound when players press Enter at button Sign in/Sign up but have wrong/invalid accounts 
    Sound moving;          //Sound when players move the cursor

    void initMusicAndSound();   //Upload music and sound data
    void deleteMusicAndSound(); //Unload music and sound data 
    void updateMusicStream(Music &musicPlay, float &timePlayed);  //Update the music stream
};


