/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** check colision : file 2
*/

#include "my_runner.h"

void set_rotation_on_point(game_t *game)
{
    sfSprite_setRotation(game->sprites->slime_sprite,
    ((int)game->rotation_angle - ((int)game->rotation_angle / 90 * 90)
    <= 45) ? ((int)game->rotation_angle / 90 * 90) :
    (((int)game->rotation_angle / 90 + 1) * 90));
    game->rotation_angle = (((int)game->rotation_angle -
    ((int)game->rotation_angle / 90 * 90) <= 45) ?
    ((int)game->rotation_angle / 90 * 90) :
    (((int)game->rotation_angle / 90 + 1) * 90));
}

int check_colision(game_t *game)
{
    int i;

    for (i = 0; i < game->object_nbr; i++) {
        if (game->slime_pos.y + game->view_move.x >= game->map[i].pos.y - 100
        && game->slime_pos.y + game->view_move.x <= game->map[i].pos.y - 70
        && game->slime_pos.x >= game->map[i].pos.x - 100
        && game->slime_pos.x <= game->map[i].pos.x + 100
        && game->map[i].value != SAW_ID && game->map[i].value != MONSTER_ID
        && game->map[i].value != JUMP_PAD_ID && game->map[i].value != SPIKE_ID
        && game->map[i].value != COIN_ID && game->map[i].value != MALUS_ID) {
            game->slime_pos.y += game->map[i].pos.y - 100 - game->slime_pos.y;
            set_rotation_on_point(game);
            return (1);
        }
    }
    return (0);
}

int check_end_colision(game_t *game, int i)
{
    if (game->slime_pos.x >= game->map[i].pos.x - 120
    && game->slime_pos.x <= game->map[i].pos.x
    && game->slime_pos.y >= game->map[i].pos.y - 90
    && game->slime_pos.y <= game->map[i].pos.y
    && game->map[i].value == END_ID) {
        game->game_screen = VICTORY;
        sfMusic_stop(game->background_music);
        game->background_pos.x = 0;
        sfSound_play(game->victory_sound);
        change_best_score(game);
        sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
        return (1);
    }
    return (0);
}

int check_ground_colision(game_t *game, int i)
{
    if ((game->slime_pos.x >= game->map[i].pos.x - 120
    && game->slime_pos.x <= game->map[i].pos.x
    && game->slime_pos.y >= game->map[i].pos.y - 90
    && game->slime_pos.y <= game->map[i].pos.y
    || game->slime_pos.y >= 1080)
    && game->map[i].value != MONSTER_ID
    && game->map[i].value != SAW_ID
    && game->map[i].value != PLATFORM_ID
    && game->map[i].value != JUMP_PAD_ID
    && game->map[i].value != COIN_ID
    && game->map[i].value != MALUS_ID) {
        game->alive = 0;
        return (1);
    }
    return (0);
}

int check_colision_from_under(game_t *game, int i)
{
    if ((game->slime_pos.y >= game->map[i].pos.y
    && game->slime_pos.y <= game->map[i].pos.y + 90
    && game->slime_pos.x >= game->map[i].pos.x - 100
    && game->slime_pos.x <= game->map[i].pos.x + 100)
    && game->map[i].value != PLATFORM_ID
    && game->map[i].value != JUMP_PAD_ID
    && game->map[i].value != COIN_ID
    && game->map[i].value != MALUS_ID) {
        game->alive = 0;
        return (1);
    }
    return (0);
}
