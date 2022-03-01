/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** check if player is falling
*/

#include "my_runner.h"

void apply_gravity(game_t *game)
{
    if (check_colision(game) == 0) {
        game->slime_pos.y -= game->gravity;
        sfSprite_rotate(game->sprites->slime_sprite, 4.5);
        game->rotation_angle += 4.5;
    }
}
