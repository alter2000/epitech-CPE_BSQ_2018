/*
** EPITECH PROJECT, 2018
** CPE_BSQ_2018
** File description:
** BSQ main file
*/

#include "include/my.h"
#include "include/bsq.h"

void finish(char *buf, int f)
{
    free(buf);
    close(f);
    exit(0);
}

sq_t *set_sq(sq_t *sq, int const x, int const y, int const side)
{
    if (!sq)
        errb("set_sq: no square struct.\n");
    sq->x = (x == -1) ? sq->x : x;
    sq->y = (y == -1) ? sq->y : y;
    sq->side = (sq->side < side) ? side : sq->side;
    return sq;
}

int find_sq(map_t const *m, int x, int y, sq_t *sq)
{
    if (m->m[x][y] == '\n' || x < 0 || y < 0 || x > m->col -1 || y > m->row -1)
        return 0;
    if (m->m[x][y] == 'o') {
        printf("o\tsquare\tx: %d;\ty: %d;\tlen: %d\n", sq->x, sq->y, sq->side);

        if (x == m->col - 1)
            return find_sq(m, 0, y + 1, sq);                  // wtf ®

        return find_sq(m, x + 1, y, sq);                      // wtf ®

    } else if (m->m[x][y] == '.') {
        printf(".\tsquare\tx: %d;\ty: %d;\tlen: %d\n", sq->x, sq->y, sq->side);

        if (x == 0)
            return find_sq(m, x + 1, y, set_sq(sq, x, y, 1));             // wtf ®

        if (x == m->col - 1)
            return find_sq(m, 0, y + 1, set_sq(sq, -1, -1, sq->side + 1));  // wtf ®

        return find_sq(m, x + 1, y, set_sq(sq, -1, -1, sq->side + 1));

    } else
        return 0;
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

int main(int argc, char const **argv)
{
    struct stat fi;
    if (argc != 2 || stat(argv[1], &fi))
        return 84;
    int n = 30;
    char *buf = malloc(n * sizeof(char));
    int f = open(argv[1], O_RDONLY);
    unsigned int row = (f < 0) ? errb("Error opening file\n") \
                            : getnbr_rec(getl(f, &buf, &n), 0);
    char *s = 0;

    while (!s)
        s = malloc(fi.st_size);
    s[fi.st_size] = 0;
    if (read(f, s, fi.st_size - my_count_digits(row) - 2) < 0)
        errb("Error reading file\n");
    map_t *m = str_to_map(s);
    sq_t *sq = mksq(0, 0, 0);
    find_sq(m, 0, 0, sq);
    printf("x: %2u\ty: %2u\tlen: %2u", sq->x, sq->y, sq->side);
    finish(buf, f);
}
