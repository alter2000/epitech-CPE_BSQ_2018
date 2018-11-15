/*
** EPITECH PROJECT, 2018
** CPE_BSQ_2018
** File description:
** BSQ main file
*/

#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

int main(int argc, char const **argv)
{
    int f;
    int n = 30;
    char **map = 0;
    char *buf = malloc(30 * sizeof(char));
    unsigned int rows = 0U;

    if (argc != 2)
        return 84;
    f =  open(argv[1], O_RDONLY);
    if (f < 0)
        errb("Wrong file\n");
    rows = getnbr_rec(getl(f, &buf, &n), 0);
    map = malloc(rows * sizeof(char));
    while ()
    /* for (unsigned int i = 0; getl(f, &map[i], &n); i++); */

    for (; rows > 0; rows--)
        free(map[rows]);
    free(buf);
    close(f);
}
