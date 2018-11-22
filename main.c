/*
** EPITECH PROJECT, 2018
** CPE_BSQ_2018
** File description:
** BSQ main file
*/

#include "include/my.h"
#include "include/bsq.h"

int main(int argc, char const **argv)
{
    if (argc != 2)
        errb("Wrong number of arguments.\n");
    map_t *m = set_map(argv[1]);
    sq_t *sq = mksq(0, 0, 0);
    print_map((char const **) fill_sq(m, find_sq(m, sq, 1)));
    printf("END___SQUARE\tx: %2u\ty: %2u\tlen: %2u", sq->x, sq->y, sq->side);
    return 0;
}
