/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "include/my.h"
#include "my.h"

static int handle_escape(sfEvent *evt, my_window_t *wt)
{
    if (evt->key.code != sfKeyEscape)
        return 0;
    if (wt->status == SETTINGS_VID_ST ||
        wt->status == SETTINGS_AUD_ST)
        wt->status = MENU_ST;
    return 0;
}

static int handle_arrow(sfEvent *evt, my_window_t *wt)
{
    int d = 1;

    if (sfKeyLeft != evt->key.code && sfKeyRight != evt->key.code)
        return 0;
    if (wt->status != SETTINGS_AUD_ST && wt->status != SETTINGS_VID_ST)
        return 0;
    if (sfKeyLeft == evt->key.code)
        d = -1;
    if (wt->status == SETTINGS_VID_ST && sfKeyLeft == evt->key.code)
        d = 0;
    if (wt->status == SETTINGS_AUD_ST && sfKeyRight == evt->key.code)
        d = 0;
    wt->status += d;
    return 0;
}

int handle_key(sfEvent *evt, my_window_t *wt)
{
    int ret = 0;

    ret |= handle_escape(evt, wt);
    ret |= handle_arrow(evt, wt);
    return 0;
}
