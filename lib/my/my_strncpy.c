/*
** EPITECH PROJECT, 2018
** CPool_Day06_2018
** File description:
** copy n chars
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    if (!src || n < 1)
        return 0;

    for (; src[i] != '\0' && i < n; i++)
        dest[i] = src[i];
    if (i > n)
        dest[i] = '\0';
    return dest;
}
