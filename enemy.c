/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

static sfTexture *set_texture(my_window_t *wt, my_duck_t *duck)
{
    double spawn_rate = get_spawn_chance(wt);
    uint8_t id = rand() % 101 >= spawn_rate * 100;
    sfTexture *t = duck->skins[id];

    duck->sprite_rect.width = id * (498 - 154) + 154;
    duck->sprite_rect.height = id * (498 - 134) + 134;
    duck->sprite_rect.top = 0;
    duck->sprite_rect.left = 0;
    sfSprite_setScale(duck->sprite,
        (sfVector2f){1. - id * 0.5, 1. - id * 0.5});
    duck->anime_time = 5e5;
    if (id)
        duck->anime_time = 5e4;
    duck->anim_n = sfClock_getElapsedTime(wt->clock).microseconds
        / duck->anime_time;
    return t;
}

static int gen_enemy_info(my_window_t *wt, my_duck_t *duck)
{
    sfVector2u w_size = sfRenderWindow_getSize(wt->w);

    sfSprite_setTexture(duck->sprite, set_texture(wt, duck), sfTrue);
    duck->is_right = rand() % 2;
    sfSprite_setTextureRect(duck->sprite, duck->sprite_rect);
    sfSprite_setPosition(duck->sprite,
        (sfVector2f){w_size.x * !duck->is_right, 0.});
    if (duck->is_right)
        sfSprite_scale(duck->sprite, (sfVector2f){-1, 1});
    duck->move = choose_movement_function();
    duck->move_n = sfClock_getElapsedTime(wt->clock).microseconds / 2e4;
    gen_var(wt, duck);
    return 0;
}

static int move_enemy(my_window_t *wt, my_duck_t *duck,
    sfInt64 elapsed)
{
    if (elapsed / 2e4 - duck->move_n > 1.) {
        duck->move_n++;
        duck->move(wt, duck);
    }
    return 0;
}

static int move_texture(my_duck_t *duck)
{
    if (duck->sprite_rect.width == 154) {
        duck->sprite_rect.left = (rand() % 27) * 154;
        return 0;
    }
    duck->sprite_rect.left = (duck->sprite_rect.left +
        duck->sprite_rect.width) % (22 * 498);
    return 0;
}

int update_enemy(my_window_t *wt, my_duck_t *duck)
{
    sfVector2f duck_pos;
    sfVector2u w_size = sfRenderWindow_getSize(wt->w);
    sfInt64 elapsed = sfClock_getElapsedTime(wt->clock).microseconds;

    move_enemy(wt, duck, elapsed);
    if (elapsed / duck->anime_time - duck->anim_n > 1.) {
        move_texture(duck);
        duck->anim_n++;
    }
    duck_pos = sfSprite_getPosition(duck->sprite);
    if ((duck->is_right && duck_pos.x > w_size.x + 10 +
        duck->sprite_rect.width) || duck_pos.x > w_size.x * 2.
        || duck_pos.y > w_size.y)
        gen_enemy_info(wt, duck);
    if (!duck->is_right && (duck_pos.x < -10 - duck->sprite_rect.width))
        gen_enemy_info(wt, duck);
    sfSprite_setTextureRect(duck->sprite, duck->sprite_rect);
    return 0;
}

my_duck_t *gen_enemy(my_window_t *wt)
{
    my_duck_t *duck = malloc(sizeof(my_duck_t));

    if (!duck)
        return NULL;
    duck->skins[0] = sfTexture_createFromFile("./assets/boo_sprite_sheet.png",
        NULL);
    duck->skins[1] = sfTexture_createFromFile("./assets/koopa.png", NULL);
    duck->sprite = sfSprite_create();
    duck->anim_n = 0;
    if (!duck->skins[0] || !duck->skins[1]) {
        free(duck);
        return NULL;
    }
    gen_enemy_info(wt, duck);
    return duck;
}
