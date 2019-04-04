/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** Readr
*/

#include "navy.h"

void readr(char *str)
{
    unsigned char i = 0;
    char c = 0;

    while (i < 2) {
        c = getch();
        if (i == 0 && str_contains("ABCDEFGH", c)) {
            str[i++] = c;
            printw("%c", c);
        } else if (i == 1 && str_contains("0123456789", c)) {
            str[i++] = c;
            printw("%c", c);
        }
    }
    printw("\n");
}
