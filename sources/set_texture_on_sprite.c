/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** set texture on sprites
*/

#include "my_runner.h"

void set_texture_next(game_t *game)
{
    sfSprite_setTexture(game->sprites->arrow_sprite,
    game->arrow_texture, sfFalse);
    sfSprite_setTexture(game->sprites->pause_sprite,
    game->pause_texture, sfFalse);
    sfSprite_setTextureRect(game->sprites->pause_sprite, game->ground_rect);
    sfSprite_setTexture(game->sprites->restart_sprite,
    game->restart_texture, sfFalse);
    sfSprite_setTexture(game->sprites->middleground_sprite,
    game->middleground_texture, sfFalse);
    sfSprite_setTexture(game->sprites->monster_sprite,
    game->monster_texture, sfFalse);
    sfSprite_setTextureRect(game->sprites->monster_sprite, game->ground_rect);
    sfSprite_setTexture(game->sprites->victory_sprite,
    game->victory_texture, sfFalse);
    sfSprite_setTexture(game->sprites->quit_sprite,
    game->quit_texture, sfFalse);
    sfSprite_setTexture(game->sprites->options_sprite,
    game->options_texture, sfFalse);
    sfSprite_setTexture(game->sprites->sound_sprite,
    game->sound_texture, sfFalse);
}

void set_texture_and_pos(game_t *game)
{
    sfSprite_setTexture(game->sprites->background_sprite,
    game->background_texture, sfFalse);
    sfSprite_setTexture(game->sprites->slime_sprite,
    game->slime_texture, sfFalse);
    sfSprite_setTexture(game->sprites->ground_sprite,
    game->ground_texture, sfFalse);
    sfSprite_setTextureRect(game->sprites->ground_sprite,
    game->ground_rect);
    sfSprite_setTexture(game->sprites->play_button_sprite,
    game->play_button_texture, sfFalse);
    sfSprite_setTexture(game->sprites->bar_sprite,
    game->bar_texture, sfFalse);
    sfSprite_setTexture(game->sprites->back_sprite,
    game->back_texture, sfFalse);
    sfSprite_setTexture(game->sprites->selection_sprite,
    game->selection_texture, sfFalse);
    sfSprite_setTexture(game->sprites->difficulty_sprite,
    game->difficulty_texture, sfFalse);
    set_texture_next(game);
}
