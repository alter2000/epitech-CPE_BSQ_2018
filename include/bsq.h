/*
** EPITECH PROJECT, 2018
** CPool_Day07_2018
** File description:
** muh library
*/

#ifndef BSQ_H
# define BSQ_H

#include <sys/stat.h>
#include <fcntl.h>

typedef struct
{
    char **m;
    int col;
    int row;
} map_t;

typedef struct
{
    int x;
    int y;
    unsigned int side;
} sq_t;

void finish(char *, int);
int find_sq(map_t const *, int, int, sq_t *);
sq_t *set_sq(sq_t *, int const, int const, int const);

unsigned int count_cols(char const *);
unsigned int count_lines(char const *);
map_t *str_to_map(char const *);
sq_t *mksq(unsigned int const, unsigned int const, unsigned int const);
int binsearch(char const *, unsigned int const, char const);

#endif
