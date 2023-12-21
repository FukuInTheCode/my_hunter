/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "include/my.h"
#include "my.h"
#include <SFML/Audio/Music.h>

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
    if (wt->status != SETTINGS_AUD_ST && wt->status != SETTINGS_VID_ST &&
        wt->status != SETTINGS_CRE_ST)
        return 0;
    if (sfKeyLeft == evt->key.code)
        d = -1;
    if (wt->status == SETTINGS_VID_ST && sfKeyLeft == evt->key.code)
        d = 0;
    if (wt->status == SETTINGS_CRE_ST && sfKeyRight == evt->key.code)
        d = 0;
    wt->status += d;
    return 0;
}


static int handle_audio(sfEvent *evt, my_window_t *wt)
{
    double vol = sfMusic_getVolume(wt->music);

    if (wt->status != SETTINGS_AUD_ST)
        return 0;
    if (sfKeyA == evt->key.code)
        vol++;
    if (sfKeyS == evt->key.code)
        vol--;
    if (vol > 100)
        vol = 100;
    if (vol < 0)
        vol = 0;
    sfMusic_setVolume(wt->music, vol);
    return 0;
}

static int handle_video(sfEvent *evt, my_window_t *wt)
{
    if (wt->status != SETTINGS_VID_ST)
        return 0;
    if (sfKeyA == evt->key.code)
        wt->fps_limit++;
    if (sfKeyS == evt->key.code)
        wt->fps_limit--;
    if (wt->fps_limit > 1000)
        wt->fps_limit = 1000;
    if (wt->fps_limit < 30)
        wt->fps_limit = 30;
    sfRenderWindow_setFramerateLimit(wt->w, wt->fps_limit);
    return 0;
}

int handle_key(sfEvent *evt, my_window_t *wt)
{
    int ret = 0;

    ret |= handle_escape(evt, wt);
    ret |= handle_arrow(evt, wt);
    ret |= handle_audio(evt, wt);
    ret |= handle_video(evt, wt);
    return 0;
}
