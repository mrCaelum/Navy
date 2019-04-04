/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** Functions to convert a base to an other
*/

#include "my_printf.h"

static unsigned long long base_size_compute(unsigned long long nb,
unsigned long long const base)
{
    unsigned long long result = 0;

    for (; nb > 1; result++) {
        if (!(nb - nb % base))
            break;
        nb = (nb - nb % base) / base;
    }
    return (result + 1);
}

char *decimal_to_base(unsigned long long nb, unsigned long long const base,
char c)
{
    unsigned long long size = base_size_compute(nb, base);
    char *result = malloc(sizeof(char) * size);
    unsigned long long tmp = nb;
    unsigned long long i = 0;

    result = malloc(sizeof(char) * size);
    for (; i < size; i++) {
        tmp = nb % base;
        result[i] = tmp + (tmp > 9 ? c - 10 : 48);
        nb = (nb - tmp) / base;
    }
    result[i] = 0;
    str_reverse(result);
    return (result);
}
