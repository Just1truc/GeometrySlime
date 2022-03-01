/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** handle event next
*/

#include "my_runner.h"

void check_keep_pressed_mouse_next(sfVector2i mouse_pos, game_t *game)
{
    if (mouse_pos.x >= 400 && mouse_pos.x <= 655 && mouse_pos.y >= 370
    && mouse_pos.y <= 400 && game->game_screen == CUSTOMIZATION) {
        game->selection_one_pos.x = mouse_pos.x - 25;
        game->slime_color.r = 255 - (655 - mouse_pos.x);
    }
    if (mouse_pos.x >= 400 && mouse_pos.x <= 655 && mouse_pos.y >= 470
    && mouse_pos.y <= 500 && game->game_screen == CUSTOMIZATION) {
        game->selection_two_pos.x = mouse_pos.x - 25;
        game->slime_color.b = 255 - (655 - mouse_pos.x);
    }
    if (mouse_pos.x >= 400 && mouse_pos.x <= 655 && mouse_pos.y >= 570
    && mouse_pos.y <= 630 && game->game_screen == CUSTOMIZATION) {
        game->selection_three_pos.x = mouse_pos.x - 25;
        game->slime_color.g = 255 - (655 - mouse_pos.x);
    }
}

void check_keep_pressed_mouse(sfVector2i mouse_pos, game_t *game)
{
    if (mouse_pos.x >= 737 && mouse_pos.x <= 788 && mouse_pos.y >= 225
    && mouse_pos.y <= 275 && game->music_volume < 100
    && game->game_screen == SOUND)
        game->music_volume += 1;
    if (mouse_pos.x >= 627 && mouse_pos.x <= 676 && mouse_pos.y >= 225
    && mouse_pos.y <= 275 && game->music_volume > 0
    && game->game_screen == SOUND)
        game->music_volume -= 1;
    if (mouse_pos.x >= 737 && mouse_pos.x <= 788 && mouse_pos.y >= 425
    && mouse_pos.y <= 475 && game->sound_volume < 100
    && game->game_screen == SOUND)
        game->sound_volume += 1;
    if (mouse_pos.x >= 627 && mouse_pos.x <= 676 && mouse_pos.y >= 425
    && mouse_pos.y <= 475 && game->sound_volume > 0
    && game->game_screen == SOUND)
        game->sound_volume -= 1;
    check_keep_pressed_mouse_next(mouse_pos, game);
}
