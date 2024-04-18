#include "../headers/Music.h"


void gameMusic::initMusicAndSound()
{
    //Open the audio of the device
    InitAudioDevice();

    //Upload file mp3 and file wav
    themeMusic = LoadMusicStream("Source/Sound/themeMusic.mp3");
    correctMatching = LoadSound("Source/Sound/correctMatching.wav");
    wrongMatching = LoadSound("Source/Sound/WrongMatching.wav");
    winning = LoadSound("Source/Sound/winning.wav");
    losing = LoadSound("Source/Sound/Losing.wav");
    pressButton = LoadSound("Source/Sound/PressButton.wav");
    wrongSign = LoadSound("Source/Sound/wrongSign.wav");
    moving = LoadSound("Source/Sound/Moving.wav");
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