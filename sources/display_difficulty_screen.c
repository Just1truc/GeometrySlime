/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** display difficulty choice screen
*/

#include "my_runner.h"

void display_difficulty_menu(game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    move_background(game, -WIDTH, 0, 3);
    display_background(game);
    sfSprite_setPosition(game->sprites->back_sprite, game->window_pos);
    sfRenderWindow_drawSprite(game->window, game->sprites->back_sprite, NULL);
    game->bar_pos.x = 0;
    game->bar_pos.y = 0;
    sfSprite_setPosition(game->sprites->difficulty_sprite, game->bar_pos);
    sfRenderWindow_drawSprite(game->window,
    game->sprites->difficulty_sprite, NULL);
    sfSprite_setPosition(game->sprites->arrow_sprite, game->arrow_pos);
    sfRenderWindow_drawSprite(game->window, game->sprites->arrow_sprite, NULL);
    sfRenderWindow_display(game->window);
}
