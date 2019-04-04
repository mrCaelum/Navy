/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** Navy
*/

#include "navy.h"

int connect_game(int enemy_pid, char const *file)
{
    char **map = read_map(file);
    char **enemy_map = map_allocation();
    int pid = getpid();

    if (!map || !enemy_map || enemy_pid <= 0 || pid <= 0)
        return (84);
    my_printf("my_pid: %d\n", pid);
    if (send_bits(enemy_pid, pid, 16))
        return (84);
    my_printf("successfully connected\n\n");
    return (game_loop_client(pid, enemy_pid, map, enemy_map));
}

int wait_game(char const *file)
{
    char **map = read_map(file);
    char **enemy_map = map_allocation();
    int pid = getpid();
    int enemy_pid = 0;

    if (!map || !enemy_map || pid <= 0)
        return (84);
    my_printf("my_pid: %d\n", pid);
    my_printf("waiting for enemy connection...\n\n");
    enemy_pid = wait_bits(16);
    if (enemy_pid <= 0)
        return (84);
    my_printf("enemy connected\n\n");
    return (game_loop_server(pid, enemy_pid, map, enemy_map));
}
