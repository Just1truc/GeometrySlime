/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** make the slime jump
*/

#include "my_runner.h"

void check_jump(game_t *game)
{
    if (game->is_jumping == 1) {
        game->slime_pos.y += game->jump_pos.y;
        game->jump_pos.y -= -1;
        if (check_colision(game) == 1) {
            game->is_jumping = 0;
        }
    }
}
