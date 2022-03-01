/*
** EPITECH PROJECT, 2021
** my_runner
** File description:
** header file
*/

#ifndef MY_RUNNER_H_
    #define MY_RUNNER_H_
    #define HEIGHT 720
    #define WIDTH 1080
/*  Game_screen handling   */
    #define MENU 0
    #define CUSTOMIZATION 1
    #define GAME 2
    #define DIFFICULTY 3
    #define OPTIONS 6
    #define SOUND 7
    #define RESTART 4
    #define VICTORY 5
/*  Map id handling  */
    #define UNDERGROUND_ID 0
    #define BASE_GROUND_ID 1
    #define PLATFORM_ID 4
    #define LEFT_UP_GROUND_ID 15
    #define RIGHT_UP_GROUND_ID 14
    #define UP_GROUND_ID 12
    #define LONELY_GROUND_ID 13
    #define MONSTER_ID 2
    #define SAW_ID 3
    #define SPIKE_ID 5
    #define JUMP_PAD_ID 6
    #define COIN_ID 8
    #define END_ID 7
    #define MALUS_ID 9
/*    Difficulty   */
    #define EASY 1
    #define NORMAL 2
    #define HARD 3
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #include <SFML/Audio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <math.h>
    #include <time.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>

typedef struct pos {
    int x;
    int y;
    int b;
    int i;
    int height;
} pos_t;

typedef struct info {
    int i;
    sfIntRect rect;
} info_t;

typedef struct statis {
    int jump_nbr;
    int score;
    int best_score;
    int try_nbr;
} statis_t;

typedef struct map_c {
    sfVector2f pos;
    int value;
    int state;
} map_c_t;

typedef struct sprite {
    sfSprite *background_sprite;
    sfSprite *slime_sprite;
    sfSprite *play_button_sprite;
    sfSprite *monster_sprite;
    sfSprite *ground_sprite;
    sfSprite *bar_sprite;
    sfSprite *back_sprite;
    sfSprite *selection_sprite;
    sfSprite *difficulty_sprite;
    sfSprite *arrow_sprite;
    sfSprite *pause_sprite;
    sfSprite *restart_sprite;
    sfSprite *middleground_sprite;
    sfSprite *victory_sprite;
    sfSprite *quit_sprite;
    sfSprite *options_sprite;
    sfSprite *sound_sprite;
} sprite_t;

typedef struct game {
    sfRenderWindow *window;
    sfColor background_color;
    sprite_t *sprites;
    sfColor ground_color;
    sfTexture *pause_texture;
    sfTexture *options_texture;
    sfTexture *quit_texture;
    sfTexture *restart_texture;
    sfTexture *slime_texture;
    sfTexture *bar_texture;
    sfTexture *arrow_texture;
    sfTexture *middleground_texture;
    sfTexture *back_texture;
    sfTexture *play_button_texture;
    sfTexture *selection_texture;
    sfTexture *victory_texture;
    sfTexture *sound_texture;
    sfColor slime_color;
    sfColor red_color;
    sfTexture *background_texture;
    sfTexture *monster_texture;
    sfTexture *ground_texture;
    sfTexture *difficulty_texture;
    sfText *score_text;
    sfText *best_score_text;
    sfFont *score_font;
    sfSound *coin_sound;
    sfSoundBuffer *coin_buffer;
    sfSound *death_sound;
    sfSoundBuffer *death_buffer;
    sfSound *victory_sound;
    sfSoundBuffer *victory_buffer;
    sfSound *wrong_sound;
    sfSoundBuffer *wrong_buffer;
    sfMusic *background_music;
    sfVector2f slime_pos;
    sfVector2f background_pos;
    sfVector2f bar_pos;
    sfVector2f monster_pos;
    sfVector2f ground_pos;
    sfVector2f middleground_pos;
    sfVector2f selection_one_pos;
    sfVector2f selection_two_pos;
    sfVector2f selection_three_pos;
    sfVector2f play_button_pos;
    sfVector2f arrow_pos;
    sfIntRect ground_rect;
    sfIntRect monsters_rect;
    sfEvent event;
    int is_jumping;
    sfVector2f jump_pos;
    int game_screen;
    int game_mode;
    int jump_phase;
    map_c_t *map;
    int object_nbr;
    int difficulty;
    sfView *view;
    char *result;
    sfVector2f view_move;
    sfVector2f window_pos;
    sfFloatRect view_rect;
    float gravity;
    int alive;
    int pause;
    float rotation_angle;
    sfClock *monster_clock;
    float sound_volume;
    float music_volume;
    sfTime time2;
    float seconds;
    float saw_seconds;
    float coin_seconds;
    statis_t *stats;
    sfClock *background_clock;
    sfTime background_time;
    float background_seconds;
    float view_seconds;
    float camera_seconds;
} game_t;

