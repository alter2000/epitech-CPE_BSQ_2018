/*
** EPITECH PROJECT, 2018
** CPool_Day07_2018
** File description:
** find if string is a digit
*/

#include "my.h"

int my_str_isnum(const char *str)
{
    for (int i = 0; str && str[i]; i++) {
        if (str[i] < '0' || str[i] > '9')
            return 0;
    }
    return 1;
}
