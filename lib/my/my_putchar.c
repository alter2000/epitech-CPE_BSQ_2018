/*
** EPITECH PROJECT, 2018
** CPool_Day07_2018
** File description:
** putchar weird clone
*/

#include "my.h"

int my_putchar(int const c)
{
    if (!c)
        return 0;
    write(1, &c, 1);
    return c;
}
