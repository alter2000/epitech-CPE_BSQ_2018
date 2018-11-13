/*
** EPITECH PROJECT, 2018
** CPool_Day08_2018
** File description:
** check if char is digit
*/

#include "my.h"

int my_isdigit(char const ch)
{
    if (ch < '0' || ch > '9') {
        return 0;
    }
    return 1;
}
