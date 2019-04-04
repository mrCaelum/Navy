/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** Map
*/

#include "navy.h"

char **map_allocation(void)
{
    char **map = malloc(9 * sizeof(char *));
    char *str = malloc(73 * sizeof(char));

    if (!map || !str)
        return (NULL);
    for (int i = 0; i < 72; i++)
        str[i] = (!i || i % 9) ? '.' : 0;
    str[72] = 0;
    for (int i = 0; i < 8; i++)
        map[i] = str + i * 9 + 1;
    map[8] = NULL;
    return (map);
}

static unsigned char set_ship(char **map, char **ship)
{
    int id = ship[1][0] == ship[2][0];
    int x = ship[1][0] - 'A';
    int y = ship[1][1] - '1';
    int *i = id ? &y : &x;

    if (ship[2][id] - (id ? '1' - 1 : 'A' - 1) - *i != ship[0][0] - 48)
        return (1);
    for (; *i < ship[2][id] - (id ? '1' - 1 : 'A' - 1); (*i)++)
        map[y][x] = ship[0][0];
    return (0);
}

static char **map_engine(char **map, char **params)
{
    char **ship;

    for (int i = 0; params[i]; i++) {
        ship = str_to_tab(params[i], ':');
        if (tab_length(ship) > 3 || tab_length(ship) <= 0
        || str_length(ship[0]) != 1 || ship[0][0] != (i + '2')
        || str_length(ship[1]) != 2 || str_length(ship[2]) != 2
        || (ship[1][0] == ship[2][0] && ship[1][1] == ship[2][1])
        || (ship[1][0] != ship[2][0] && ship[1][1] != ship[2][1])
        || !str_contains("ABCDEFGH", ship[1][0])
        || !str_contains("12345678", ship[1][1])
        || !str_contains("ABCDEFGH", ship[2][0])
        || !str_contains("12345678", ship[2][1])
        || set_ship(map, ship))
            return (NULL);
        free(ship);
    }
    free(*params);
    free(params);
    return (map);
}

char **read_map(char const *filename)
{
    char *params = NULL;
    char buffer[READ_SIZE];
    int size = READ_SIZE;
    int fd = open(filename, O_RDONLY);

    if (fd <= 0)
        return (NULL);
    while (size == READ_SIZE) {
        size = read(fd, buffer, READ_SIZE);
        for (int i = 0; i < size; i++)
            params = str_addchar(params, buffer[i]);
    }
    close(fd);
    return (map_engine(map_allocation(), str_to_tab(params, '\n')));
}

void print_map(char **map)
{
    my_printf(" |A B C D E F G H\n-+---------------\n");
    for (int y = 0; y < 8; y++) {
        my_printf("%d|", y + 1);
        for (int x = 0; x < 8; x++)
            my_printf(x ? " %c" : "%c", map[y][x]);
        write(1, "\n", 1);
    }
    write(1, "\n", 1);
}
