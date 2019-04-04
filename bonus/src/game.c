/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** Game
*/

#include "navy.h"

static int set_result(char **enemy_map, int x, int y)
{
    unsigned int i = wait_bits(16);

    enemy_map[y][x] = i ? 'x' : 'o';
    printw("%c%c: %s\n\n", x + 'A', y + '1', i ? "hit" : "missed");
    refresh();
    return (0);
}

static int attack(int enemy_pid, char **enemy_map)
{
    char c[3] = {0, 0, 0};

    printw("attack: ");
    refresh();
    readr(c);
    if (str_length(c) > 2 || str_length(c) <= 0
    || !str_contains("ABCDEFGH", c[0])
    || !str_contains("12345678", c[1])) {
        printw("wrong position\n");
        refresh();
        return (attack(enemy_pid, enemy_map));
    }
    usleep(1000);
    if (send_bits(enemy_pid, c[0] - 'A', 16))
        return (attack(enemy_pid, enemy_map));
    usleep(10);
    if (send_bits(enemy_pid, c[1] - '1', 16))
        return (attack(enemy_pid, enemy_map));
    return (set_result(enemy_map, c[0] - 'A', c[1] - '1'));
}

static int recive_attack(int enemy_pid, char **map)
{
    int x = wait_bits(16);
    int y = wait_bits(16);
    int i = str_contains("2345x", map[y][x]);

    usleep(100);
    send_bits(enemy_pid, i, 16);
    printw("%c%c: %s\n\n", x + 'A', y + '1', i ? "hit" : "missed");
    refresh();
    map[y][x] = i ? 'x' : 'o';
    return (0);
}

static void ziprint(char **map, char **enemy_map)
{
    clear();
    printw("my positions:\n");
    print_map(map);
    printw("enemy's positions:\n");
    print_map(enemy_map);
}

int game_loop_client(int pid, int enemy_pid, char **map, char **enemy_map)
{
    int running = 1;

    while (running) {
        ziprint(map, enemy_map);
        printw("waiting for enemy's attack...\n");
        refresh();
        while (recive_attack(enemy_pid, map));
        if (on_loose(map, enemy_map))
            return (1);
        ziprint(map, enemy_map);
        if (attack(enemy_pid, enemy_map))
            return (0);
        if (on_win(map, enemy_map))
            return (0);
    }
    return (0);
}

int game_loop_server(int pid, int enemy_pid, char **map, char **enemy_map)
{
    int running = 1;

    while (running) {
        ziprint(map, enemy_map);
        if (attack(enemy_pid, enemy_map))
            return (0);
        if (on_win(map, enemy_map))
            return (0);
        ziprint(map, enemy_map);
        printw("waiting for enemy's attack...\n");
        refresh();
        while (recive_attack(enemy_pid, map));
        if (on_loose(map, enemy_map))
            return (1);
    }
    return (0);
}
