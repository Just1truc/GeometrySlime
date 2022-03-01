/*
** EPITECH PROJECT, 2021
** my_runnre
** File description:
** get the best score
*/

#include "my_runner.h"

void change_best_score(game_t *game)
{
    int fd = open("scores/score.txt", O_WRONLY);

    if (game->stats->score > game->stats->best_score) {
        game->result = my_conv(game->stats->score, 10);
        write(fd, game->result, my_strlen(game->result));
        free(game->result);
        game->stats->best_score = game->stats->score;
    }
    close(fd);
}
