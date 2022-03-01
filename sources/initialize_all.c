/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** runner game
*/

#include "my_runner.h"

void initialize_sprites_next(game_t *game)
{
    game->sprites->pause_sprite = sfSprite_create();
    game->sprites->restart_sprite = sfSprite_create();
    game->sprites->middleground_sprite = sfSprite_create();
    game->sprites->victory_sprite = sfSprite_create();
    game->coin_sound = sfSound_create();
    game->death_sound = sfSound_create();
    game->victory_sound = sfSound_create();
    game->wrong_sound = sfSound_create();
    game->sprites->quit_sprite = sfSprite_create();
    game->sprites->options_sprite = sfSprite_create();
    game->sprites->sound_sprite = sfSprite_create();
}

void initialize_sprites(game_t *game)
{
    game->sprites->slime_sprite = sfSprite_create();
    game->sprites->background_sprite = sfSprite_create();
    game->sprites->monster_sprite = sfSprite_create();
    game->sprites->ground_sprite = sfSprite_create();
    game->sprites->play_button_sprite = sfSprite_create();
    game->sprites->bar_sprite = sfSprite_create();
    game->sprites->back_sprite = sfSprite_create();
    game->sprites->selection_sprite = sfSprite_create();
    game->sprites->difficulty_sprite = sfSprite_create();
    game->sprites->arrow_sprite = sfSprite_create();
    initialize_sprites_next(game);
}

void initialize_color(game_t *game)
{
    game->background_color.a = 90;
    game->background_color.r = 100;
    game->background_color.g = 255;
    game->background_color.b = 255;
    game->ground_color.a = 255;
    game->ground_color.r = 100;
    game->ground_color.g = 255;
    game->ground_color.b = 255;
    game->slime_color.a = 255;
    game->slime_color.r = 0;
    game->slime_color.g = 255;
    game->slime_color.b = 0;
    game->red_color.a = 255;
    game->red_color.r = 255;
    game->red_color.g = 0;
    game->red_color.b = 0;
}

void initialize_stuff(game_t *game)
{
    game->score_text = sfText_create();
    game->difficulty = NORMAL;
    game->view = sfView_createFromRect(game->view_rect);
    game->gravity = -5 * game->difficulty;
    game->alive = 1;
    game->pause = 0;
    game->rotation_angle = 0;
    game->saw_seconds = 0;
    game->coin_seconds = 0;
    game->monster_clock = sfClock_create();
    game->background_clock = sfClock_create();
    game->sound_volume = 100;
    game->music_volume = 100;
    sfText_setFont(game->score_text, game->score_font);
    sfText_setCharacterSize(game->score_text, 50);
    sfSound_setBuffer(game->coin_sound, game->coin_buffer);
    sfSound_setBuffer(game->death_sound, game->death_buffer);
    sfSound_setBuffer(game->victory_sound, game->victory_buffer);
    sfSound_setBuffer(game->wrong_sound, game->wrong_buffer);
}

void initialize_all(game_t *game)
{
    game->sprites = malloc(sizeof(sprite_t));
    initialize_sprites(game);
    initialize_textures(game);
    initialize_sounds(game);
    initialize_pos(game);
    initialize_color(game);
    initialize_rect(game);
    initialize_statistics(game);
    initialize_stuff(game);
    set_texture_and_pos(game);
}
