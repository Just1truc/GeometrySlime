/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** initialize sound buffer and musics
*/

#include "my_runner.h"

void initialize_sounds(game_t *game)
{
    game->coin_buffer =
    sfSoundBuffer_createFromFile("assets/coin_sound_effect.wav");
    game->death_buffer =
    sfSoundBuffer_createFromFile("assets/death_sound.wav");
    game->background_music =
    sfMusic_createFromFile("assets/background_music.ogg");
    game->wrong_buffer =
    sfSoundBuffer_createFromFile("assets/wrong.wav");
    game->victory_buffer =
    sfSoundBuffer_createFromFile("assets/victory-sound-effect.wav");
}
