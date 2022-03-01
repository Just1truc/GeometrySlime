/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** event for the pause menu
*/

#include "my_runner.h"

void get_event_pause_menu(sfVector2i mouse_pos, game_t *game)
{
    if (mouse_pos.x >= 470 && mouse_pos.x <= 570 && mouse_pos.y >= 310
    && mouse_pos.y <= 410 && game->game_screen == GAME
    && game->pause == 1) {
        game->pause = 0;
        sfMusic_play(game->background_music);
    }
    if (mouse_pos.x >= 0 && mouse_pos.x <= 100 && mouse_pos.y >= 0
    && mouse_pos.y <= 100 && game->game_screen == GAME
    && game->pause == 0) {
        game->pause = 1;
        sfMusic_pause(game->background_music);
    }
}
