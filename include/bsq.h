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

void finish(char *, int);
void bsq(char **, unsigned int, unsigned int, unsigned int);
unsigned int count_cols(char const *);
unsigned int count_lines(char const *);
char **single_to_double(char const *);

#endif
