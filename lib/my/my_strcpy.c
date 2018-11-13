/*
** EPITECH PROJECT, 2018
** CPool_Day06_2018
** File description:
** copy string into given string
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    if (!src)
        return 0;
    for (; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}
