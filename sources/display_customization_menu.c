/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** display the menu of customization
*/

#include "my_runner.h"

void display_custom_menu_next(game_t *game)
{
    sfSprite_setPosition(game->sprites->slime_sprite, game->slime_pos);
    sfRenderWindow_drawSprite(game->window, game->sprites->slime_sprite, NULL);
    sfSprite_setPosition(game->sprites->selection_sprite,
    game->selection_one_pos);
    sfRenderWindow_drawSprite(game->window,
    game->sprites->selection_sprite, NULL);
    sfSprite_setPosition(game->sprites->selection_sprite,
    game->selection_two_pos);
    sfRenderWindow_drawSprite(game->window,
    game->sprites->selection_sprite, NULL);
    sfSprite_setPosition(game->sprites->selection_sprite,
    game->selection_three_pos);
    sfRenderWindow_drawSprite(game->window,
    game->sprites->selection_sprite, NULL);
}

void display_bars_at_once(game_t *game)
{
    sfSprite_setPosition(game->sprites->bar_sprite, get_pos(400, 360));
    game->red_color.g = 0;
    game->red_color.r = 255;
    sfSprite_setColor(game->sprites->bar_sprite, game->red_color);
    sfRenderWindow_drawSprite(game->window, game->sprites->bar_sprite, NULL);
    sfSprite_setPosition(game->sprites->bar_sprite, get_pos(400, 460));
    game->red_color.r = 0;
    game->red_color.b = 255;
    sfSprite_setColor(game->sprites->bar_sprite, game->red_color);
    sfRenderWindow_drawSprite(game->window, game->sprites->bar_sprite, NULL);
    sfSprite_setPosition(game->sprites->bar_sprite, get_pos(400, 560));
    game->red_color.b = 0;
    game->red_color.g = 255;
    sfSprite_setColor(game->sprites->bar_sprite, game->red_color);
    sfRenderWindow_drawSprite(game->window, game->sprites->bar_sprite, NULL);
}

void display_customization_menu(game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    game->slime_pos.x = 475;
    game->slime_pos.y = 160;
    move_background(game, -WIDTH, 0, 3);
    display_background(game);
    sfSprite_setPosition(game->sprites->back_sprite, get_pos(0, 0));
    sfRenderWindow_drawSprite(game->window, game->sprites->back_sprite, NULL);
    display_bars_at_once(game);
    sfSprite_setColor(game->sprites->slime_sprite, game->slime_color);
    display_custom_menu_next(game);
    sfRenderWindow_display(game->window);
}
