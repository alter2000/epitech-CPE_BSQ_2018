/*
** EPITECH PROJECT, 2018
** CPE_BSQ_2018
** File description:
** BSQ main file
*/

#include "include/my.h"
#include "include/bsq.h"

map_t *set_map(char const *path)
{
    struct stat fi;
    int n = 30;
    char *buf = malloc(n * sizeof(char));
    int f = open(path, O_RDONLY);
    unsigned int r = (f < 0) ? errb("Error opening file.\n") \
                            : getnbr_rec(getl(f, &buf, &n), 0);
    char *s = 0;

    stat(path, &fi);
    while (!s)
        s = malloc(fi.st_size);
    s[fi.st_size] = 0;
    r = read(f, s, fi.st_size);
    while (r > 0)
        r += read(f, s + r, fi.st_size - r);
    errb("Error reading file\n");
    close(f);
    free(buf);
    return str_to_map(s);
}

int main(int argc, char const **argv)
{
    if (argc != 2)
        errb("Wrong number of arguments.\n");
    map_t *m = set_map(argv[1]);
    sq_t *sq = mksq(0, 0, 0);
    find_sq(m, sq, 1);
    printf("x: %2u\ty: %2u\tlen: %2u", sq->x, sq->y, sq->side);
    return 0;
}
