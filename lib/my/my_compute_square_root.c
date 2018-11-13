/*
** EPITECH PROJECT, 2018
** CPool_Day05_2018
** File description:
** find square rööt
*/

#include "my.h"

int abs(int i)
{
    return (i < 0) ? -i : i;
}

int my_compute_square_root(int nb)
{
    int i = 0;
    for ( ; (i * i) != nb; i++) {
        if ((i * i) > abs(nb))
            return 0;
    }
    return (i < 0) ? 1 : i;
}
