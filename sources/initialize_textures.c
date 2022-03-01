/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** initialize texture by importing them from files
*/

#include "my_runner.h"

void initialize_textures_next(game_t *game)
{
    game->restart_texture =
    sfTexture_createFromFile("assets/restart_menu.png", NULL);
    game->middleground_texture =
    sfTexture_createFromFile("assets/second_paralax.png", NULL);
    game->victory_texture =
    sfTexture_createFromFile("assets/victory_screen.png", NULL);
    game->quit_texture =
    sfTexture_createFromFile("assets/quit_button.png", NULL);
    game->score_font =
    sfFont_createFromFile("assets/font.ttf");
    game->options_texture =
    sfTexture_createFromFile("assets/options.png", NULL);
    game->sound_texture =
    sfTexture_createFromFile("assets/sound_button.png", NULL);
    game->pause_texture =
    sfTexture_createFromFile("assets/play_pause.png", NULL);
}

void initialize_textures(game_t *game)
{
    game->slime_texture =
    sfTexture_createFromFile("assets/base_slime.png", NULL);
    game->background_texture =
    sfTexture_createFromFile("assets/background_test.png", NULL);
    game->monster_texture =
    sfTexture_createFromFile("assets/monsters.png", NULL);
    game->ground_texture =
    sfTexture_createFromFile("assets/grounds.png", NULL);
    game->play_button_texture =
    sfTexture_createFromFile("assets/play.png", NULL);
    game->bar_texture =
    sfTexture_createFromFile("assets/choosing_bar.png", NULL);
    game->back_texture = sfTexture_createFromFile("assets/back.png", NULL);
    game->selection_texture =
    sfTexture_createFromFile("assets/selection.png", NULL);
    game->difficulty_texture =
    sfTexture_createFromFile("assets/difficulty.png", NULL);
    game->arrow_texture =
    sfTexture_createFromFile("assets/left_arrow.png", NULL);
    initialize_textures_next(game);
}
