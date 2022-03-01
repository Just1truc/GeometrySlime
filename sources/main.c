/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** mainf file containing main functions
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include "my_runner.h"

void game_loop(game_t *game)
{
    initialize_all(game);
    set_colors(game);
    while (sfRenderWindow_isOpen(game->window)) {
        handle_event(game);
        set_screen(game);
    }
    destroy_all(game);
}

int main(int ac, char **ag)
{
    sfVideoMode m = {WIDTH, HEIGHT, 32};
    game_t *game;
    int output;

    game = malloc(sizeof(game_t));
    game->game_screen = 0;
    game->is_jumping = 0;
    output = handle_opt(ac, ag, game);
    if (output == 84)
        return (84);
    if (output == 1) {
        game->window = sfRenderWindow_create(m,
        "Geometry slime", sfClose, NULL);
        sfRenderWindow_setFramerateLimit(game->window, 60);
        game->game_mode = 0;
        game_loop(game);
    }
    free(game);
    return (0);
}
