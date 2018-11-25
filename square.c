/*
** EPITECH PROJECT, 2018
** CPE_BSQ_2018
** File description:
** square checking operations
*/

#include "include/bsq.h"
#include "include/my.h"

int issquare(map_t const *m, int row, int col, int side)
{
    if (row < 0 || col < 0 \
        || (row + side) > m->row || (col + side) > m->col)
        return 0;
    for (uint_t i = 0; i < side; ++i)
        for (uint_t j = 0; j < side; ++j)
            if (m->m[row + i][col + j] == 'o')
                return 0;
    return 1;
}

sq_t *set_sq(sq_t *sq, int const y, int const x, int const side)
{
    if (!sq)
        err("set_sq: no square struct\n");
    if (sq->side < side) {
        sq->x = x;
        sq->y = y;
        sq->side = side;
    }
    return sq;
}

void check_sq(map_t const *m, sq_t *sq, int const y, int const x)
{
    int side = 0;

    if (!m || !m->m[0] || !sq)
        errb("check_sq: no square struct, no map struct or no map array\n");
    for (; m->m[y][x + side] == '.'; ++side);
    for (; !issquare(m, y, x, side); --side);
    set_sq(sq, y, x, side);
}

sq_t *find_sq(map_t const *m, sq_t *sq, int const side)
{
    if (!m || !m->m || !m->m[0])
        errb("find_sq: no map\n");
    for (uint_t y = 0, x = 0; y < m->row; ++y, x = 0)
        for (; x < m->col && m->m[y] && m->m[y][x] \
                && m->m[y][x] != '\n'; ++x)
            check_sq(m, sq, y, x);
    return sq;
}

char ** const fill_sq(map_t const * m, sq_t *sq)
{
    for (uint_t y = sq->y; y < sq->y + sq->side; ++y)
        for (uint_t x = sq->x; x < sq->x + sq->side; ++x)
            m->m[y][x] = 'x';
    free(sq);
    return m->m;
}
