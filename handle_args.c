/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

static int handle_help(char const *arg)
{
    int fd;
    char buf[1000] = {0};

    if (my_strncmp("-h", arg, 2) || my_strlen(arg) != 2)
        return 84;
    fd = open("./assets/help.txt", O_RDONLY);
    if (fd <= 0)
        return 0;
    if (read(fd, buf, 999) == -1)
        return 84 + close(fd);
    write(1, buf, my_strlen(buf));
    return 1 + close(fd);
}

int handle_args(int argc, char **argv, char **envp)
{
    if (argc == 2)
        return handle_help(argv[1]);
    if (argc != 1)
        return 84;
    for (int i = 0; envp[i]; i++)
        if (!my_strncmp("DISPLAY", envp[i], 6))
            return 0;
    return 84;
}
