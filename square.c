/*
** EPITECH PROJECT, 2018
** CPE_BSQ_2018
** File description:
** square checking operations
*/

#include "include/bsq.h"
#include "include/my.h"

sq_t *set_sq(sq_t *sq, int const x, int const y, int const side)
{
    if (!sq)
        errb("set_sq: no square struct.\n");
    sq->x = (x == -1) ? sq->x : x;
    sq->y = (y == -1) ? sq->y : y;
    sq->side = (sq->side < side) ? side : sq->side;
    return sq;
}

int binsearch(char const *range, unsigned int const len, char const query)
{
    if (!range || !*range || *range == '\n')
        return 0;
    if (*range == query)
        return 1;
    if (len > 0)
        return (*range == query) + binsearch(range, len / 2, query)
            + binsearch(range + len / 2, len / 2, query);
    else
        return 0;
}

int square(map_t const *map, sq_t *sq, int side)
{
    for (uint_t i = 0; i < side; i++) {
        if (map->m[sq->x + i][sq->y + i] == 'o' \
            || map->m[sq->x][sq->y + i] == 'o' \
            || map->m[sq->x + i][sq->y] == 'o')
            return 0;
    }
    return 1;
}

int find_sq(map_t const *m, sq_t *sq, int size)
{
    if (square(m, sq, size))
        find_sq(m, sq, size + 1);
    return 0;
}
