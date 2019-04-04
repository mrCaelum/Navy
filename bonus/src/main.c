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

static void init_colors(void)
{
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_BLUE);
    init_pair(3, COLOR_RED, COLOR_RED);
    init_pair(4, COLOR_GREEN, COLOR_GREEN);
}

static void init_ncurses(WINDOW *win)
{
    initscr();
    noecho();
    cbreak();
    win = newwin(10, 30, (24 - 10) / 2, (80 - 30) / 2);
    keypad(win, TRUE);
    refresh();
    curs_set(0);
    init_colors();
}

static void stop(void)
{
    endwin();
    system("stty -raw && stty echo && stty onlcr");
}

int main(int argc, char const *argv[])
{
    WINDOW *win;

    signal(SIGUSR1, signal_add);
    signal(SIGUSR2, signal_add);
    init_ncurses(win);
    if (argc < 2 || argc > 3)
        return (stop(), 84);
    if (argc == 2
    && (str_is_equal(argv[1], "-h") || str_is_equal(argv[1], "--help"))) {
        write(1, HELP, str_length(HELP));
        return (stop(), 0);
    }
    if (argc == 2)
        return (stop(), wait_game(argv[1]));
    else
        return (stop(), connect_game(get_pid_arg(argv[1]), argv[2]));
}
