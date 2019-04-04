/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** Functions to print numbers in others bases
*/

#include "my_printf.h"

int hexa(va_list arg)
{
    unsigned int integer = va_arg(arg, unsigned int);
    char *str = decimal_to_base(integer, 16, 'a');
    int size = str_length(str);

    write(1, str, size);
    free(str);
    return (size);
}

int upcase_hexa(va_list arg)
{
    unsigned int integer = va_arg(arg, unsigned int);
    char *str = decimal_to_base(integer, 16, 'A');
    int size = str_length(str);

    write(1, str, size);
    free(str);
    return (size);
}

int octal(va_list arg)
{
    unsigned int integer = va_arg(arg, unsigned int);
    char *str = decimal_to_base(integer, 8, 'a');
    int size = str_length(str);

    write(1, str, size);
    free(str);
    return (size);
}

int binary(va_list arg)
{
    unsigned int integer = va_arg(arg, unsigned int);
    char *str = decimal_to_base(integer, 2, 'a');
    int size = str_length(str);

    write(1, str, size);
    free(str);
    return (size);
}

int pointer(va_list arg)
{
    unsigned long long ptr = (unsigned long long)va_arg(arg, void *);
    char *str = decimal_to_base(ptr, 16, 'a');
    int size = str_length(str);

    write(1, "0x", 2);
    write(1, str, size);
    free(str);
    return (size + 2);
}
