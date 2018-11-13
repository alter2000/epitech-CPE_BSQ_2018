/*
** EPITECH PROJECT, 2018
** CPool_Day08_2018
** File description:
** strdup implementation
*/

#include "my.h"

char *my_strdup(char const *src)
{
    char *dest = malloc((my_strlen(src) + 1) * sizeof(char));

    while (!dest)
        dest = malloc((my_strlen(src) + 1) * sizeof(char));
    dest = my_strcpy(dest, src);
    return dest;
}