int check_monster_colision(game_t *game, int i);
int check_saw_colision(game_t *game, int i);
void set_rotation_on_point(game_t *game);
int check_colision(game_t *game);
int check_end_colision(game_t *game, int i);
int check_ground_colision(game_t *game, int i);
int check_colision_from_under(game_t *game, int i);
void check_keep_pressed_mouse_next(sfVector2i mouse_pos, game_t *game);
void check_keep_pressed_mouse(sfVector2i mouse_pos, game_t *game);
void initialize_rect(game_t *game);
void initialize_statistics(game_t *game);
void set_colors(game_t *game);
void display_pause_menu(game_t *game);
void start_main_game(game_t *game);
void apply_gravity(game_t *game);
void reposition_camera(game_t *game);
void display_middleground(game_t *game);
void move_middleground(game_t *game);
void display_victory_menu(game_t *game);
void display_restart_menu(game_t *game);
void display_difficulty_menu(game_t *game);
void display_sound_menu(game_t *game);
void display_option_menu(game_t *game);
void display_customization_menu(game_t *game);
void display_background(game_t *game);
void display_menu(game_t *game);
void initialize_pos(game_t *game);
void display_element(game_t *game, info_t *inf,
sfSprite *sprite, sfTexture *texture);
void get_back_to_menu(game_t *game);
void reset_game(game_t *game);
void initialize_game(game_t *game);
void get_event_pause_menu(sfVector2i mouse_pos, game_t *game);
void handle_moving_ground(game_t *game);
void display_basic_ground(game_t *game);
sfIntRect get_rect(int top, int left, int width, int height);
void change_best_score(game_t *game);
void move_background(game_t *game, int min, int reset, int speed);
int my_strlen(char const *str);
char *my_revstr(char *str);
void reset_state(game_t *game);
char *my_conv(int nbr, int nb);
char *my_strcpy(char *dest, char const *src);
void my_putstr(char const *str);
int get_perfect_spawn(game_t *game);
void initialize_all(game_t *game);
int my_put_nbr(int nb);
int my_getnbr(char *str);
sfVector2f get_pos(int x, int y);
void get_map(game_t *game, char **ag);
void load_map(game_t *game);
int check_colision(game_t *game);
int check_death(game_t *game);
void change_state(game_t *game, int ID, int max_state);
void set_volume(game_t *game);
void handle_event(game_t *game);
void set_difficulty(sfVector2i mouse_pos, game_t *game);
void set_texture_and_pos(game_t *game);
void initialize_textures(game_t *game);
void initialize_sounds(game_t *game);
void destroy_all(game_t *game);
int handle_opt(int ac, char **ag, game_t *game);
void display_h_opt(void);
void check_pause(game_t *game);
void handle_obj_clocks(game_t *game);
void check_jump(game_t *game);
void draw_slime(game_t *game);
void set_screen(game_t *game);
int get_map_begin(char **ag);
int get_nbr_of_objects(char **ag);
int get_height(char **ag);
int check_up(game_t *game, pos_t *pos);
void get_under_air_ground(game_t *game, pos_t *pos, char *buffer);
void load_map_fourth(game_t *game, info_t *inf);

#endif /* MY_RUNNER_H_ */
