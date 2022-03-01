/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** free everything
*/

#include "my_runner.h"

void destroy_sprites(game_t *game)
{
    sfSprite_destroy(game->sprites->ground_sprite);
    sfSprite_destroy(game->sprites->monster_sprite);
    sfSprite_destroy(game->sprites->back_sprite);
    sfSprite_destroy(game->sprites->selection_sprite);
    sfSprite_destroy(game->sprites->bar_sprite);
    sfSprite_destroy(game->sprites->slime_sprite);
    sfSprite_destroy(game->sprites->background_sprite);
    sfSprite_destroy(game->sprites->play_button_sprite);
    sfSprite_destroy(game->sprites->difficulty_sprite);
    sfSprite_destroy(game->sprites->arrow_sprite);
    sfSprite_destroy(game->sprites->restart_sprite);
    sfSprite_destroy(game->sprites->middleground_sprite);
    sfSprite_destroy(game->sprites->pause_sprite);
    sfSprite_destroy(game->sprites->victory_sprite);
    sfSprite_destroy(game->sprites->sound_sprite);
    sfSprite_destroy(game->sprites->options_sprite);
    sfSprite_destroy(game->sprites->quit_sprite);
}

void destroy_textures(game_t *game)
{
    sfTexture_destroy(game->ground_texture);
    sfTexture_destroy(game->monster_texture);
    sfTexture_destroy(game->back_texture);
    sfTexture_destroy(game->selection_texture);
    sfTexture_destroy(game->bar_texture);
    sfTexture_destroy(game->slime_texture);
    sfTexture_destroy(game->background_texture);
    sfTexture_destroy(game->play_button_texture);
    sfTexture_destroy(game->difficulty_texture);
    sfTexture_destroy(game->arrow_texture);
    sfTexture_destroy(game->restart_texture);
    sfTexture_destroy(game->middleground_texture);
    sfTexture_destroy(game->pause_texture);
    sfTexture_destroy(game->victory_texture);
    sfTexture_destroy(game->sound_texture);
    sfTexture_destroy(game->options_texture);
    sfTexture_destroy(game->quit_texture);
}

void destroy_all(game_t *game)
{
    destroy_sprites(game);
    destroy_textures(game);
    sfSound_destroy(game->coin_sound);
    sfSoundBuffer_destroy(game->coin_buffer);
    sfSound_destroy(game->death_sound);
    sfSoundBuffer_destroy(game->death_buffer);
    sfSound_destroy(game->victory_sound);
    sfSoundBuffer_destroy(game->victory_buffer);
    sfSound_destroy(game->wrong_sound);
    sfSoundBuffer_destroy(game->wrong_buffer);
    sfMusic_destroy(game->background_music);
    sfClock_destroy(game->monster_clock);
    sfClock_destroy(game->background_clock);
    free(game->stats);
    free(game->map);
    free(game->sprites);
    sfView_destroy(game->view);
    sfRenderWindow_destroy(game->window);
}
