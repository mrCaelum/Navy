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
    my_printf("%c%c: %s\n\n", x + 'A', y + '1', i ? "hit" : "missed");
    return (0);
}

static int attack(int enemy_pid, char **enemy_map)
{
    char *c;

    my_printf("attack: ");
    if (!(c = readr()))
        return (1);
    if (str_length(c) > 2 || str_length(c) <= 0
    || !str_contains("ABCDEFGH", c[0])
    || !str_contains("12345678", c[1])) {
        write(1, "wrong position\n", 15);
        return (free(c), attack(enemy_pid, enemy_map));
    }
    usleep(1000);
    if (send_bits(enemy_pid, c[0] - 'A', 16))
        return (free(c), attack(enemy_pid, enemy_map));
    usleep(10);
    if (send_bits(enemy_pid, c[1] - '1', 16))
        return (free(c), attack(enemy_pid, enemy_map));
    return (set_result(enemy_map, c[0] - 'A', c[1] - '1'));
}

static int recive_attack(int enemy_pid, char **map)
{
    int x = wait_bits(16);
    int y = wait_bits(16);
    int i = str_contains("2345x", map[y][x]);

    usleep(100);
    send_bits(enemy_pid, i, 16);
    my_printf("%c%c: %s\n\n", x + 'A', y + '1', i ? "hit" : "missed");
    map[y][x] = i ? 'x' : 'o';
    return (0);
}

int game_loop_client(int pid, int enemy_pid, char **map, char **enemy_map)
{
    int running = 1;

    while (running) {
        my_printf("my positions:\n");
        print_map(map);
        my_printf("enemy's positions:\n");
        print_map(enemy_map);
        my_printf("waiting for enemy's attack...\n");
        while (recive_attack(enemy_pid, map));
        if (on_loose(map, enemy_map))
            return (1);
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
        my_printf("my positions:\n");
        print_map(map);
        my_printf("enemy's positions:\n");
        print_map(enemy_map);
        if (attack(enemy_pid, enemy_map))
            return (0);
        if (on_win(map, enemy_map))
            return (0);
        my_printf("waiting for enemy's attack...\n");
        while (recive_attack(enemy_pid, map));
        if (on_loose(map, enemy_map))
            return (1);
    }
    return (0);
}
