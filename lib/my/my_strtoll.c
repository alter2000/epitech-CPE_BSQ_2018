/*
** EPITECH PROJECT, 2018
** CPool_evalexpr_2018
** File description:
** strtoll implementation and probably strtol too
*/

#include "my.h"

long long int my_strtoll(char *s, char **end, long long int rec)
{
    if (rec < LLONG_MIN + 100)
        return LLONG_MIN;
    if (rec > LLONG_MAX - 100)
        return LLONG_MAX;
    if (*s && *(s + 1) && (*s == '-' && my_isdigit(*(s + 1)))) {
        end++;
        return -my_strtoll((s + 1), end, rec * 10);
    }
    if (*s && my_isdigit(*s)) {
        end++;
        return my_strtoll((s + 1), end, rec * 10  + (*s - '0'));
    }
    return rec;
}
