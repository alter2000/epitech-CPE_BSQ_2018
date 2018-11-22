/*
** EPITECH PROJECT, 2018
** CPE_BSQ_2018
** File description:
** writing and reading functions
*/

#include "bsq.h"
#include "my.h"

static int skip_line(int fd)
{
    char buf = 0;

    if (fd < 0)
        errb("Error opening file\n");
    while (buf != '\n')
        read(fd, &buf, 1);
    return fd;
}

static char *check_board(char *s)
{
    unsigned int i = 0;

    while (s[i] != '\n')
        ++i;
    for (; s[i]; ++i)
        if (s[i] != '.' && s[i] != 'o' && s[i] != '\n')
            errc(s, s);
    if (s[i - 1] && s[i - 1] != '\n')
        errc(s, s);
    return s;
}

char ** const fill_sq(map_t const * m, sq_t const *sq)
{
    for (uint_t y = sq->y; y < sq->y + sq->side; ++y)
        for (uint_t x = sq->x; x < sq->x + sq->side; ++x)
            m->m[y][x] = 'x';
    return m->m;
}

map_t *set_map(char const *path)
{
    struct stat fi;
    int f = skip_line(open(path, O_RDONLY));
    int r = 0;
    char *s = 0;

    stat(path, &fi);
    while (!s)
        s = malloc(fi.st_size);
    s[fi.st_size] = 0;
    r = read(f, s, fi.st_size);
    if (r > 0)
        r += read(f, s + r, fi.st_size - r);
    if (r < 0)
        errb("Error reading file\n");
    close(f);
    return str_to_map(check_board(s));
}

void print_map(char const **map)
{
    my_show_word_array((char const **) map);
}
