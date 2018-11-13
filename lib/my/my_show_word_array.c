/*
** EPITECH PROJECT, 2018
** CPool_Day08_2018
** File description:
** print array of arrays separated by newlines
*/

#include "my.h"

int my_show_word_array(char const *tab[])
{
    int i = 0;

    for (; tab[i]; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
    return i;
}
