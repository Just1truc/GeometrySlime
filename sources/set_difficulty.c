/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** set difficulty
*/

#include "my_runner.h"

void set_difficulty(sfVector2i mouse_pos, game_t *game)
{
    if (mouse_pos.x >= 420 && mouse_pos.x <= 650 && mouse_pos.y >= 125
    && mouse_pos.y <= 200 && game->game_screen == DIFFICULTY) {
        game->arrow_pos.y = 125;
        game->difficulty = EASY;
    }
    if (mouse_pos.x >= 420 && mouse_pos.x <= 650 && mouse_pos.y >= 505
    && mouse_pos.y <= 580 && game->game_screen == DIFFICULTY) {
        game->arrow_pos.y = 500;
        game->difficulty = HARD;
    }
    if (mouse_pos.x >= 360 && mouse_pos.x <= 710 && mouse_pos.y >= 315
    && mouse_pos.y <= 390 && game->game_screen == DIFFICULTY) {
        game->arrow_pos.y = 310;
        game->difficulty = NORMAL;
    }
}
