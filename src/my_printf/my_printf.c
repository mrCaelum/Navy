/*
** EPITECH PROJECT, 2018
** PSU_my_printf_2018
** File description:
** my_printf file
*/

#include "my_printf.h"

static const op_t ptr_tab[] = {
    {"d", &decimal},
    {"hd", &decimal},
    {"hhd", &decimal},
    {"ld", &long_d},
    {"lld", &long_long_d},
    {"qd", &long_long_d},
    {"i", &decimal},
    {"hi", &decimal},
    {"hhi", &decimal},
    {"li", &long_d},
    {"lli", &long_long_d},
    {"qi", &long_long_d},
    {"u", &unsigned_decimal},
    {"hu", &unsigned_decimal},
    {"hhu", &unsigned_decimal},
    {"lu", &long_u},
    {"llu", &long_long_u},
    {"qu", &long_long_u},
    {"c", &character},
    {"s", &string},
    {"S", &string_with_hidden_char},
    {"%", &percent},
    {"x", &hexa},
    {"x", &hexa},
    {"lx", &hexa},
    {"llx", &hexa},
    {"hx", &hexa},
    {"hhx", &hexa},
    {"X", &upcase_hexa},
    {"lX", &upcase_hexa},
    {"llX", &upcase_hexa},
    {"hX", &upcase_hexa},
    {"hhX", &upcase_hexa},
    {"o", &octal},
    {"b", &binary},
    {"p", &pointer},
    {NULL, NULL}
};

int call_function(char const *str, int i, int *total_printed, va_list arg)
{
    for (int j = 0; ptr_tab[j].str; j++) {
        if (str_startwith(str + i, ptr_tab[j].str)) {
            *total_printed += ptr_tab[j].ptr(arg);
            return (str_length(ptr_tab[j].str) - 1);
        }
    }
}

int my_printf(char const *str, ...)
{
    va_list arg;
    int total_printed = 0;

    va_start(arg, str);
    for (int i = 0; str[i]; i++, total_printed++) {
        if (str[i] == '%') {
            i++;
            i += call_function(str, i, &total_printed, arg);
        } else {
            write(1, &str[i], 1);
        }
    }
    return (total_printed - 1);
}
