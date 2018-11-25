/*
** EPITECH PROJECT, 2018
** CPE_BSQ_2018
** File description:
** TODO: FILL THIS YO ------- not forgetti makefiletti
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "bsq.h"

sq_t *set_sq(sq_t *, int const, int const, int const);

Test(mksq, empty)
{
    cr_expect(mksq(0, 0, 0)->x == 0);
    cr_expect(mksq(1, 0, 0)->y == 0);
    cr_expect(mksq(1, 2, 0)->side == 0);
}

Test(mksq, not_empty)
{
    cr_expect(mksq(1, 0, 0)->x == 1);
    cr_expect(mksq(1, 2, 0)->y == 2);
    cr_expect(mksq(1, 2, 99)->side == 99);
}

Test(set_sq, bigger)
{
    sq_t *sq = set_sq(mksq(0, 0, 0), 3, 2, 12);

    cr_expect(sq->x == 2);
    cr_expect(sq->y == 3);
    cr_expect(sq->side == 12);
}

Test(set_sq, equal)
{
    sq_t *sq = set_sq(mksq(4, 9, 89), 4, 4, 4);

    cr_expect(sq->x == 4);
    cr_expect(sq->y == 9);
    cr_expect(sq->side == 89);
}

Test(set_sq, smaller)
{
    sq_t *sq = set_sq(mksq(4, 9, 89), 3, 4, 4);

    cr_expect(sq->x == 4);
    cr_expect(sq->y == 9);
    cr_expect(sq->side == 89);
}
