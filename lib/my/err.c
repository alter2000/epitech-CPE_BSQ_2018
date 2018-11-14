/*
** EPITECH PROJECT, 2018
** CPool_Day12_2018
** File description:
** short error function that always returns 84
*/

#include "my.h"

void errb(char const *errstr)
{
    if (!errstr || !*errstr) {
        write(2, "no error string\n", 16);
        return;
    }
    write(2, errstr, my_strlen(errstr));
    _exit(84);
}

void err(char const *errstr)
{
    if (!errstr || !*errstr)
        write(2, "no error string\n", 16);
    else
        write(2, errstr, my_strlen(errstr));
}
