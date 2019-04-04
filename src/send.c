/*
** EPITECH PROJECT, 2019
** PSU_navy_2018
** File description:
** Send
*/

#include "navy.h"

int power(int nb, int pow)
{
    int result = 1;

    if (!nb)
        return (0);
    if (nb == 1 || !pow)
        return (1);
    for (int i = 0; i < pow; i++)
        result *= nb;
    return (result);
}

void signal_add(int sig)
{
    TMP = sig == SIGUSR1;
}

int send_bit(int pid, unsigned int value)
{
    kill(pid, value ? SIGUSR1 : SIGUSR2);
    return (0);
}

unsigned int wait_bit(void)
{
    usleep(1000);
    TMP = -1;
    while (TMP < 0);
    return (TMP);
}
