/*
** EPITECH PROJECT, 2018
** CPool_Day07_2018
** File description:
** concatenate two strings or n chars
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int n)
{
    int i = 0;
    char *len = dest + my_strlen(dest);

    for (;src[i] != '\0' && i < n; i++)
        len[i] = src[i];
    len[i] = '\0';
    return dest;
}
