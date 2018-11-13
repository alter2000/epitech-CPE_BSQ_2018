/*
** EPITECH PROJECT, 2018
** CPool_Day07_2018
** File description:
** find if string contains only alphanumerics
*/

#include "my.h"

int my_str_isalpha(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (my_isupper(str[i]) || my_islower(str[i]))
            return 1;
    }
    return 0;
}
