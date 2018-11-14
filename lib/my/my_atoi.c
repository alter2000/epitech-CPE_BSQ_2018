/*
** EPITECH PROJECT, 2018
** CPool_evalexpr_2018
** File description:
** atoi implementation
*/

#include "my.h"

int my_atoi(char const **s)
{
    int nbr = 0;

    for (;**s >= '0' && **s <= '9'; (*s)++)
        nbr = nbr * 10 + (**s - '0');
    return nbr;
}

long long int my_atoll(char const **s)
{
    long long int nbr = 0;

    for (;**s >= '0' && **s <= '9'; (*s)++)
        nbr = nbr * 10 + (**s - '0');
    return nbr;
}
