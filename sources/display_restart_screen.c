/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** display restart screen
*/

#include "my_runner.h"

void display_restart_menu(game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    game->background_pos.y = 0;
    game->view_rect.top = 0;
    sfView_reset(game->view, game->view_rect);
    sfRenderWindow_setView(game->window, game->view);
    move_background(game, -WIDTH, 0, 3);
    display_background(game);
    sfSprite_setPosition(game->sprites->restart_sprite, get_pos(0, 0));
    sfRenderWindow_drawSprite(game->window,
    game->sprites->restart_sprite, NULL);
    sfRenderWindow_display(game->window);
}
