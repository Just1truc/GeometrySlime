/*
** EPITECH PROJECT, 2021
** my_put_nbr
** File description:
** displays the number given as a parameter.
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_put_nbr(int nb)
{
    unsigned int nbr;

    if (nb < 0) {
        write(1, "-", 1);
        nbr = -nb;
    } else {
        nbr = nb;
    }
    if (nbr >= 10) {
        my_put_nbr(nbr / 10);
    }
    my_putchar(nbr % 10 + '0');
    return (0);
}
