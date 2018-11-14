/*
** EPITECH PROJECT, 2018
** CPE_BSQ_2018
** File description:
** BSQ main file
*/

#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

char *getl(int fd, char **b)
{
    unsigned int works = 1;

    if (*b == 0)
        *b = my_bzero(malloc(20 * sizeof(char)), 20 * sizeof(char));
    for (unsigned long int i = 0; works > 0 && *b[i] != '\n'; i++)
        works = read(fd, *b, 1);
    return *b;
}

int main(int argc, char const **argv)
{
    FILE *f;
    char **map = 0;
    char *buf = 0;
    unsigned int rows = 0U;

    if (argc != 2)
        return 84;
    f = open(argv[1], O_RDONLY);
    if (f < 0)
        errb("Wrong file\n");
    map = malloc(getnbr_rec(getl(f, 0), 0) * sizeof(char));
    for (unsigned int i = 0; getl(f, &map[i]); i++);
}

