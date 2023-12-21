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
    NONE = 0,
    MENU_ST = 1,
    GAME_ST = 2,
    SETTINGS_ST = 4,
} my_status_t;

typedef struct {
    sfRenderWindow *w;
    sfSprite **bgs;
    my_status_t status;
} my_window_t;

typedef struct my_duck {
    sfSprite *sprite;
    struct my_duck *next;
} my_duck_t;

typedef struct {
    sfEventType type;
    func f;
} my_evt_t;

int do_events_loop(my_window_t *);

int game_loop(my_window_t *, my_duck_t **);

int display_game(my_window_t *, my_duck_t **);

int add_enemy(my_window_t *, my_duck_t **);
int draw_enemies(my_window_t *, my_duck_t *);

int handle_close(my_window_t *);

static my_evt_t const my_events[] = {
    {sfEvtClosed, handle_close},
    {sfEvtCount, NULL},
};

#endif
