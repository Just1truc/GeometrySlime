/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** draw slime depending of rotation
*/

#include "my_runner.h"

void draw_slime(game_t *game)
{
    sfSprite_setOrigin(game->sprites->slime_sprite,
    (sfVector2f){50, 50});
    sfSprite_setPosition(game->sprites->slime_sprite,
    get_pos(game->slime_pos.x + 50, game->slime_pos.y + 50));
    sfRenderWindow_drawSprite(game->window,
    game->sprites->slime_sprite, NULL);
    sfSprite_setOrigin(game->sprites->slime_sprite,
    (sfVector2f){0, 0});
}
