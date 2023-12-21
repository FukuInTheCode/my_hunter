/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "include/my.h"
#include "my.h"
#include <SFML/Graphics/RenderWindow.h>

static func choose_displayer(my_window_t *wt)
{
    if (wt->status == GAME_ST)
        return display_game;
    return NULL;
}

int game_loop(my_window_t *wt)
{
    int error = 0;
    func displayer = NULL;

    for (; sfRenderWindow_isOpen(wt->w);) {
        do_events_loop(wt);
        displayer = choose_displayer(wt);
        if (displayer != NULL)
            displayer(wt);
        sfRenderWindow_display(wt->w);
    }
    return error;
}
