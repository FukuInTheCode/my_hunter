/*
** EPITECH PROJECT, 2023
** MY_H
** File description:
** Placeholder
*/

#ifndef MY_H
    #define MY_H
    #include <SFML/Window/Event.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <stdint.h>
    #include <time.h>
    #include <limits.h>
    #include <stdarg.h>
    #include <errno.h>
    #include <fcntl.h>
    #include <math.h>
    #include <stdlib.h>
    #include <sys/stat.h>

    #include <criterion/criterion.h>
    #include <criterion/redirect.h>

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Config.h>
    #include <SFML/GPUPreference.h>
    #include <SFML/Network.h>
    #include <SFML/OpenGL.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>


typedef int(*func)();

typedef enum {
    NONE,
    MENU_ST,
    GAME_ST,
    GAMEOVER_ST,
    SETTINGS_VID_ST,
    SETTINGS_AUD_ST,
    SETTINGS_CRE_ST,
} my_status_t;

typedef struct {
    sfRenderWindow *w;
    sfSprite **bgs;
    my_status_t status;
    sfClock *clock;
    sfInt64 score;
    uint8_t lives;
    uint64_t bg_n;
    sfText *text;
    bool is_day;
    sfMusic *music;
    int fps_limit;
} my_window_t;

typedef struct {
    sfSprite *sprite;
    sfBool is_right;
    sfInt64 anim_n;
    sfInt64 move_n;
    func move;
    union {
        double sin_a[3];
        double linear_y;
    };
    sfTexture *skins[2];
    sfIntRect sprite_rect;
    double anime_time;
} my_duck_t;

typedef struct {
    sfEventType type;
    func f;
} my_evt_t;

int do_events_loop(my_window_t *, my_duck_t *);

int game_loop(my_window_t *, my_duck_t *);

int display_gameover(my_window_t *, my_duck_t *);
int display_menu(my_window_t *, my_duck_t *);
int display_setting(my_window_t *, my_duck_t *);
int display_game(my_window_t *, my_duck_t *);

my_duck_t *gen_enemy(my_window_t *);
int update_enemy(my_window_t *, my_duck_t *);
int gen_var(my_window_t *, my_duck_t *);

int handle_setting(sfEvent *, my_window_t *);
int handle_close(sfEvent *, my_window_t *);
int handle_click(sfEvent *, my_window_t *, my_duck_t *);
int handle_key(sfEvent *, my_window_t *);
int handle_args(int, char **, char **);

size_t my_strlen(char const *);
int my_strncmp(char const *, char const *, int);

int sin_movement(my_window_t *, my_duck_t *);
int linear_movement(my_window_t *, my_duck_t *);
func choose_movement_function(void);

char *my_put_nbr(int, char[1000]);
char *my_revstr(char *);

double get_spawn_chance(my_window_t *);

static my_evt_t const my_events[] = {
    {sfEvtKeyPressed, handle_key},
    {sfEvtMouseButtonPressed, handle_click},
    {sfEvtClosed, handle_close},
    {sfEvtCount, NULL},
};

static char const *paths[] __attribute__((unused)) =
    {"./assets/background_day.png",
    "./assets/background_night.jpg", "./assets/title_screen.png",
    "./assets/game_over.png", "./assets/tryagain.png",
    "./assets/menu.png", "./assets/start_btn.png", "./assets/setting_btn.png",
    "./assets/audio_setting_btn.png", "./assets/video_setting_btn.png"};

#endif
