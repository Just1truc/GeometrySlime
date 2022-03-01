/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** display menu screen
*/

#include "my_runner.h"

void display_menu(game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    move_background(game, -WIDTH, 0, 3);
    display_background(game);
    game->slime_pos.x = 50;
    sfSprite_setPosition(game->sprites->slime_sprite, get_pos(50, 420));
    handle_moving_ground(game);
    sfRenderWindow_drawSprite(game->window, game->sprites->slime_sprite, NULL);
    sfSprite_setPosition(game->sprites->play_button_sprite,
    game->play_button_pos);
    sfRenderWindow_drawSprite(game->window,
    game->sprites->play_button_sprite, NULL);
    sfSprite_setPosition(game->sprites->quit_sprite, get_pos(980, 620));
    sfRenderWindow_drawSprite(game->window, game->sprites->quit_sprite, NULL);
    sfRenderWindow_display(game->window);
}
