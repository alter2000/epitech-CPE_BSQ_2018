/*
** EPITECH PROJECT, 2018
** CPool_Day07_2018
** File description:
** get number from string
*/

#include "my.h"

long long int getnbr_rec(char const *ch, long long int i)
{
    if (i < LLONG_MIN + 10)
        return LLONG_MIN;
    if (i > LLONG_MAX - 10)
        return LLONG_MAX;
    if (*ch && *(ch + 1) \
        && (*ch == '-' && my_isdigit(*(ch + 1))))
        return -getnbr_rec((ch + 1), i * 10);
    if (*ch && my_isdigit(*ch))
        return getnbr_rec((ch + 1), i * 10  + (*ch - '0'));
    return i;
}

long long int my_getnbr(char const *str)
{
    if (!str)
        return 0;
    return getnbr_rec(str, 0LL);
}
