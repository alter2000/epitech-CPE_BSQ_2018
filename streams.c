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
    uint_t r;

    if (fd < 0)
        errb("Error opening file\n");
    r = read(fd, &buf, 1);
    while (buf != '\n') {
        if (r == -1)
            errb("error reading\n");
        if (buf < '0' || buf > '9')
            errb("line contains non-digits\n");
        if (r == 0)
            errb("out of lines\n");
        r = read(fd, &buf, 1);
    }
    return fd;
}

static char *check_board(char *s)
{
    uint_t col = 0;
    uint_t i = 0;

    if (!s)
        errb("no text in map\n");
    while (s[i++] != '\n')
        ++col;
    for (uint_t tmp = 0, i = 0; s[i]; ++i) {
        ++tmp;
        if (s[i] != '.' && s[i] != 'o' && s[i] != '\n')
            errc(s, "invalid map\n");
        if (s[i] == '\n') {
            if (tmp - 1 != col)
                errc(s, "non-rectangular map\n");
            tmp = 0;
        }
    }
    if (col == 0 || s[i - 1] != '\n')
        errc(s, "invalid file\n");
    return s;
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

void print_map(char **map)
{
    my_show_word_array((char const **) map);
    for (uint_t i = 0; map[i]; ++i)
        free(map[i]);
    free(map);
}
