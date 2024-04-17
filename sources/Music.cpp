#include "../headers/GamePlay/Music.h"


void gameMusic::initMusicAndSound()
{
    //Open the audio of the device
    InitAudioDevice();

    //Upload file mp3 and file wav
    themeMusic = LoadMusicStream("resources/Sound/themeMusic.mp3");
    correctMatching = LoadSound("resources/Sound/correctMatching.wav");
    wrongMatching = LoadSound("resources/Sound/WrongMatching.wav");
    winning = LoadSound("resources/Sound/winning.wav");
    losing = LoadSound("resources/Sound/Losing.wav");
    pressButton = LoadSound("resources/Sound/PressButton.wav");
    wrongSign = LoadSound("resources/Sound/wrongSign.wav");
    moving = LoadSound("resources/Sound/Moving.wav");
}

void gameMusic::deleteMusicAndSound()
{
    //Unload file mp3 and file wav
    UnloadMusicStream(themeMusic);
    UnloadSound(correctMatching);
    UnloadSound(wrongMatching);
    UnloadSound(winning);
    UnloadSound(losing);
    UnloadSound(pressButton);
    UnloadSound(wrongSign);
    UnloadSound(moving);
    CloseAudioDevice();
}

void gameMusic::updateMusicStream(Music &musicPlay, float &timePlayed)
{
    UpdateMusicStream(musicPlay);   // Update music buffer with new stream data

    // Get normalized time played for current music stream
    timePlayed = GetMusicTimePlayed(musicPlay)/GetMusicTimeLength(musicPlay);

    if (timePlayed > 1.0f) timePlayed = 1.0f;   // Make sure time played is no longer than music
}