/*
** EPITECH PROJECT, 2018
** CPE_BSQ_2018
** File description:
** map.c unit tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <string.h>
#include "my.h"
#include "bsq.h"

uint_t count_cols(char *);
uint_t count_lines(char *);

static void redirect(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(count_cols, empty)
{
    char *s2 = my_strdup("12345\n\n");
    char *s3 = my_strdup("1234\n12\n12341234");

    cr_expect(count_cols(s2) == 5);
    cr_expect(count_cols(s3) == 4);
}

Test(count_cols, zero, .init = redirect, .exit_code = 84)
{
    cr_expect(count_cols(my_strdup("\n\n\n\n\n\n\n\n\n\n")) == 0);
    fflush(stdout);
    cr_expect_stdout_eq_str("invalid map\n");
}

Test(count_lines, empty)
{
    cr_expect(count_lines(my_strdup("12345\n\n")) == 2);
    cr_expect(count_lines(my_strdup("1234\n12\n1234\n\n1234")) == 4);
    cr_expect(count_lines(my_strdup("\n\n\n\n\n\n\n\n\n\n")) == 10);
    cr_expect(count_lines(my_strdup("asdfalskdfjhasldkfjhasldkfjasd")) == 0);
}

Test(mksq, zero)
{
    cr_expect(mksq(0, 0, 0)->x == 0);
    cr_expect(mksq(0, 1, 1)->x == 0);
    cr_expect(mksq(1, 1, 0)->side == 0);
    cr_expect(mksq(1, 0, 1)->y == 0);
    cr_expect(mksq(1, 0, 1)->y == 0);
    cr_expect(mksq(0, 1, 0)->side == 0);
}

Test(mksq, nonzero)
{
    cr_expect(mksq(1, 0, 0)->x == 1);
    cr_expect(mksq(1, 1, 1)->x == 1);
    cr_expect(mksq(1, 1, 1)->side == 1);
    cr_expect(mksq(0, 1, 0)->y == 1);
    cr_expect(mksq(1, 1, 1)->y == 1);
    cr_expect(mksq(0, 0, 1)->side == 1);
}

Test(str_to_map, basic)
{
    char *s = my_strdup("asdfasdfasdfasdf\nasdfasdfasfd\nbsdf\nasdf\nlkjh\n");
    map_t *map = str_to_map(s);

    cr_expect(map->col == 16);
    cr_expect(map->row == 5);
    cr_expect_str_eq(map->m[0], "asdfasdfasdfasdf");
    cr_expect_str_eq(map->m[1], "asdfasdfasfd");
    cr_expect_str_eq(map->m[2], "bsdf");
}
