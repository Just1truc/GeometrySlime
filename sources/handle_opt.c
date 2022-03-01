/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** handle opt
*/

#include "my_runner.h"

int check_errors(char **ag)
{
    int val;
    if ((val = open(ag[1], O_RDONLY)) == -1) {
        my_putstr("./my_runner: map not found :'");
        my_putstr(ag[1]);
        my_putstr("'\nretry with -h\n");
        close(val);
        return (84);
    }
    if (ag[1][0] == '-'
    && (ag[1][1] != 'i' && ag[1][1] != 'h')) {
        my_putstr("./my_runner: argument not found: '");
        my_putstr(ag[1]);
        my_putstr("'\nretry with -h\n");
        return (84);
    }
    return (0);
}

int handle_args(char **ag, game_t *game)
{
    int val;
    if (ag[1][0] == '-' && ag[1][1] == 'i') {
        my_putstr("Infinite mod not functionnal\n");
        return (2);
    }
    if (ag[1][0] == '-' && ag[1][1] == 'h') {
        display_h_opt();
        return (0);
    }
    if (check_errors(ag) == 84)
        return (84);
    if ((val = open(ag[1], O_RDONLY)) != -1) {
        get_map(game, ag);
        close(val);
        return (1);
    }
    return (-69);
}

int handle_opt(int ac, char **ag, game_t *game)
{
    int output;
    if (ac != 2) {
        my_putstr("./my_runner: bad arguments: ");
        my_put_nbr(ac - 1);
        my_putstr(" given but 1 is required\nretry with -h\n");
        return (84);
    } else {
        output = handle_args(ag, game);
        if (output != -69)
            return output;
    }
    return (0);
}
