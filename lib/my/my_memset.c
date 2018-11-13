/*
** EPITECH PROJECT, 2018
** CPool_infinadd_2018
** File description:
** memset(3) clone
*/

#include "my.h"

void *my_memset(char *s, short ch, size_t n)
{
    if (!s)
        return 0;
    for (unsigned long long int i = 0; i < n; i++)
        s[i] = ch;
    return s;
}
