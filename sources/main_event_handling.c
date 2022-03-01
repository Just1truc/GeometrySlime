/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** handle events
*/

#include "my_runner.h"

void handle_screens_next(sfVector2i mouse_pos, game_t *game)
{
    if (mouse_pos.x >= 269 && mouse_pos.x <= 831 && mouse_pos.y >= 209
    && mouse_pos.y <= 269 && game->game_screen == OPTIONS) {
        game->game_screen = DIFFICULTY;
    }
    if (mouse_pos.x >= 408 && mouse_pos.x <= 685 && mouse_pos.y >= 418
    && mouse_pos.y <= 478 && game->game_screen == OPTIONS)
        game->game_screen = SOUND;
    set_difficulty(mouse_pos, game);
    get_event_pause_menu(mouse_pos, game);
    if (mouse_pos.x >= 985 && mouse_pos.x <= 1075 && mouse_pos.y >= 625
    && mouse_pos.y <= 715 && game->game_screen == MENU) {
        sfRenderWindow_close(game->window);
    }
}

void handle_screens(sfVector2i mouse_pos, game_t *game)
{
    if (mouse_pos.x >= 360 && mouse_pos.x <= 435 && mouse_pos.y >= 340
    && mouse_pos.y <= 410 && game->game_screen == MENU)
        game->game_screen = CUSTOMIZATION;
    if (mouse_pos.x >= 600 && mouse_pos.x <= 675 && mouse_pos.y >= 340
    && mouse_pos.y <= 410 && game->game_screen == MENU)
        game->game_screen = OPTIONS;
    if (mouse_pos.x >= 0 && mouse_pos.x <= 100 && mouse_pos.y >= 0
    && mouse_pos.y <= 100 && (game->game_screen == CUSTOMIZATION
    || game->game_screen == OPTIONS))
        game->game_screen = MENU;
    if (mouse_pos.x >= 0 && mouse_pos.x <= 100 && mouse_pos.y >= 0
    && mouse_pos.y <= 100 && (game->game_screen == DIFFICULTY
    || game->game_screen == SOUND)) {
        game->game_screen = OPTIONS;
        set_volume(game);
    }
    handle_screens_next(mouse_pos, game);
}

void check_mouse(sfVector2i mouse_pos, game_t *game)
{
    if (mouse_pos.x >= 475 && mouse_pos.x <= 575 && mouse_pos.y >= 310
    && mouse_pos.y <= 410 && game->game_screen == MENU) {
        sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
        initialize_game(game);
    }
    if ((mouse_pos.x >= 315 && mouse_pos.x <= 760 && mouse_pos.y >= 205
    && mouse_pos.y <= 305 && game->game_screen == RESTART)
    || (mouse_pos.x >= 636 && mouse_pos.x <= 728 && mouse_pos.y >= 533
    && mouse_pos.y <= 608 && game->game_screen == VICTORY)) {
        sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
        reset_game(game);
    }
    if ((mouse_pos.x >= 405 && mouse_pos.x <= 675 && mouse_pos.y >= 405
    && mouse_pos.y <= 505 && game->game_screen == RESTART)
    || (mouse_pos.x >= 377 && mouse_pos.x <= 466 && mouse_pos.y >= 532
    && mouse_pos.y <= 609 && game->game_screen == VICTORY)) {
        get_back_to_menu(game);
    }
    handle_screens(mouse_pos, game);
}

void check_key_events(game_t *game)
{
    if (game->event.type == sfEvtKeyPressed
    && game->event.key.code == sfKeySpace && game->game_screen == MENU) {
        sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
        initialize_game(game);
    }
    if (game->event.type == sfEvtKeyPressed
    && game->event.key.code == sfKeySpace && game->game_screen == GAME
    && game->is_jumping == 0 && check_colision(game) == 1) {
        game->is_jumping = 1;
        game->jump_pos.y = -30;
    }
    if (game->event.type == sfEvtMouseButtonPressed) {
        check_mouse(sfMouse_getPositionRenderWindow(game->window), game);
    }
    if (game->event.type == sfEvtKeyPressed
    && game->event.key.code == sfKeyEscape)
        sfRenderWindow_close(game->window);
    if (game->event.type == sfEvtKeyPressed
    && game->event.key.code == sfKeyP && game->game_screen == GAME)
        check_pause(game);
}

void handle_event(game_t *game)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue
    && (game->game_screen == CUSTOMIZATION
    || game->game_screen == SOUND)) {
        check_keep_pressed_mouse(sfMouse_getPositionRenderWindow(game->window),
        game);
    }
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        check_key_events(game);
    }
}
