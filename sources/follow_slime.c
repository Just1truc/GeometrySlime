/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** function that make the camera follow the slime
*/

#include "my_runner.h"

void reposition_camera(game_t *game)
{
    if (game->slime_pos.y <= game->window_pos.y + 100) {
        game->window_pos.y -= -game->gravity;
        game->background_pos.y -= -game->gravity;
        game->middleground_pos.y -= -game->gravity;
        game->view_move.y = -(-game->gravity);
    } else if (game->slime_pos.y >= game->window_pos.y + HEIGHT - 300) {
        game->window_pos.y += -game->gravity;
        game->background_pos.y += -game->gravity;
        game->middleground_pos.y += -game->gravity;
        game->view_move.y = -game->gravity;
    } else {
        game->view_move.y = 0;
    }
}
