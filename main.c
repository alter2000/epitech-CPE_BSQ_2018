/*
** EPITECH PROJECT, 2018
** CPE_BSQ_2018
** File description:
** BSQ main file
*/

#include "my.h"
#include "bsq.h"

void finish(char *buf, int f)
{
    free(buf);
    close(f);
    exit(0);
}

void bsq(char **map, unsigned int row, unsigned int col, unsigned int cur)
{
    /* if (*map == 'o') */
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
    unsigned int col;
    char *map = 0;

    while (!map)
        map = my_bzero(malloc(fi->st_size), fi->st_size);
    if (read(f, map, fi->st_size - my_count_digits(row) - 2) < 0)
        errb("Error reading file\n");
    for (col = 0; map[col] != '\n'; col++);
    bsq(single_to_double(map), row, col, 0);
    finish(buf, f);
}
