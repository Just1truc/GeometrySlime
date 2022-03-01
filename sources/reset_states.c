/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** reset_state
*/

#include "my_runner.h"

void reset_state(game_t *game)
{
    int i;

    for (i = 0; i < game->object_nbr; i++)
        game->map[i].state = 1;
}
