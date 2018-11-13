/*
** EPITECH PROJECT, 2018
** CPool_Day06_2018
** File description:
** compare string values
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    while (*s2) {
        if (*s1 == *s2)
            return my_strcmp((s1 + 1), (s2 + 1));
        else
            return *s1 - *s2;
    }
    return 0;
}
