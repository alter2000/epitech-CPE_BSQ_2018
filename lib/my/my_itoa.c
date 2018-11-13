/*
** EPITECH PROJECT, 2018
** CPool_evalexpr_2018
** File description:
** itoa implementation in base 10
*/

#include "my.h"

char *my_itoa(int nb)
{
    short sign = (nb < 0);
    char *str = malloc(my_count_digits(nb) + sign + 1);
    short left = 0;
    unsigned int i = 0;
    nb = (nb < 0) ? -nb : nb;

    while (!str)
        str = malloc(my_count_digits(nb) + sign + 1);
    do {
        left = nb % 10;
        nb /= 10;
        str[i++] = left + '0';
    } while (nb > 0);
    if (sign)
        str[i++] = '-';
    str[i] = '\0';
    return my_revstr(str);
}
