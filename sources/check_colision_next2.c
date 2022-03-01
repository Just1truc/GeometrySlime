/*
** EPITECH PROJECT, 2021
** my_runner check colision file 3
** File description:
** chcek colision
*/

#include "my_runner.h"

int check_monster_colision(game_t *game, int i)
{
    if (game->slime_pos.y >= game->map[i].pos.y - 100
    && game->slime_pos.y <= game->map[i].pos.y
    && game->slime_pos.x >= game->map[i].pos.x - 70
    && game->slime_pos.x <= game->map[i].pos.x + 30
    && (game->map[i].value == MONSTER_ID)) {
        game->alive = 0;
        return (1);
    }
    return (0);
}

int check_saw_colision(game_t *game, int i)
{
    if (game->slime_pos.y >= game->map[i].pos.y - 50
    && game->slime_pos.y <= game->map[i].pos.y
    && game->slime_pos.x >= game->map[i].pos.x - 100
    && game->slime_pos.x <= game->map[i].pos.x + 30
    && (game->map[i].value == SAW_ID)) {
        game->alive = 0;
        return (1);
    }
    return (0);
}
