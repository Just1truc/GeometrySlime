/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** check pause
*/

#include "my_runner.h"

void check_pause(game_t *game)
{
    if (game->pause == 0)
        game->pause = 1;
    else
        game->pause = 0;
}
