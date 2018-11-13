/*
** EPITECH PROJECT, 2018
** CPool_Day06_2018
** File description:
** find string in string
*/

#include "my.h"

char *my_strstr(char *str, const char *to_find)
{
    if (!*str)
        return 0;
    if (!*to_find)
        return str;
    if ((*str == *to_find) && (!my_strcmp(str, to_find)))
        return str;
    return my_strstr(str + 1, to_find);
}
