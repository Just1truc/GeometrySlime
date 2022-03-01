/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** display middle ground
*/

#include "my_runner.h"

void display_middleground(game_t *game)
{
    sfSprite_setPosition(game->sprites->middleground_sprite,
    game->middleground_pos);
    sfRenderWindow_drawSprite(game->window,
    game->sprites->middleground_sprite, NULL);
    game->middleground_pos.x += WIDTH;
    sfSprite_setPosition(game->sprites->middleground_sprite,
    game->middleground_pos);
    sfRenderWindow_drawSprite(game->window,
    game->sprites->middleground_sprite, NULL);
    game->middleground_pos.x -= WIDTH;
}

void move_middleground(game_t *game)
{
    if (game->middleground_pos.x <=
    -WIDTH + game->window_pos.x - game->view_move.x)
        game->middleground_pos.x = game->window_pos.x -
        game->view_move.x;
    game->middleground_pos.x += game->view_move.x - 2;
}
