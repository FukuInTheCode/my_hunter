/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

int handle_args(int argc, char **argv, char **envp)
{
    for (int i = 0; envp[i]; i++)
        if (!my_strncmp("DISPLAY", envp[i], 6))
            return 0;
    return 84;
}
