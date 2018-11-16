/*
** EPITECH PROJECT, 2018
** CPE_BSQ_2018
** File description:
** BSQ main file
*/

#include "my.h"
#include "bsq.h"

/* (m->m[x][y] == '.') */

void finish(char *buf, int f)
{
    free(buf);
    close(f);
    exit(0);
}

int find_sq(map_t const *m, int const x, int const y, \
        sq_t *sq)
{
    if (x < 0 || y < 0 || x >= m->cols || y >= m->rows)
        return 0;
    if (m->m[x][y] == 'o')
        return 0;
    if (m->m[x][y] == '.' && sq->x) {
        sq->x = x;
        sq->y = y;
        return find_sq(m, x + 1, y, sq) \
            + find_sq(m, x, y + 1, sq);
    }
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
    int n = 30;
    char *buf = malloc(n * sizeof(char));
    struct stat *fi = malloc(sizeof(struct stat));
    if (argc != 2 || stat(argv[1], fi))
        return 84;
    int f = open(argv[1], O_RDONLY);
    unsigned int row = (f < 0) ? errb("Error opening file\n") \
                            : getnbr_rec(getl(f, &buf, &n), 0);
    char *s = 0;

    while (!s)
        s = malloc(fi->st_size);
    s[fi->st_size] = 0;
    if (read(f, s, fi->st_size - my_count_digits(row) - 2) < 0)
        errb("Error reading file\n");
    find_sq(str_to_map(s), 0, 0, mksq(0, 0, 0));
    finish(buf, f);
}
