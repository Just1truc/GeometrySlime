/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** handle the different screens
*/

#include "my_runner.h"

void get_pause_state(game_t *game)
{
    if (game->pause == 0) {
        start_main_game(game);
    } else {
        display_pause_menu(game);
    }
}

void get_alive_state(game_t *game)
{
    if (game->alive == 1) {
        get_pause_state(game);
    } else {
        game->game_screen = RESTART;
        game->background_pos.x = 0;
        sfSound_play(game->death_sound);
        sfMusic_stop(game->background_music);
        sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
    }
}

void set_screen(game_t *game)
{
    if (game->game_screen == MENU)
        display_menu(game);
    if (game->game_screen == CUSTOMIZATION)
        display_customization_menu(game);
    if (game->game_screen == OPTIONS)
        display_option_menu(game);
    if (game->game_screen == SOUND)
        display_sound_menu(game);
    if (game->game_screen == DIFFICULTY)
        display_difficulty_menu(game);
    if (game->game_screen == GAME)
        get_alive_state(game);
    if (game->game_screen == RESTART)
        display_restart_menu(game);
    if (game->game_screen == VICTORY)
        display_victory_menu(game);
}
