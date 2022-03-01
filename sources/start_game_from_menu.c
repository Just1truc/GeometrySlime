/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** start game
*/

#include "my_runner.h"

void initialize_game(game_t *game)
{
    game->game_screen = GAME;
    game->view_move.y = game->gravity;
    game->slime_pos.y = game->map[get_perfect_spawn(game)].pos.y - 100;
    game->window_pos.y = game->slime_pos.y - 300;
    game->middleground_pos.y = game->slime_pos.y - 300;
    game->background_pos.y = game->slime_pos.y - 300;
    game->view_rect.top = game->slime_pos.y - 300;
    sfView_reset(game->view, game->view_rect);
    sfRenderWindow_setView(game->window, game->view);
    game->stats->score = 0;
    sfMusic_setLoop(game->background_music, sfTrue);
    sfMusic_play(game->background_music);
}

void reset_game(game_t *game)
{
    game->game_screen = GAME;
    game->slime_pos.y = game->map[get_perfect_spawn(game)].pos.y - 100;
    game->slime_pos.x = 50;
    game->alive = 1;
    game->background_pos.x = -1 * game->view_move.x;
    game->background_pos.y = game->slime_pos.y - 300;
    game->middleground_pos.x = -1 * game->view_move.x;
    game->middleground_pos.y = game->slime_pos.y - 300;
    game->window_pos.x = 0;
    game->window_pos.y = game->slime_pos.y - 300;
    game->is_jumping = 0;
    game->view_rect.top = game->slime_pos.y - 300;
    game->slime_color.a = 255;
    sfSprite_setColor(game->sprites->slime_sprite, game->slime_color);
    sfView_reset(game->view, game->view_rect);
    sfRenderWindow_setView(game->window, game->view);
    game->stats->score = 0;
    sfMusic_setLoop(game->background_music, sfTrue);
    sfMusic_play(game->background_music);
    reset_state(game);
}

void get_back_to_menu(game_t *game)
{
    game->game_screen = MENU;
    sfSprite_setRotation(game->sprites->slime_sprite, 0);
    game->slime_pos.y = 420;
    game->slime_pos.x = 50;
    game->alive = 1;
    game->background_pos.x = 0;
    game->background_pos.y = 0;
    game->middleground_pos.y = 0;
    game->middleground_pos.x = 0;
    game->window_pos.x = 0;
    game->window_pos.y = 0;
    game->is_jumping = 0;
    game->slime_color.a = 255;
    sfSprite_setColor(game->sprites->slime_sprite, game->slime_color);
    reset_state(game);
}
