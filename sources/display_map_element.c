/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** display anelement form the map
*/

#include "my_runner.h"

void display_element(game_t *game, info_t *inf,
sfSprite *sprite, sfTexture *texture)
{
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setTextureRect(sprite, inf->rect);
    sfSprite_setPosition(sprite, game->map[inf->i].pos);
    sfRenderWindow_drawSprite(game->window, sprite, NULL);
}
