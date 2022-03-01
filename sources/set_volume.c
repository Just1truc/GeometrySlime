/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** set volume
*/

#include "my_runner.h"

void set_volume(game_t *game)
{
    sfMusic_setVolume(game->background_music, game->music_volume);
    sfSound_setVolume(game->death_sound, game->sound_volume);
    sfSound_setVolume(game->coin_sound, game->sound_volume);
    sfSound_setVolume(game->victory_sound, game->sound_volume);
    sfSound_setVolume(game->wrong_sound, game->sound_volume);
}
