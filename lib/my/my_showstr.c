/*
** EPITECH PROJECT, 2018
** CPool_Day07_2018
** File description:
** print nonprintables as hex values
*/

#include "my.h"

void my_showstr(char const *str)
{
    char *base = "0123456789abcdef";
    char test[2];
    test[1] = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        test[0] = str[i];
        if (my_str_isprintable(test))
            my_putchar(str[i]);
        else {
            my_putchar('\\');
            if (str[i] < 16)
                my_putchar('0');
            my_put_nbr_base(str[i], base);
        }
    }
}

int my_put_nbr_base(int n, char const *base)
{
    int i = 0;
    int leftovers = 0;

    while (base[i] != '\0')
        i++;
    if (i <= 1)
        return n;
    leftovers %= i;
    if (leftovers < 0)
        leftovers = -leftovers;
    if (n / i == 0) {
        if (n < 0)
            my_putchar('-');
        my_putchar(base[leftovers]);
        return n;
    }
    my_put_nbr_base(n / i, base);
    my_putchar(base[leftovers]);
    return n;
}
