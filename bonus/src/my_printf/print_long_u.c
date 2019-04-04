/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** Functions to print long unsigned numbers
*/

#include "my_printf.h"

static unsigned long print_long_u(unsigned long nb, int i)
{
    char tmp;

    if (nb < 0)
        return (0);
    if (nb < 10) {
        tmp = nb + '0';
        write(1, &tmp, 1);
        return (i + 1);
    } else {
        print_long_u(nb / 10, i + 1);
        tmp = nb % 10 + '0';
        write(1, &tmp, 1);
    }
    return (0);
}

static unsigned long long print_long_long_u(unsigned long long nb, int i)
{
    char tmp;

    if (nb < 0)
        return (0);
    if (nb < 10) {
        tmp = nb + '0';
        write(1, &tmp, 1);
        return (i + 1);
    } else {
        print_long_long_u(nb / 10, i + 1);
        tmp = nb % 10 + '0';
        write(1, &tmp, 1);
    }
    return (0);
}

int long_u(va_list arg)
{
    unsigned long element = va_arg(arg, unsigned long);
    int i = 0;

    i = print_long_u(element, i);
    return (i);
}

int long_long_u(va_list arg)
{
    unsigned long element = va_arg(arg, unsigned long long);
    int i = 0;

    i = print_long_long_u(element, i);
    return (i);
}
