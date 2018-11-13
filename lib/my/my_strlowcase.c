/*
** EPITECH PROJECT, 2018
** CPool_Day07_2018
** File description:
** convert string to lowercase
*/

#include "my.h"

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] -= ('a' - 'A');
    }
    return str;
}
