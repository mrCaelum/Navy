/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** Functions to print long variables
*/

#include "my_printf.h"

static int print_long_d(long int nb, int i)
{
    char tmp;

    if (nb < 0)
        return (0);
    if (nb < 10) {
        tmp = nb + '0';
        write(1, &tmp, 1);
        return (i + 1);
    } else {
        print_long_d(nb / 10, i + 1);
        tmp = nb % 10 + '0';
        write(1, &tmp, 1);
    }
    return (0);
}

static int print_long_long_d(long long int nb, int i)
{
    char tmp;

    if (nb < 0)
        return (0);
    if (nb < 10) {
        tmp = nb + '0';
        write(1, &tmp, 1);
        return (i + 1);
    } else {
        print_long_long_d(nb / 10, i + 1);
        tmp = nb % 10 + '0';
        write(1, &tmp, 1);
    }
    return (0);
}

int long_d(va_list arg)
{
    long int element = va_arg(arg, long int);
    int i = 0;

    i = print_long_d(element, i);
    return (i);
}

int long_long_d(va_list arg)
{
    long long int element = va_arg(arg, long long int);
    int i = 0;

    i = print_long_d(element, i);
    return (i);
}
