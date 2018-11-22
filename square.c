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
    if (sq->side < side) {
        sq->x = x;
        sq->y = y;
        sq->side = side;
    }
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

int issquare(map_t const *m, int row, int col, int side)
{
    if (row > m->row || col > m->col \
        || (row + side) > m->row || (col + side) > m->col)
        return 0;
    for (uint_t i = 0; i < side; ++i)
        if (binsearch(m->m[row + i], side, 'o'))
            return 0;
    return 1;
}

void check_square(map_t const *m, sq_t *sq, int x, int y)
{
    uint_t largest = 0;

    while (m->m[y][x + largest] && m->m[y][x + largest] != 'o' &&
            m->m[y][x + largest] != '\n')
        ++largest;
    while (largest > sq->side && !issquare(m, y, x, largest))
        --largest;
    if (largest > sq->side) {
        sq->side = largest;
        sq->y = y;
        sq->x = x;
    }
    return;
}

sq_t *find_sq(map_t const *m, sq_t *sq, int side)
{
    for (uint_t y = 0, x = 0; y < m->row; ++y, x = 0) {
        while (x < m->col && m->m[y][x] != '\n')
            check_square(m, sq, x++, y);
    }
    return sq;
}
