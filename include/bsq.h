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
#include <stddef.h>

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

sq_t *set_sq(sq_t *, int const, int const, int const);
int binsearch(char const *, unsigned int const, char const);
int issquare(map_t const *, int, int, int);
void check_square(map_t const *, sq_t *, int, int);
sq_t *find_sq(map_t const *, sq_t *, int);

map_t *mkmap(size_t const, size_t const);
map_t *str_to_map(char *);
sq_t *mksq(unsigned int const, unsigned int const, unsigned int const);

char ** const fill_sq(map_t const *, sq_t const *);
map_t *set_map(char const *);
void print_map(char const **);

#endif // BSQ_H
