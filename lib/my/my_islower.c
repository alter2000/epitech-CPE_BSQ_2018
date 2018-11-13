/*
** EPITECH PROJECT, 2018
** CPool_Day07_2018
** File description:
** check if char is lowercase
*/

#include "my.h"

int my_islower(char const ch)
{
    if (ch < 'a' || ch > 'z') {
        return 0;
    }
    return 1;
}
