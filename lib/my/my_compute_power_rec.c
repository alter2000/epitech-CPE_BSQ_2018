/*
** EPITECH PROJECT, 2018
** CPool_Day05_2018
** File description:
** find power by recursing
*/

#include "my.h"

int my_compute_power_rec(int nb, int p)
{
    if (p == 1)
        return nb;
    if (p == 0)
        return 1;
    if (nb < INT_MIN || nb > INT_MAX)
        return 0;
    return nb * my_compute_power_rec(nb, p - 1);
}
