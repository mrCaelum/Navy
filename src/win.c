/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** wim
*/

#include "navy.h"

int on_win(char **map, char **enemy_map)
{
    int count = 0;

    for (int y = 0; enemy_map[y]; y++)
        for (int x = 0; enemy_map[y][x]; x++)
            count += enemy_map[y][x] == 'x';
    if (count >= 14) {
        my_printf("my positions:\n");
        print_map(map);
        my_printf("enemy's positions:\n");
        print_map(enemy_map);
        my_printf("I won\n");
    }
    return (count >= 14);
}

int on_loose(char **map, char **enemy_map)
{
    for (int y = 0, x = 0; map[y]; x++) {
        if (!map[y][x]) {
            x = 0;
            y++;
            continue;
        } else if (str_contains("2345", map[y][x]))
            return (0);
    }
    my_printf("my positions:\n");
    print_map(map);
    my_printf("enemy's positions:\n");
    print_map(enemy_map);
    my_printf("Enemy won\n");
    return (1);
}
