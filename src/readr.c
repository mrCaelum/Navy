/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** Readr
*/

#include "navy.h"

char *readr(void)
{
    char c = 0;
    char *str = NULL;

    while (c != '\n') {
        if (read(0, &c, 1) <= 0)
            return (NULL);
        if (c == '\n')
            return (str);
        str = str_addchar(str, c);
    }
    return (str);
}
