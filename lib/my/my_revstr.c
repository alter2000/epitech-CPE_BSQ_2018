/*
** EPITECH PROJECT, 2018
** CPool_Day06_2018
** File description:
** reverse() implementation
*/

#include "my.h"

char *my_revstr(char *str)
{
    int a = 0;
    int b = my_strlen(str) - 1;
    int c;

    if (!str)
        return 0;
    while (a < b) {
        c = str[a];
        str[a++] = str[b];
        str[b--] = c;
    }
    return str;
}
