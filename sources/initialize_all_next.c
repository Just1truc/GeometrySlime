/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** initialize everython next
*/

#include "my_runner.h"

void initialize_statistics(game_t *game)
{
    char buffer[30000];
    int fd = open("scores/score.txt", O_RDONLY);
    int len = read(fd, buffer, 10);
    char *best_score = malloc(sizeof(char) * 11);

    game->stats = malloc(sizeof(statis_t));
    buffer[len] = '\0';
    best_score[0] = '0';
    best_score[1] = '\0';
    best_score = my_strcpy(best_score, buffer);
    close(fd);
    game->stats->best_score = my_getnbr(best_score);
}

void initialize_rect(game_t *game)
{
    game->ground_rect.top = 0;
    game->ground_rect.left = 200;
    game->ground_rect.width = 100;
    game->ground_rect.height = 100;
    game->view_rect.top = 0;
    game->view_rect.left = 0;
    game->view_rect.width = 1080;
    game->view_rect.height = 720;
}
