/*
** EPITECH PROJECT, 2018
** CPool_Day07_2018
** File description:
** check if str is uppercase
*/

#include "my.h"

int my_str_isupper(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 'A' || str[i] > 'Z')
            return 0;
    }
        return 1;
}
