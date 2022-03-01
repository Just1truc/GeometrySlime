/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** handle menu ground display
*/

#include "my_runner.h"

void display_lower_ground(game_t *game)
{
    game->ground_pos.y += 100;
    sfSprite_setTexture(game->sprites->ground_sprite,
    game->ground_texture, sfFalse);
    sfSprite_setTextureRect(game->sprites->ground_sprite,
    get_rect(0, 500, 100, 100));
    sfSprite_setPosition(game->sprites->ground_sprite,
    game->ground_pos);
    sfRenderWindow_drawSprite(game->window,
    game->sprites->ground_sprite, NULL);
}

void display_upper_ground(game_t *game)
{
    sfSprite_setTexture(game->sprites->ground_sprite,
    game->ground_texture, sfFalse);
    sfSprite_setTextureRect(game->sprites->ground_sprite,
    get_rect(0, 0, 100, 100));
    sfSprite_setPosition(game->sprites->ground_sprite,
    game->ground_pos);
    sfRenderWindow_drawSprite(game->window,
    game->sprites->ground_sprite, NULL);
}

void display_basic_ground(game_t *game)
{
    int i;

    for (i = 0; i < WIDTH / 100 + 1; i++) {
        display_upper_ground(game);
        display_lower_ground(game);
        game->ground_pos.y -= 100;
        game->ground_pos.x += 100;
    }
    game->ground_pos.x -= i * 100;
}

void handle_moving_ground(game_t *game)
{
    if (game->ground_pos.x <= -WIDTH)
        game->ground_pos.x = 0;
    game->ground_pos.x -= 8;
    display_basic_ground(game);
    game->ground_pos.x += WIDTH;
    display_basic_ground(game);
    game->ground_pos.x -= WIDTH;
}
