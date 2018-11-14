/*
** EPITECH PROJECT, 2018
** CPool_Day07_2018
** File description:
** print nonprintables as hex values
*/

#include "my.h"

void my_showstr(char const *str)
{
    for (unsigned int i = 0; str[i]; i++) {
        if (my_isprintable(str[i]))
            my_putchar(str[i]);
        else {
            my_putchar('\\');
            if (str[i] < 16)
                my_putchar('0');
            my_put_nbr_base(str[i], "0123456789abcdef");
        }
    }
}
