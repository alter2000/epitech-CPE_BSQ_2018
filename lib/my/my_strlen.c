/*
** EPITECH PROJECT, 2018
** CPool_Day04_2018
** File description:
** find string length
*/

#include "my.h"

unsigned long long int my_strlen(char const *str)
{
    unsigned long long int i = 0;
    while (str && str[i])
        i++;
    return i;
}
