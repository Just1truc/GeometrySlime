/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** load map
*/

#include "my_runner.h"

void load_map_third(game_t *game, info_t *inf)
{
    if (game->map[inf->i].value == COIN_ID && game->map[inf->i].state >= 0) {
        inf->rect = get_rect(0, game->map[inf->i].state * 100 + 400, 100, 100);
        display_element(game, inf, game->sprites->monster_sprite,
        game->monster_texture);
    }
    if (game->map[inf->i].value == JUMP_PAD_ID) {
        inf->rect = get_rect(0, 800, 100, 100);
        display_element(game, inf, game->sprites->ground_sprite,
        game->ground_texture);
    }
    if (game->map[inf->i].value == MALUS_ID && game->map[inf->i].state >= 0) {
        inf->rect = get_rect(0, game->map[inf->i].state * 100 + 1200,
        100, 100);
        display_element(game, inf, game->sprites->monster_sprite,
        game->monster_texture);
    }
}

void load_map_second(game_t *game, info_t *inf)
{
    if (game->map[inf->i].value == LONELY_GROUND_ID) {
        inf->rect = get_rect(0, 200, 100, 100);
        display_element(game, inf,
        game->sprites->ground_sprite, game->ground_texture);
    }
    if (game->map[inf->i].value == PLATFORM_ID) {
        inf->rect = get_rect(0, 600, 100, 100);
        display_element(game, inf,
        game->sprites->ground_sprite, game->ground_texture);
    }
    if (game->map[inf->i].value == MONSTER_ID) {
        inf->rect = get_rect(0, game->map[inf->i].state * 100, 100, 100);
        display_element(game, inf,
        game->sprites->monster_sprite, game->monster_texture);
    }
}

void load_map_first(game_t *game, info_t *inf)
{
    if (game->map[inf->i].value == BASE_GROUND_ID) {
        inf->rect = get_rect(0, 0, 100, 100);
        display_element(game, inf,
        game->sprites->ground_sprite, game->ground_texture);
    }
    if (game->map[inf->i].value == LEFT_UP_GROUND_ID) {
        inf->rect = get_rect(0, 100, 100, 100);
        display_element(game, inf,
        game->sprites->ground_sprite, game->ground_texture);
    }
    if (game->map[inf->i].value == RIGHT_UP_GROUND_ID) {
        inf->rect = get_rect(0, 400, 100, 100);
        display_element(game, inf,
        game->sprites->ground_sprite, game->ground_texture);
    }
    if (game->map[inf->i].value == UP_GROUND_ID) {
        inf->rect = get_rect(0, 300, 100, 100);
        display_element(game, inf,
        game->sprites->ground_sprite, game->ground_texture);
    }
}

void load_map(game_t *game)
{
    info_t *inf = malloc(sizeof(info_t));

    for (inf->i = 0; inf->i < game->object_nbr; inf->i++) {
        load_map_first(game, inf);
        load_map_second(game, inf);
        load_map_third(game, inf);
        load_map_fourth(game, inf);
    }
    free(inf);
}

void move_map(game_t *game)
{
    int i;

    for (i = 0; i < game->object_nbr; i++) {
        game->map[i].pos.x -= (game->difficulty + 1) * 3;
    }
}
