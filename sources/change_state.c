/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** change monster state
*/

#include "my_runner.h"

void change_id_state(game_t *game, int i, int max_state)
{
    if (game->map[i].state == max_state)
        game->map[i].state = -1;
    game->map[i].state += 1;
}

void change_state(game_t *game, int ID, int max_state)
{
    int i;

    for (i = 0; i < game->object_nbr; i++) {
        if (game->map[i].value == ID && game->map[i].state >= 0) {
            change_id_state(game, i, max_state);
        }
    }
}
