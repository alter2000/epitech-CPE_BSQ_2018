/*
** EPITECH PROJECT, 2018
** CPool_infinadd_2018
** File description:
** memset(3) clone for zero inits
*/

#include "my.h"

void *my_bzero(char *s, size_t n)
{
    if (!s)
        return 0;
    for (unsigned long long int i = 0; i < n; i++)
        s[i] = 0;
    return s;
}
