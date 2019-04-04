/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** Functions to print characters
*/

#include "my_printf.h"

static int print_hidden(int nb, int i)
{
    char *str = decimal_to_base(nb, 8, 'a');
    int size = str_length(str);
    int zeros = 3 - size;

    i += zeros;
    write(1, "\\", 1);
    for (int z = 0; z < zeros; z++)
        write(1, "0", 1);
    write(1, str, size);
    return (i + size);
}

int character(va_list arg)
{
    char element = (char)va_arg(arg, int);

    write(1, &element, 1);
    return (1);
}

int string(va_list arg)
{
    char *str = va_arg(arg, char *);
    int size = str_length(str);

    write(1, str, size);
    return (size - 1);
}

int string_with_hidden_char(va_list arg)
{
    char *str = va_arg(arg, char *);
    int size = 0;

    for (int i = 0; str[i]; i++, size++) {
        if (str[i] < 32 || str[i] > 126) {
            size += print_hidden(str[i], 1);
        } else {
            write(1, &str[i], 1);
        }
    }
    return (size - 1);
}

int percent(va_list arg)
{
    write(1, "%", 1);
    return (1);
}
