#pragma once
#include "../include/raylib.h"

#define COLLECTABLE_SOUND "./Assets/sounds/collectable_sound.wav"
#define GAME_OVER_SOUND "./Assets/sounds/game_over_sound.wav"
#define GAME_MUSIC_SOUND "./Assets/sounds/game_music.wav"

class sound
{
public:
    sound();

    void PlayGameOverSound();
    void PlayGameMusic();
    void PlayCollectableSound();
    ~sound();

    Sound game_over_sound;
    Sound collectable_sound;
    Music game_music;
};