/*
** EPITECH PROJECT, 2018
** CPool_Day07_2018
** File description:
** Title Case All Words
*/

#include "my.h"

char *my_strcapitalize(char *str)
{
    int len = my_strlen(str);

    for (int i = 0; i < len; i++) {
        if (my_isalpha(str[i]) && (my_isspace(str[i - 1]) || i == 0))
            str[i] -= 32;
    }
    return str;
}
