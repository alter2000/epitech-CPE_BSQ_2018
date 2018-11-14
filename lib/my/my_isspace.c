/*
** EPITECH PROJECT, 2018
** CPool_Day07_2018
** File description:
** check if char is whitespace
*/

#include "my.h"

int my_isspace(char const ch)
{
    if (ch == ' ' || ch == '\t' || ch == '\v'|| ch == '\r' || ch == '\n')
        return 0;
    return 1;
}
