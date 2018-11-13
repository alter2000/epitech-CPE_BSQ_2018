/*
** EPITECH PROJECT, 2018
** CPool_Day06_2018
** File description:
** compare strings or n chars
*/

#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    while (*s1 && *s2 && n) {
        if (*s1 != *s2)
            return s1 - s2;
        else
            return my_strncmp((s1 + 1), (s2 + 1), n - 1);
    }
    return -1;
}
