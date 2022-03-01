/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** runner
*/

#include "my_runner.h"

int get_perfect_spawn(game_t *game)
{
    int i;

    for (i = 0; i < game->object_nbr; i++) {
        if (game->map[i].pos.x >= 50 && game->map[i].pos.x <= 150)
            return (i);
    }
}
