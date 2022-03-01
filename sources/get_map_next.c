/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
**  get map next
*/

#include "my_runner.h"

int get_map_begin(char **ag)
{
    int val = open(ag[1], O_RDONLY);
    char buffer[30000];
    int len = read(val, buffer, 29999);
    int i;
    int last_back = 0;

    buffer[len] = '\0';
    for (i = 0; !(buffer[i] >= '0' && buffer[i] <= '9'); i++) {
        if (buffer[i] == '\n')
            last_back = i;
    }
    close(val);
    return (last_back + 1);
}

int get_nbr_of_objects(char **ag)
{
    int val = open(ag[1], O_RDONLY);
    char buffer[30000];
    int len = read(val, buffer, 29999);
    int i;
    int sum = 0;

    buffer[len] = '\0';
    for (i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] >= '0' && buffer[i] <= '9')
            sum++;
    }
    close(val);
    return (sum);
}

int get_height(char **ag)
{
    int begin = get_map_begin(ag);
    int val = open(ag[1], O_RDONLY);
    char buffer[30000];
    int len = read(val, buffer, 29999);
    int i;
    int lui = 0;

    buffer[len] = '\0';
    for (i = begin; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\n')
            lui++;
    }
    close(val);
    return (lui);
}

int check_up(game_t *game, pos_t *pos)
{
    int verify;
    int x = pos->x;
    int y = pos->y;

    for (verify = 0; verify < pos->b; verify++) {
        if (game->map[verify].pos.y == (HEIGHT - pos->height) + (y - 1) * 100
        && game->map[verify].pos.x == x * 100 - 100
        && game->map[verify].value != COIN_ID
        && game->map[verify].value != MALUS_ID) {
            return (1);
        }
    }
    return (0);
}

void get_under_air_ground(game_t *game, pos_t *pos, char *buffer)
{
    if (buffer[pos->i - 1] != ' ' && buffer[pos->i + 1] != ' ')
        game->map[pos->b].value = BASE_GROUND_ID;
    if (buffer[pos->i - 1] == ' ' && buffer[pos->i + 1] == ' ')
        game->map[pos->b].value = LONELY_GROUND_ID;
    if (buffer[pos->i - 1] == ' ' && buffer[pos->i + 1] != ' ')
        game->map[pos->b].value = LEFT_UP_GROUND_ID;
    if (buffer[pos->i - 1] != ' ' && buffer[pos->i + 1] == ' ')
        game->map[pos->b].value = RIGHT_UP_GROUND_ID;
}
