/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** display information about the game
*/

#include "my_runner.h"

void display_h_opt(void)
{
    char buffer[30000];
    int val = open("informations.txt", O_RDONLY);
    int len = read(val, buffer, 29999);
    buffer[len] = '\0';
    my_putstr(buffer);
    close(val);
}
