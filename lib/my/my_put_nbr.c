/*
** EPITECH PROJECT, 2018
** CPool_Day03_2018
** File description:
** print number on stdout
*/

#include "my.h"

int my_put_nbr(int nb)
{
    if (nb < INT_MIN || nb > INT_MAX) {
        write(2, "put_nbr: out of bounds", 25);
        return 0;
    }
    if (nb < 0) {
        my_putchar('-');
        my_put_nbr(-nb);
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
        my_put_nbr(nb % 10);
    }
    if (nb >= 0)
        my_putchar('0' + nb);
    return 0;
}
