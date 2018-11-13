/*
** EPITECH PROJECT, 2018
** CPool_Day08_2018
** File description:
** check if string contains whitespace
*/

#include "my.h"

int my_str_isspace(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\f' \
            || str[i] == '\r' || str[i] == '\n' || str[i] == '\v')
                return str[i];
    }
    return 1;
}
