#include "../headers/sounds.h"

sound::sound()
{
    InitAudioDevice();
    game_over_sound = LoadSound(GAME_OVER_SOUND);
    collectable_sound = LoadSound(COLLECTABLE_SOUND);
    game_music = LoadMusicStream(GAME_MUSIC_SOUND);
}

void sound::PlayGameOverSound()
{
    PlaySound(game_over_sound);
}

void sound::PlayGameMusic()
{
    PlayMusicStream(game_music);
}

void sound::PlayCollectableSound()
{
    PlaySound(collectable_sound);
}

sound::~sound()
{
    UnloadSound(game_over_sound);
    UnloadSound(collectable_sound);
    UnloadMusicStream(game_music);
    CloseAudioDevice();
}