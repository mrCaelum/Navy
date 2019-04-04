/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** Functions to print integer
*/

#include "my_printf.h"

static int print_integer(int nb, int i)
{
    char tmp;

    if (nb < 0)
        return (0);
    if (nb < 10) {
        tmp = nb + '0';
        write(1, &tmp, 1);
        return (i + 1);
    } else {
        print_integer(nb / 10, i + 1);
        tmp = nb % 10 + '0';
        write(1, &tmp, 1);
    }
    return (0);
}

static unsigned int print_unsigned_integer(unsigned int nb, int i)
{
    char tmp;

    if (nb < 0)
        return (0);
    if (nb < 10) {
        tmp = nb + '0';
        write(1, &tmp, 1);
        return (i + 1);
    } else {
        print_integer(nb / 10, i + 1);
        tmp = nb % 10 + '0';
        write(1, &tmp, 1);
    }
    return (0);
}

int decimal(va_list arg)
{
    int element = va_arg(arg, int);
    int i = 0;

    i = print_integer(element, i);
    return (i);
}

int unsigned_decimal(va_list arg)
{
    unsigned int element = va_arg(arg, unsigned int);
    int i = 0;

    i = print_integer(element, i);
    return (i);
}
