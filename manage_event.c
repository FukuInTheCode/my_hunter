/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

int do_events_loop(my_window_t *wt, my_duck_t *duck)
{
    for (sfEvent evt; sfRenderWindow_pollEvent(wt->w, &evt);)
        for (int i = 0; my_events[i].f; i++)
            (evt.type == my_events[i].type) && my_events[i].f(&evt, wt, duck);
    return 0;
}
