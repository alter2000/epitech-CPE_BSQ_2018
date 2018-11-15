/*
** EPITECH PROJECT, 2018
** CPE_BSQ_2018
** File description:
** map string to double array
*/

#include "my.h"
#include "bsq.h"

unsigned int count_cols(char const *s)
{
    unsigned int col;

    for (col = 0; *s != '\n'; col++);
    return col;
}

unsigned int count_lines(char const *s)
{
    unsigned int line = 0;

    while (*s)
        line += (*s++ == '\n');
    return line;
}

char **single_to_double(char const *s)
{
    unsigned int ln = count_lines(s);
    unsigned int col = count_cols(s);
    unsigned int i = 0;
    char **map = malloc(sizeof(char *) * (ln + 2));

    for (unsigned int j = 0, k = 0; i < ln; i++, j++, k = 0) {
        map[i] = malloc(sizeof(char) * col);
        while (s[j] != '\n')
            map[i][k++] = s[j++];
        my_putchar('k');
    }
    map[i] = 0;
    return map;
}
