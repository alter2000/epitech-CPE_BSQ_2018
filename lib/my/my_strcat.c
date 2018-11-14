/*
** EPITECH PROJECT, 2018
** CPool_Day07_2018
** File description:
** concatenate two strings
*/

#include "my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int len = my_strlen(dest);

    for (;src[i]; i++)
        dest[i + len] = src[i];
    dest[i + len] = 0;
    return dest;
}
