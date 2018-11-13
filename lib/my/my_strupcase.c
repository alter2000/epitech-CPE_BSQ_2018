/*
** EPITECH PROJECT, 2018
** CPool_Day07_2018
** File description:
** convert string to uppercase
*/

#include "my.h"

char *my_strupcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] += ('a' - 'A');
    }
    return str;
}
