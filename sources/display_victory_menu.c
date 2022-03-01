/*
** EPITECH PROJECT, 2021
** my__runner
** File description:
** display victory screen
*/

#include "my_runner.h"

void display_scores_vic(game_t *game)
{
    game->result = my_conv(game->stats->score, 10);
    sfText_setPosition(game->score_text,
    get_pos(530 - (my_strlen(game->result) - 1) * 15, 295));
    sfText_setString(game->score_text, game->result);
    sfText_setCharacterSize(game->score_text, 30);
    sfRenderWindow_drawText(game->window, game->score_text, NULL);
    free(game->result);
    game->result = my_conv(game->stats->best_score, 10);
    sfText_setPosition(game->score_text,
    get_pos(530 - (my_strlen(game->result) - 1) * 15, 445));
    sfText_setString(game->score_text, game->result);
    sfRenderWindow_drawText(game->window, game->score_text, NULL);
    free(game->result);
}

void display_victory_menu(game_t *game)
{
    sfRenderWindow_clear(game->window, sfBlack);
    game->background_pos.y = 0;
    game->view_rect.top = 0;
    sfView_reset(game->view, game->view_rect);
    sfRenderWindow_setView(game->window, game->view);
    move_background(game, -WIDTH, 0, 3);
    display_background(game);
    sfSprite_setPosition(game->sprites->victory_sprite, get_pos(0, 0));
    sfRenderWindow_drawSprite(game->window,
    game->sprites->victory_sprite, NULL);
    display_scores_vic(game);
    sfText_setPosition(game->score_text, get_pos(470, 235));
    sfText_setString(game->score_text, "COINS:");
    sfRenderWindow_drawText(game->window, game->score_text, NULL);
    sfText_setPosition(game->score_text, get_pos(400, 385));
    sfText_setString(game->score_text, "BEST SCORE:");
    sfRenderWindow_drawText(game->window, game->score_text, NULL);
    sfRenderWindow_display(game->window);
}
