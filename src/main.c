/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** Main
*/

#include "navy.h"

static int get_pid_arg(char const *arg)
{
    int pid = 0;

    for (int i = 0; arg[i]; i++) {
        if (!str_contains("0123456789", arg[i]))
            return (-1);
        pid = 10 * pid + arg[i] - 48;
    }
    return (pid);
}

int main(int argc, char const *argv[])
{
    signal(SIGUSR1, signal_add);
    signal(SIGUSR2, signal_add);
    if (argc < 2 || argc > 3)
        return (84);
    if (argc == 2
    && (str_is_equal(argv[1], "-h") || str_is_equal(argv[1], "--help"))) {
        write(1, HELP, str_length(HELP));
        return (0);
    }
    if (argc == 2)
        return (wait_game(argv[1]));
    else
        return (connect_game(get_pid_arg(argv[1]), argv[2]));
}
