/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** main game loop
*/

#include "my_runner.h"

void main_game_next(game_t *game)
{
    if (game->view_seconds >= 0.0166) {
        reposition_camera(game);
        check_jump(game);
        apply_gravity(game);
    }
    check_death(game);
    load_map(game);
    draw_slime(game);
    sfRenderWindow_drawSprite(game->window, game->sprites->pause_sprite, NULL);
    sfText_setString(game->score_text, game->result);
    sfRenderWindow_drawText(game->window, game->score_text, NULL);
    free(game->result);
    if (game->view_seconds >= 0.0166)
        sfView_move(game->view, game->view_move);
    sfRenderWindow_setView(game->window, game->view);
    sfRenderWindow_display(game->window);
}

void main_game(game_t *game)
{
    game->background_time = sfClock_getElapsedTime(game->background_clock);
    game->background_seconds = game->background_time.microseconds / 1000000.0;
    game->view_seconds = game->background_seconds;
    if (game->background_seconds >= 0.0166) {
        game->window_pos.x += game->view_move.x;
        game->slime_pos.x += game->view_move.x;
        move_background(game, -WIDTH + game->window_pos.x - game->view_move.x,
        game->window_pos.x - game->view_move.x, -1 * (game->view_move.x - 1));
        move_middleground(game);
        sfClock_restart(game->background_clock);
    }
    handle_obj_clocks(game);
    sfRenderWindow_clear(game->window, sfBlack);
    display_background(game);
    display_middleground(game);
}

void start_main_game(game_t *game)
{
    game->view_move.x = (game->difficulty + 2) * 3;
    sfText_setCharacterSize(game->score_text, 50);
    game->result = my_conv(game->stats->score, 10);
    sfText_setPosition(game->score_text, get_pos(game->window_pos.x + 500
    - 25 * (my_strlen(game->result) - 1), game->window_pos.y));
    sfSprite_setTexture(game->sprites->pause_sprite,
    game->pause_texture, sfFalse);
    sfSprite_setTextureRect(game->sprites->pause_sprite,
    get_rect(0, 0, 100, 100));
    sfSprite_setPosition(game->sprites->pause_sprite, game->window_pos);
    main_game(game);
    main_game_next(game);
}
