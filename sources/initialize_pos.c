/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** initialize positions
*/

#include "my_runner.h"

void initialize_pos_next(game_t *game)
{
    game->selection_one_pos.x = 385;
    game->selection_one_pos.y = 332;
    game->selection_two_pos.x = 385;
    game->selection_two_pos.y = 432;
    game->selection_three_pos.x = 620;
    game->selection_three_pos.y = 532;
    game->arrow_pos.x = 750;
    game->arrow_pos.y = 125;
    game->view_move.x = 1;
    game->view_move.y = 0;
    game->window_pos.x = 0;
    game->window_pos.y = 0;
    game->middleground_pos.x = 0;
    game->middleground_pos.y = 0;
}

void initialize_pos(game_t *game)
{
    game->slime_pos.x = 50;
    game->slime_pos.y = 420;
    game->background_pos.x = 0;
    game->background_pos.y = 0;
    game->ground_pos.x = 0;
    game->ground_pos.y = 520;
    game->monster_pos.x = 980;
    game->monster_pos.y = 420;
    game->play_button_pos.x = 245;
    game->play_button_pos.y = 120;
    game->bar_pos.x = 0;
    game->bar_pos.y = 0;
    initialize_pos_next(game);
}
