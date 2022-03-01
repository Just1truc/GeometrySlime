/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** display sound menu
*/

#include "my_runner.h"

void display_volume_levels(game_t *game)
{
    game->result = my_conv((int)game->music_volume, 10);
    sfText_setPosition(game->score_text,
    get_pos(697 - (my_strlen(game->result) - 1) * 10, 237));
    sfText_setString(game->score_text, game->result);
    sfText_setCharacterSize(game->score_text, 20);
    sfRenderWindow_drawText(game->window, game->score_text, NULL);
    free(game->result);
    game->result = my_conv((int)game->sound_volume, 10);
    sfText_setPosition(game->score_text,
    get_pos(697 - (my_strlen(game->result) - 1) * 10, 437));
    sfText_setString(game->score_text, game->result);
    sfText_setCharacterSize(game->score_text, 20);
    sfRenderWindow_drawText(game->window, game->score_text, NULL);
    free(game->result);
}

void display_sound_bars(game_t *game)
{
    sfSprite_setPosition(game->sprites->sound_sprite,
    get_pos(600, 200));
    sfRenderWindow_drawSprite(game->window,
    game->sprites->sound_sprite, NULL);
    sfSprite_setPosition(game->sprites->sound_sprite,
    get_pos(600, 400));
    sfRenderWindow_drawSprite(game->window,
    game->sprites->sound_sprite, NULL);
}

void display_sound_menu(game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    move_background(game, -WIDTH, 0, 3);
    display_background(game);
    display_sound_bars(game);
    sfSprite_setPosition(game->sprites->back_sprite, get_pos(0, 0));
    sfRenderWindow_drawSprite(game->window,
    game->sprites->back_sprite, NULL);
    sfText_setCharacterSize(game->score_text, 50);
    sfText_setPosition(game->score_text, get_pos(200, 218));
    sfText_setString(game->score_text, "MUSIC");
    sfRenderWindow_drawText(game->window, game->score_text, NULL);
    sfText_setPosition(game->score_text, get_pos(200, 418));
    sfText_setString(game->score_text, "SOUNDS");
    sfRenderWindow_drawText(game->window, game->score_text, NULL);
    display_volume_levels(game);
    sfRenderWindow_display(game->window);
}
