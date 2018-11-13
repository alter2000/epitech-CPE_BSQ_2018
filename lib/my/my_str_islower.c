/*
** EPITECH PROJECT, 2018
** CPool_Day07_2018
** File description:
** check if str is lowercase
*/

#include "my.h"

int my_str_islower(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 'a' || str[i] > 'z')
            return 0;
    }
    return 1;
}
