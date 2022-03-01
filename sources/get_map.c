/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** get map from args
*/

#include "my_runner.h"

void check_ground_type(game_t *game, pos_t *pos, char *buffer)
{
    if (check_up(game, pos) == 0) {
        get_under_air_ground(game, pos, buffer);
    } else if (buffer[pos->i - 1] == ' ' && buffer[pos->i + 1] == ' ')
        game->map[pos->b].value = UP_GROUND_ID;
    else
        game->map[pos->b].value = UNDERGROUND_ID;
}

void set_element(game_t *game, pos_t *pos, char *buffer)
{
    if (buffer[pos->i] == '1') {
        check_ground_type(game, pos, buffer);
    } else
        game->map[pos->b].value = buffer[pos->i] - '0';
    game->map[pos->b].pos.x = pos->x * 100 - 100;
    game->map[pos->b].pos.y = pos->y * 100 + (HEIGHT - pos->height);
    game->map[pos->b].state = 1;
}

void check_element(game_t *game, pos_t *pos, char *buffer)
{
    if (buffer[pos->i - 1] == '\n') {
        pos->y++;
        pos->x = 0;
    }
    if (buffer[pos->i] >= '0' && buffer[pos->i] <= '9') {
        set_element(game, pos, buffer);
        pos->b++;
    }
    pos->x++;
}

pos_t *initialize_pos_struct(pos_t *pos, char **ag)
{
    pos = malloc(sizeof(pos_t));
    pos->x = 0;
    pos->y = 0;
    pos->b = 0;
    pos->height = get_height(ag) * 100;
    return pos;
}

void get_map(game_t *game, char **ag)
{
    int i;
    int val = open(ag[1], O_RDONLY);
    char buffer[30000];
    int len = read(val, buffer, 29999);
    int b = 0;
    pos_t *pos;
    pos = initialize_pos_struct(pos, ag);
    game->object_nbr = get_nbr_of_objects(ag);
    game->map = malloc(sizeof(map_c_t) * (game->object_nbr + 1));
    buffer[len] = '\0';
    for (pos->i = get_map_begin(ag); buffer[pos->i] != '\0'; pos->i++) {
        check_element(game, pos, buffer);
    }
    close(val);
    free(pos);
}
