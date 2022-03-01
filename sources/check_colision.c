/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** check colision
*/

#include "my_runner.h"

int check_platform_colision(game_t *game, int i)
{
    if (game->slime_pos.y >= game->map[i].pos.y - 90
    && game->slime_pos.y <= game->map[i].pos.y
    && game->slime_pos.x >= game->map[i].pos.x - 120
    && game->slime_pos.x <= game->map[i].pos.x + 50
    && game->map[i].value == PLATFORM_ID) {
        game->alive = 0;
        return (1);
    }
    return (0);
}

void check_jump_pad_colision(game_t *game, int i)
{
    if (game->slime_pos.y >= game->map[i].pos.y - 20
    && game->slime_pos.y <= game->map[i].pos.y
    && game->slime_pos.x >= game->map[i].pos.x - 100
    && game->slime_pos.x <= game->map[i].pos.x + 30
    && game->map[i].value == JUMP_PAD_ID) {
        game->is_jumping = 1;
        game->jump_pos.y = -35;
    }
}

void check_coin_colision(game_t *game, int i)
{
    if (((game->slime_pos.x >= game->map[i].pos.x - 100
    && game->slime_pos.x <= game->map[i].pos.x + 100
    && game->slime_pos.y >= game->map[i].pos.y - 90
    && game->slime_pos.y <= game->map[i].pos.y)
    || (game->slime_pos.y >= game->map[i].pos.y
    && game->slime_pos.y <= game->map[i].pos.y + 90
    && game->slime_pos.x >= game->map[i].pos.x - 100
    && game->slime_pos.x <= game->map[i].pos.x + 100))
    && game->map[i].value == COIN_ID
    && game->map[i].state >= 0) {
        game->map[i].state = -6;
        game->stats->score += 1;
        sfSound_play(game->coin_sound);
    }
}

void check_malus_colision(game_t *game, int i)
{
    if (((game->slime_pos.x >= game->map[i].pos.x - 100
    && game->slime_pos.x <= game->map[i].pos.x + 100
    && game->slime_pos.y >= game->map[i].pos.y - 90
    && game->slime_pos.y <= game->map[i].pos.y)
    || (game->slime_pos.y >= game->map[i].pos.y
    && game->slime_pos.y <= game->map[i].pos.y + 90
    && game->slime_pos.x >= game->map[i].pos.x - 100
    && game->slime_pos.x <= game->map[i].pos.x + 100))
    && game->map[i].value == MALUS_ID
    && game->map[i].state >= 0) {
        game->map[i].state = -6;
        game->stats->score -= 1;
        sfSound_play(game->wrong_sound);
    }
}

int check_death(game_t *game)
{
    int i;
    for (i = 0; i < game->object_nbr; i++) {
        if (check_end_colision(game, i) == 1)
            return (1);
        if (check_ground_colision(game, i) == 1)
            return (1);
        if (check_colision_from_under(game, i) == 1)
            return (1);
        if (check_monster_colision(game, i) == 1)
            return (1);
        if (check_saw_colision(game, i) == 1)
            return (1);
        if (check_platform_colision(game, i) == 1)
            return (1);
        check_jump_pad_colision(game, i);
        check_coin_colision(game, i);
        check_malus_colision(game, i);
    }
    return (0);
}
