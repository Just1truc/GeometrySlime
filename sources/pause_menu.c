/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** pause menu
*/

#include "my_runner.h"

void display_pause_menu(game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    display_background(game);
    display_middleground(game);
    load_map(game);
    sfSprite_setTexture(game->sprites->pause_sprite,
    game->pause_texture, sfFalse);
    sfSprite_setTextureRect(game->sprites->pause_sprite,
    get_rect(0, 100, 100, 100));
    sfSprite_setPosition(game->sprites->pause_sprite,
    get_pos(game->window_pos.x + 470, game->window_pos.y + 310));
    sfRenderWindow_drawSprite(game->window,
    game->sprites->pause_sprite, NULL);
    draw_slime(game);
    sfRenderWindow_display(game->window);
}
