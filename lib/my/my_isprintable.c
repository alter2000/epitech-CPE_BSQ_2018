/*
** EPITECH PROJECT, 2018
** CPool_Day07_2018
** File description:
** check if string contains only printable chars
*/

#include "my.h"

int my_isprintable(char const ch)
{
    if (ch < 32 || ch > 126)
        return 0;
    return 1;
}
