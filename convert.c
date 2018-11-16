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
    unsigned int col = 0;

    while (s[col] != '\n')
        col++;
    return col;
}

unsigned int count_lines(char const *s)
{
    unsigned int line = 0;

    while (*s)
        line += (*s++ == '\n');
    return line;
}

map_t *mkmap(size_t const cols, size_t const lines)
{
    map_t *map = malloc(sizeof(map_t));
    map->m = my_bzero(malloc(sizeof(char *) * (lines + 2)), \
                        sizeof(char *) * (lines + 2));
    map->cols = cols;
    map->rows = lines;

    return map;
}

map_t *str_to_map(char const *s)
{
    unsigned int i = 0;
    map_t *map = mkmap(count_cols(s), count_lines(s));

    for (unsigned int j = 0, k = 0; i < map->rows; j++, k = 0) {
        map->m[i] = malloc(sizeof(char) * map->cols + 2);
        while (s[j] != '\n')
            map->m[i][k++] = s[j++];
        map->m[i++][k] = 0;
    }
    map->m[i] = 0;
    return map;
}

sq_t *mksq(unsigned int const x, unsigned int const y, unsigned int const side)
{
    sq_t *square = malloc(sizeof(sq_t));

    square->x = x;
    square->y = y;
    square->side = side;
    return square;
}
