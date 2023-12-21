/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "include/my.h"
#include "my.h"

static func choose_displayer(my_window_t *wt)
{
    if (wt->status == GAME_ST)
        return display_game;
    if (wt->status == GAMEOVER_ST)
        return display_gameover;
    if (wt->status == MENU_ST)
        return display_menu;
    if (wt->status == SETTINGS_VID_ST || wt->status == SETTINGS_AUD_ST ||
        wt->status == SETTINGS_CRE_ST)
        return display_setting;
    return NULL;
}

int game_loop(my_window_t *wt, my_duck_t *duck)
{
    int error = 0;
    func displayer = NULL;

    sfMusic_setLoop(wt->music, sfTrue);
    sfMusic_play(wt->music);
    wt->bg_n = sfClock_getElapsedTime(wt->clock).microseconds / 1e5;
    for (sfClock_restart(wt->clock); sfRenderWindow_isOpen(wt->w);) {
        sfRenderWindow_clear(wt->w, sfBlack);
        do_events_loop(wt, duck);
        displayer = choose_displayer(wt);
        if (displayer != NULL)
            displayer(wt, duck);
        sfRenderWindow_display(wt->w);
    }
    return error;
}
