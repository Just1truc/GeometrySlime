/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** init colors
*/

#include "my_runner.h"

void set_colors(game_t *game)
{
    sfSprite_setColor(game->sprites->background_sprite,
    game->background_color);
    sfSprite_setColor(game->sprites->ground_sprite,
    game->ground_color);
    sfSprite_setColor(game->sprites->slime_sprite,
    game->slime_color);
    game->background_color.a = 150;
    sfSprite_setColor(game->sprites->middleground_sprite,
    game->background_color);
    game->jump_phase = 0;
}
