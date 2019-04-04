/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** __DESCRIPTION__
*/

#ifndef MY_PRINTF_H_
    #define MY_PRINTF_H_

    #include <unistd.h>
    #include <stdlib.h>
    #include <stdarg.h>
    #include <sys/types.h>
    #include "str.h"

    typedef struct op {
        char *str;
        int (*ptr)(va_list arg);
    } op_t;

    int my_printf(char const *str, ...);

    int decimal(va_list arg);
    int long_d(va_list arg);
    int long_long_d(va_list arg);
    int unsigned_decimal(va_list arg);
    int long_u(va_list arg);
    int long_long_u(va_list arg);
    int character(va_list arg);
    int string(va_list arg);
    int string_with_hidden_char(va_list arg);
    int percent(va_list arg);
    int hexa(va_list arg);
    int upcase_hexa(va_list arg);
    int octal(va_list arg);
    int binary(va_list arg);
    int pointer(va_list arg);

    char *decimal_to_base(unsigned long long nb, unsigned long long const base,
    char c);
    char *long_to_base(unsigned long long nb, unsigned long long const base);

#endif
