/*
** EPITECH PROJECT, 2018
** CPool_Day07_2018
** File description:
** check if char is uppercase
*/

#include "my.h"

int my_isupper(char const ch)
{
    if (ch < 'A' || ch > 'Z') {
        return 0;
    }
    return 1;
}
