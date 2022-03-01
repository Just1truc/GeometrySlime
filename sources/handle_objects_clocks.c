/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** handle clocks
*/

#include "my_runner.h"

void handle_obj_clocks(game_t *game)
{
    game->time2 = sfClock_getElapsedTime(game->monster_clock);
    game->seconds = game->time2.microseconds / 1000000.0;
    game->saw_seconds += game->seconds;
    game->coin_seconds += game->seconds;
    if (game->seconds >= 0.5) {
        change_state(game, MONSTER_ID, 1);
        change_state(game, MALUS_ID, 1);
        sfClock_restart(game->monster_clock);
    }
    if (game->saw_seconds >= 0.1) {
        change_state(game, SAW_ID, 1);
        game->saw_seconds = 0;
    }
    if (game->coin_seconds >= 0.5) {
        change_state(game, COIN_ID, 7);
        game->coin_seconds = 0;
    }
}
