/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** check is the slime is inside a rect
*/

int is_in_inter(float pos, float min, float max)
{
    if (pos >= min && pos <= max)
        return (1);
    return (0);
}
