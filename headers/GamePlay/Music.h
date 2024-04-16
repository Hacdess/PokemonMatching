#pragma once
#include "raylib.h"

struct gameMusic
{
    Music themeMusic;
    Sound correctMatching;
    Sound wrongMatching ;
    Sound winning ;
    Sound losing;
    Sound pressButton;
    Sound wrongSign;
    Sound moving;

    void initMusicAndSound();
    void deleteMusicAndSound();
    void updateMusicStream(Music &musicPlay, float &timePlayed);
};


