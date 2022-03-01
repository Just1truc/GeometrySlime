/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** display options menu
*/

#include "my_runner.h"

void display_option_menu(game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    move_background(game, -WIDTH, 0, 3);
    display_background(game);
    sfSprite_setPosition(game->sprites->options_sprite, get_pos(0, 0));
    sfRenderWindow_drawSprite(game->window,
    game->sprites->options_sprite, NULL);
    sfSprite_setPosition(game->sprites->back_sprite, get_pos(0, 0));
    sfRenderWindow_drawSprite(game->window, game->sprites->back_sprite, NULL);
    sfRenderWindow_display(game->window);
}
