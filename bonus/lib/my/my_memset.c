/*
** EPITECH PROJECT, 2018
** muhlib
** File description:
** memset(3) clone
*/

#include "my.h"

void *my_memset(char *s, short ch, size_t n)
{
    if (!s)
        return 0;
    for (size_t i = 0; i < n; i++)
        s[i] = ch;
    return s;
}

void *my_nul(char *s, size_t n)
{
    return my_memset(s, 0, n);
}
