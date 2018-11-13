/*
** EPITECH PROJECT, 2018
** CPool_rush2_2018
** File description:
** count digits of number
*/

#include "my.h"

static int my_count_digits_rec(int n, int i)
{
    if (n < INT_MIN || n > INT_MAX) {
        write(2, "count_digits: number out of bounds\n", 35);
        return 84;
    }
    if (n / 10 != 0)
        return i + my_count_digits_rec(n / 10, i);
    else if (n >= 0)
        return 1;
    else
        return 0;
}

int my_count_digits(int n)
{
    return my_count_digits_rec((n >= 0) ? n : -n, 0);
}
