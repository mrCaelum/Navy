/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** Header file
*/

#ifndef NAVY_H_
    #define NAVY_H_

    #include "my_printf.h"
    #include <signal.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <ncurses.h>

    char **map_allocation(void);
    char **read_map(char const *);
    void print_map(char **);

    void readr(char *);

    int connect_game(int, char const *);
    int wait_game(char const *);

    int send_bit(int, unsigned int);
    unsigned int wait_bit(void);
    int send_bits(int, unsigned int, unsigned int);
    unsigned int wait_bits(unsigned int);

    int game_loop_client(int, int, char **, char **);
    int game_loop_server(int, int, char **, char **);

    int power(int, int);
    void signal_add(int);

    int on_win(char **, char **);
    int on_loose(char **, char **);

    int TMP;

#endif

#ifndef HELP
    #define HELP (H_USAGE H_DESC H_DESC1 H_DESC2)
    #define H_USAGE "USAGE\n\t./navy [first_player_pid] navy_positions\n"
    #define H_DESC "DESCRIPTION\n\tfirst_player_pid: only for the 2nd player. "
    #define H_DESC1 "pid of the first player.\n\tnavy_positions: "
    #define H_DESC2 "file representing the positions of the ships.\n"
#endif

#ifndef READ_SIZE
    #define READ_SIZE 64
#endif
