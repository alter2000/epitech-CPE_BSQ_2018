/*
** EPITECH PROJECT, 2018
** CPool_Day07_2018
** File description:
** find if char is letter
*/

#include "my.h"

int my_isalpha(char const ch)
{
    if (my_isupper(ch) || my_islower(ch))
        return 1;
    return 0;
}
