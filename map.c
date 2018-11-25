/*
** EPITECH PROJECT, 2018
** CPE_BSQ_2018
** File description:
** map string to double array
*/

#include "include/my.h"
#include "include/bsq.h"
#include <unistd.h>

static unsigned int count_cols(char const *s)
{
    uint_t col = 0;

    while (s[col] != '\n')
        ++col;
    return col;
}

static unsigned int count_lines(char const *s)
{
    uint_t line = 0;

    while (*s)
        if (*s++ == '\n')
            ++line;
    if (line == 0)
        errb("invalid map");
    return line;
}

static map_t *mkmap(size_t const cols, size_t const lines)
{
    map_t *map = malloc(sizeof(map_t));

    if (cols == 0 || lines == 0) {
        errc((char *) map, "invalid map\n");
    }
    map->m = (char **) my_nul(malloc(sizeof(char *) * (lines + 2)), \
                        sizeof(char *) * (lines + 2));
    map->col = cols;
    map->row = lines;
    return map;
}

sq_t *mksq(uint_t const x, uint_t const y, uint_t const side)
{
    sq_t *square = malloc(sizeof(sq_t));

    square->x = x;
    square->y = y;
    square->side = side;
    return square;
}

map_t *str_to_map(char *s)
{
    uint_t i = 0;
    map_t *map = mkmap(count_cols(s), count_lines(s));

    for (uint_t j = 0, k = 0; i < map->row; j++, k = 0) {
        while (!map->m[i])
            map->m[i] = malloc(sizeof(char) * map->col + 2);
        while (s[j] != '\n')
            map->m[i][k++] = s[j++];
        map->m[i++][k] = 0;
    }
    free(s);
    map->m[i] = 0;
    return map;
}
