/*
** EPITECH PROJECT, 2018
** CPool_Day03_2018
** File description:
** print number on stdout
*/

#include "my.h"

int my_put_nbr_base(int nb, char const *base)
{
    int b = my_strlen(base);

    if (nb < INT_MIN + b + 1 || nb > INT_MAX - b - 1) {
        write(2, "put_nbr: out of bounds\n", 23);
        return 0;
    }
    if (nb < 0) {
        my_putchar('-');
        my_put_nbr_base(-nb, base);
    }
    if (nb > b - 1) {
        my_put_nbr_base(nb / b, base);
        my_put_nbr_base(nb % b, base);
    }
    if (nb >= 0 && nb < b)
        my_putchar(base[nb]);
    return nb;
}

int my_put_nbr(int nb)
{
    return my_put_nbr_base(nb, "0123456789");
}
