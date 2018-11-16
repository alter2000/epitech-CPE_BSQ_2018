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
    unsigned int cols;
    unsigned int rows;
} map_t;

typedef struct
{
    unsigned int x;
    unsigned int y;
    unsigned int side;
} sq_t;

void finish(char *, int);
int find_sq(map_t const *, int const, int const, sq_t *);

unsigned int count_cols(char const *);
unsigned int count_lines(char const *);
map_t *str_to_map(char const *);
sq_t *mksq(unsigned int const, unsigned int const, unsigned int const);
int binsearch(char const *, unsigned int const, char const);

#endif
