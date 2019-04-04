/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** Send
*/

#include "navy.h"

int send_bits(int pid, unsigned int value, unsigned int bit_nb)
{
    unsigned int tmp = value;

    if (value >= power(2, bit_nb))
        return (1);
    for (unsigned int i = 0; i < bit_nb; i++) {
        tmp = value % 2;
        kill(pid, tmp ? SIGUSR1 : SIGUSR2);
        value = (value - tmp) / 2;
        usleep(10);
    }
    return (0);
}

unsigned int wait_bits(unsigned int bit_nb)
{
    unsigned int value = 0;
    char buffer[bit_nb];

    for (int i = 0; i < bit_nb; i++)
        buffer[i] = -1;
    TMP = -1;
    for (int i = 0; buffer[bit_nb - 1] < 0;) {
        if (TMP != -1) {
            buffer[i] = TMP;
            TMP = -1;
            i++;
        }
    }
    for (int i = 0; i < bit_nb; i++)
        if (buffer[i])
            value += power(2, i);
    return (value);
}
