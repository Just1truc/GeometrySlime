/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** display backgrounds depending of a given pos
*/

#include "my_runner.h"

void display_background(game_t *game)
{
    sfSprite_setPosition(game->sprites->background_sprite,
    game->background_pos);
    sfRenderWindow_drawSprite(game->window,
    game->sprites->background_sprite, NULL);
    game->background_pos.x += WIDTH;
    sfSprite_setPosition(game->sprites->background_sprite,
    game->background_pos);
    sfRenderWindow_drawSprite(game->window,
    game->sprites->background_sprite, NULL);
    game->background_pos.x -= WIDTH;
}

void move_background(game_t *game, int min, int reset, int speed)
{
    if (game->background_pos.x <= min)
        game->background_pos.x = reset;
    game->background_pos.x -= speed;
}
