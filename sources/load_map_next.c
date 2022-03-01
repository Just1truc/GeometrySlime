/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** load map next
*/

#include "my_runner.h"

void load_map_fourth(game_t *game, info_t *inf)
{
    if (game->map[inf->i].value == SAW_ID) {
        inf->rect = get_rect(0, game->map[inf->i].state * 100 + 200, 100, 100);
        display_element(game, inf, game->sprites->monster_sprite,
        game->monster_texture);
    }
    if (game->map[inf->i].value == SPIKE_ID) {
        inf->rect = get_rect(0, 700, 100, 100);
        display_element(game, inf, game->sprites->ground_sprite,
        game->ground_texture);
    }
    if (game->map[inf->i].value == UNDERGROUND_ID) {
        inf->rect = get_rect(0, 500, 100, 100);
        display_element(game, inf, game->sprites->ground_sprite,
        game->ground_texture);
    }
}
